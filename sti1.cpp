#include "sti1.h"
#include "ui_sti1.h"
#include "listwidget.h"
#include "player.h"
#include <QDir>
#include <QUrl>

STI1::STI1(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::STI1)
{
    ui->setupUi(this);
}

STI1::~STI1()
{
    delete ui;
}

void STI1::on_pushButton_7_clicked() //listado de conias
{
    listWidget *listado=new listWidget(nullptr,"STI1");
    listado->show();
}

void STI1::loadPlayer(int tipo){
    QString path=QCoreApplication::applicationDirPath()+(tipo==0 ? "/music" : "/videos")+"/STI1/"; //directorio donde estan los archivos
    QDir source(path);
    QStringList filters;
    if(tipo==0){ //ponemos esto para evitar que lea archivos que no debe
        filters.append({"*.mp3","*.m4a","*.opus","*.wav"});
    }else if(tipo==1){
        filters.append({"*.avi","*.mp4","*.mov","*.mkv","*.wmv"});
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

void STI1::on_pushButton_8_clicked() //galeria de audios
{
    loadPlayer(0); //0 indica que es audio
}


void STI1::on_pushButton_9_clicked() //galeria de videos
{
    loadPlayer(1); //1 indica que es video
}


void STI1::on_pushButton_10_clicked() //galeria de imagenes
{
    listWidget *listado=new listWidget(nullptr,"STI1",nullptr,true);
    listado->show();
}

