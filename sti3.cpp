#include "sti3.h"
#include "ui_sti3.h"
#include "listwidget.h"
#include "player.h"
#include <QUrl>
#include <QDir>

STI3::STI3(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::STI3)
{
    ui->setupUi(this);
}

STI3::~STI3()
{
    delete ui;
}

void STI3::on_pushButton_6_clicked()
{
    this->setCurrentIndex(1);
}


void STI3::on_pushButton_5_clicked()
{
    this->setCurrentIndex(2);
}


void STI3::on_pushButton_4_clicked()
{
    this->setCurrentIndex(3);
}


void STI3::on_pushButton_3_clicked()
{
    this->setCurrentIndex(0);
}


void STI3::on_pushButton_7_clicked()
{
    this->setCurrentIndex(0);
}


void STI3::on_pushButton_8_clicked()
{
    this->setCurrentIndex(0);
}


void STI3::on_pushButton_9_clicked()
{
    this->setCurrentIndex(4);
}


void STI3::on_pushButton_10_clicked()
{
    this->setCurrentIndex(0);
}


void STI3::on_pushButton_clicked() //conias Arco 1
{
    listWidget *listado=new listWidget(nullptr,"STI3","1");
    listado->show();
}


void STI3::on_pushButton_2_clicked() //conias Arco 2
{
    listWidget *listado=new listWidget(nullptr,"STI3","2");
    listado->show();
}


void STI3::on_pushButton_11_clicked() //galeria de imagenes Arco 1
{
    listWidget *listado=new listWidget(nullptr,"STI3","1",true);
    listado->show();
}


void STI3::on_pushButton_12_clicked() //galeria de videos Arco 1
{
    loadPlayer(1,1);
}


void STI3::on_pushButton_15_clicked() //imagenes Arco 3
{
    listWidget *listado=new listWidget(nullptr,"STI3","3",true);
    listado->show();
}


void STI3::on_pushButton_14_clicked() //videos Arco 3
{
    loadPlayer(1,3);
}

void STI3::loadPlayer(int tipo, int arco){
    QString path=QCoreApplication::applicationDirPath()+(tipo==0 ? "/music" : "/videos")+"/STI3/"+arco+"/"; //directorio donde estan los archivos
    QDir source(path);
    QStringList filters;
    if(tipo==0){ //ponemos esto para evitar que lea archivos que no debe
        filters.append({"*.mp3","*.m4a"});
    }else if(tipo==1){
        filters.append({"*.avi","*.mp4"});
    }

    QStringList listaArchivos=source.entryList(filters); //leemos los nombres de los videos
    QList<QUrl> listaReprod;
    foreach (QString archivo, listaArchivos) { //los vamos metiendo en la lista de Reproduccion
        QUrl url=QUrl::fromLocalFile(path+archivo); //url local completa del video
        listaReprod.append(url);
    }
    Player *player = new Player;
    player->addToPlaylist(listaReprod);
    player->show(); //inicializamos el reproductor
}
