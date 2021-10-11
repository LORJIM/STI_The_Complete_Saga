#include "listwidget.h"
#include "ui_listwidget.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QJsonObject>
#include "gallery.h"
#include <QDir>

listWidget::listWidget(QWidget *parent, QString entrega, QString arco, bool galeria) :
    QWidget(parent),
    ui(new Ui::listWidget)
{
    ui->setupUi(this);

    if(galeria){ //galeria de imagenes
        this->imagenes=QJsonArray(); //galeria multimedia resetea array
        QString path=QCoreApplication::applicationDirPath()+"/images/"+entrega+"/"+(arco!=nullptr ? arco+"/" : ""); //directorio donde estan los videos
        QDir source(path);
        QStringList filters={ //ponemos esto para evitar que lea archivos que no debe
            "*.jpg","*.png","*.jpeg","*.gif"
        };
        QStringList listaImages=source.entryList(filters); //leemos los nombres de las imagenes

        foreach (QString imagen, listaImages) { //los vamos metiendo en la lista de imagenes
            ui->listWidget_2->addItem(imagen);
            // use initializer list to construct QJsonObject
            auto data1 = QJsonObject(
            {
            qMakePair(QString("Desc"), imagen), //el nombre de la imagen es su descripcion
            qMakePair(QString("IMG"), path+imagen) //esto es la url local de la imagen
            });
            this->imagenes.push_back(QJsonValue(data1));
        }

    }else{ //lista de conias
        //aqui ejecutamos la query con la entrega y arco para cargar las conias
        QString queryString= "SELECT * FROM "+entrega+(arco!=nullptr ? " WHERE Arco LIKE "+arco : "");
        QSqlQuery query;
        query.exec(queryString);
        while(query.next()){ //rellenamos la lista con los resultados
            ui->listWidget_2->addItem(query.value("Desc").toString());
    //        ui->listWidget_2->item(ui->listWidget_2->count()-1)->setData(1,query.value("IMG").toString()); //guardamos la url por debajo
        }
    }

}

listWidget::~listWidget()
{
    delete ui;
}

void listWidget::on_listWidget_2_itemClicked(QListWidgetItem *item) //'zoom' de la conia
{
    if(!this->imagenes.empty()){ //galeria multimedia
        //stacked widget con la galeria de imagenes, le pasamos el array y la row de la imagen actual
        gallery *galeria=new gallery(nullptr, this->imagenes, ui->listWidget_2->row(item));
        galeria->show();
//      QMessageBox::about(this,"Coña",item->data(1).toString());
    }else QMessageBox::about(this,"Coña",item->text());

}

