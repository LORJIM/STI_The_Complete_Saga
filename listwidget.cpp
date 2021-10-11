#include "listwidget.h"
#include "ui_listwidget.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QJsonObject>
#include "gallery.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>

listWidget::listWidget(QWidget *parent, QString entrega, QString arco, int galeria) :
    QWidget(parent),
    ui(new Ui::listWidget),
    tipoGaleria(galeria)
{
    ui->setupUi(this);

    if(galeria!=0) this->galeria=QJsonArray(); //galeria multimedia resetea array

    //aqui ejecutamos la query con la entrega y arco para cargar las conias
    QString queryString= "SELECT * FROM "+entrega+(arco!=nullptr ? " WHERE Arco LIKE "+arco+" AND" : " WHERE")+" IMG"+(galeria==1 ? " NOT" : " IS" )+" NULL";
    QSqlQuery query;
    query.exec(queryString);
    while(query.next()){ //rellenamos la lista con los resultados
        ui->listWidget_2->addItem(query.value("Desc").toString());

        if(galeria==1){
            // use initializer list to construct QJsonObject
            auto data1 = QJsonObject(
            {
            qMakePair(QString("Desc"), query.value("Desc").toString()),
            qMakePair(QString("IMG"), query.value("IMG").toString())
            });
            this->galeria.push_back(QJsonValue(data1));
        }

//        ui->listWidget_2->item(ui->listWidget_2->count()-1)->setData(1,query.value("IMG").toString()); //guardamos la url por debajo
    }
}

listWidget::~listWidget()
{
    delete ui;
}

void listWidget::on_listWidget_2_itemClicked(QListWidgetItem *item) //'zoom' de la conia
{
    if(!this->galeria.empty()){ //galeria multimedia
        switch (this->tipoGaleria) {
            case 1:{ //imagenes
                //stacked widget con la galeria de imagenes, le pasamos el array y la row de la imagen actual
                gallery *galeria=new gallery(nullptr, this->galeria, ui->listWidget_2->row(item));
                galeria->show();
                break;
            }
            case 2:{ //videos
                QMediaPlayer *player = new QMediaPlayer;

                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/videos/Fortnite_20210917193935.mp4"));
                player->setPlaylist(playlist);
                QVideoWidget *videoWidget = new QVideoWidget;
                player->setVideoOutput(videoWidget);
                //videoWidget->setFullScreen(true); -> esta es la que hacen los videojuegos
                videoWidget->setGeometry(100,100,300,400); //definimos una ventana small
                videoWidget->showMaximized(); //la mostramos maximizada


                playlist->setCurrentIndex(1);
                player->play();
                break;
            }
            case 3:{ //audio
                break;
            }
        }



//        QMessageBox::about(this,"Coña",item->data(1).toString());
    }else QMessageBox::about(this,"Coña",item->text());

}

