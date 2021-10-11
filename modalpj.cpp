#include "modalpj.h"
#include "ui_modalpj.h"
#include <QSqlQuery>
#include <QMediaPlaylist>

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
        QPixmap pix(QCoreApplication::applicationDirPath()+query.value("Image").toString()); //accedemos a la imagen con la ruta local de la columna Image
        ui->labelPic->setPixmap(pix); //seteamos la imagen
        if(!query.value("Image2").isNull()){
            QPixmap pix(QCoreApplication::applicationDirPath()+query.value("Image2").toString()); //accedemos a la imagen con la ruta local de la columna Image
            ui->labelPic2->setPixmap(pix); //seteamos la imagen
        }
    }

    //musica para paco xD
    if(idpj=="6"){
        QMediaPlaylist *playlist = new QMediaPlaylist();
        playlist->addMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/music/pasodoble.mp3"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop); //la ponemos en bucle para evitar que solo se reproduzca una vez

        this->music->setPlaylist(playlist);
        this->music->play();
    }
}

void modalPJ::closeEvent(QCloseEvent *e){ //parar la musica cuando cerremos la modal
    this->music->stop();
}

modalPJ::~modalPJ()
{
    delete ui;
}
