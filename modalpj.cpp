#include "modalpj.h"
#include "ui_modalpj.h"
#include "listwidget.h"
#include <QSqlQuery>
#include <QMediaPlaylist>
#include <QFileInfo>

modalPJ::modalPJ(QWidget *parent, QString idpj) :
    QDialog(parent),
    ui(new Ui::modalPJ)
{
    ui->setupUi(this);

    QMediaPlayer music;
    //aqui ejecutamos la query con la id del pj para cargar su info en cualquier modal cuando se crea
    QSqlQuery query;
    query.exec("SELECT * FROM PJS WHERE ID LIKE "+idpj);
    while(query.next()){ //solo obtendremos un resultado
        ui->desc->setText(query.value("Desc").toString());
        ui->nombre->setText(query.value("Nombre").toString());
        QFileInfo img(QCoreApplication::applicationDirPath()+"/images/PJS/"+idpj+"/1.jpg");
        //IMPORTANTE: QUE SEAN TODAS JPG PARA EVITAR CONTROLES ADICIONALES
        if(img.exists()){ //si la imagen existe
            QPixmap pix(img.absoluteFilePath());
            ui->labelPic->setPixmap(pix); //seteamos la imagen
        }

        QFileInfo img2(QCoreApplication::applicationDirPath()+"/images/PJS/"+idpj+"/2.jpg");
        if(img2.exists()){ //si la imagen existe
            QPixmap pix(img2.absoluteFilePath());
            ui->labelPic2->setPixmap(pix); //seteamos la imagen
        }
    }

    if(idpj!="2"){ //escondemos el boton de obras de amoros para el restos de PJs
        //musica para paco xD
        if(idpj=="6"){
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/music/pasodoble.wav"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop); //la ponemos en bucle para evitar que solo se reproduzca una vez

            this->music->setPlaylist(playlist);
            this->music->play();
        }
        ui->buttonObras->hide();
    }

}

void modalPJ::closeEvent(QCloseEvent *e){ //parar la musica cuando cerremos la modal
    this->music->stop();
}

modalPJ::~modalPJ()
{
    delete ui;
}

void modalPJ::on_buttonObras_clicked() //obras de amoros
{
    listWidget *listado=new listWidget(nullptr,nullptr,nullptr,true); //mandando la entrega a null significa que la galeria que queremos son las obras de amoros
    listado->show();
}

