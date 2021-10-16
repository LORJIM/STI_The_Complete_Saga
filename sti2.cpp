#include "sti2.h"
#include "ui_sti2.h"
#include "listwidget.h"
#include <QSqlQuery>
#include <QJsonObject>
#include <QDir>
#include <QFileInfo>
#include <QMovie>

STI2::STI2(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::STI2)
{
    ui->setupUi(this);
}

STI2::~STI2()
{
    delete ui;
}

void STI2::on_pushButton_2_clicked() //principal
{
    this->setCurrentIndex(1);
}


void STI2::on_pushButton_6_clicked() //dani
{
    this->loadMiniSerie("1");
}


void STI2::on_pushButton_4_clicked() //santi
{
    this->loadMiniSerie("2");
}


void STI2::on_pushButton_5_clicked() //roberto
{
    this->loadMiniSerie("3");
}


void STI2::on_pushButton_clicked() //jorge
{
    this->loadMiniSerie("4");
}

void STI2::loadMiniSerie(QString serie){
    this->setCurrentIndex(2);
    this->capitulos=QJsonArray(); //resetea array

    QString path=QCoreApplication::applicationDirPath()+"/images/MINI_SERIES/"+serie+"/"; //path imagenes de la serie
    int capitulo=1; //contador necesario tambien para ir cogiendo las imagenes locales
    //query sql
    QSqlQuery query;
    query.exec("SELECT * FROM MINISERIES WHERE SUBSTR(ID,1,1) LIKE "+serie); //select de los caps de la serie
    while(query.next()){ //los vamos guardando en el array
        //primero buscamos las imagenes y su desc en local
        //IMPORTANTE: QUE SEAN TODAS JPG O GIF PARA EVITAR CONTROLES ADICIONALES
        QFileInfo img1(path+QString::number(capitulo)+"1.jpg");
        QFileInfo img1GIF(path+QString::number(capitulo)+"1.gif");
        QFileInfo img2(path+QString::number(capitulo)+"2.jpg");
        QFileInfo img2GIF(path+QString::number(capitulo)+"2.gif");

        // use initializer list to construct QJsonObject (asignamos valores
        auto data1 = QJsonObject(
        {
        qMakePair(QString("SERIE"), query.value("SERIE").toString()),
        qMakePair(QString("CAP"), query.value("CAP").toString()),
        qMakePair(QString("DESC"), query.value("DESC").toString()),
        qMakePair(QString("IMG"), (img1.exists() ? img1.absoluteFilePath() : (img1GIF.exists() ? img1GIF.absoluteFilePath() : ""))),
        qMakePair(QString("IMG2"),(img2.exists() ? img2.absoluteFilePath() : (img2GIF.exists() ? img2GIF.absoluteFilePath() : ""))),
        qMakePair(QString("IMGDESC"), query.value("IMGDESC").toString()),
        qMakePair(QString("IMG2DESC"), query.value("IMG2DESC").toString())
        });
        this->capitulos.push_back(QJsonValue(data1));
        capitulo++;
    }
    this->loadCapitulo(1);
}

void STI2::loadCapitulo(int capitulo){
    //este seteo es necesario para manejar los botones de atras y siguiente capitulo
    this->capitulo=capitulo;
    if(this->capitulo==1) ui->pushButton_8->hide(); //si es el primero no hay cap anterior
    else if(this->capitulo==2)ui->pushButton_8->show(); //a partir del 2 se muestra

    if(this->capitulo==this->capitulos.count()) ui->pushButton_16->hide(); //si es el ultimo no hay cap siguiente
    else ui->pushButton_16->show(); //a partir del 2 se muestra

    capitulo--; //en el array es uno menos
    ui->labelTITU->setText(this->capitulos.at(capitulo).toObject().value("SERIE").toString());
    ui->labelCAP->setText(this->capitulos.at(capitulo).toObject().value("CAP").toString());
    ui->labelDESC->setText(this->capitulos.at(capitulo).toObject().value("DESC").toString());
    auto img1=this->capitulos.at(capitulo).toObject().value("IMG");
    if(img1!=""){
        QString img1String=img1.toString();
        if(img1String.endsWith("jpg")){
            QPixmap pix(img1String); //accedemos a la imagen con la ruta de recursos de la columna Image
            ui->labelIMG->setPixmap(pix); //seteamos la imagen
        }else if(img1String.endsWith("gif")){ //si es gif el proceso es diferente
            QMovie *movie = new QMovie(img1String);
            ui->labelIMG->setMovie(movie);
            movie->start();
        }
    }else{
        ui->labelIMG->clear();
    }

    auto img2=this->capitulos.at(capitulo).toObject().value("IMG2");
    if(img2!=""){
        QString img2String=img2.toString();
        if(img2String.endsWith("jpg")){
            QPixmap pix(img2String); //accedemos a la imagen con la ruta de recursos de la columna Image
            ui->labelIMG2->setPixmap(pix); //seteamos la imagen
        }else if(img2String.endsWith("gif")){ //si es gif el proceso es diferente
            QMovie *movie = new QMovie(img2String);
            ui->labelIMG2->setMovie(movie);
            movie->start();
        }
    }else{
        ui->labelIMG2->clear();
    }


    auto img1Desc=this->capitulos.at(capitulo).toObject().value("IMGDESC");
    if(!img1Desc.isNull())
        ui->labelIMGDESC->setText(img1Desc.toString());
    auto img2Desc=this->capitulos.at(capitulo).toObject().value("IMG2DESC");
    if(!img2Desc.isNull())
        ui->labelIMG2DESC->setText(img2Desc.toString());

}

void STI2::on_pushButton_16_clicked() //siguiente capitulo
{
    this->loadCapitulo(this->capitulo+1);
}


void STI2::on_pushButton_8_clicked() //anterior capitulo
{
    this->loadCapitulo(this->capitulo-1);
}


void STI2::on_pushButton_9_clicked() //volver al menu
{
    this->setCurrentIndex(0);
}


void STI2::on_pushButton_3_clicked() //volver al menu en principal
{
    this->setCurrentIndex(0);
}


void STI2::on_pushButton_7_clicked() //listado de chorradas
{
    listWidget *listado=new listWidget(nullptr,"STI2");
    listado->show();
}

void STI2::loadVideo(QUrl url){ //funcion comun para reproducir videos de rapunsen
    this->player->~Player(); //quitamos el anterior video si ya hay uno abierto
    this->player=new Player();
    QList<QUrl> list = { url };
    this->player->addToPlaylist(list);
    this->player->show();
    this->player->play(); //lo reproducimos automaticamente fullscreen
}

void STI2::on_pushButton_10_clicked() //rapunsen 1
{
    loadVideo(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/videos/rapunsen.avi"));
}

void STI2::on_pushButton_11_clicked() //rapunsen 2
{
    loadVideo(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/videos/rapunsen2.avi"));
}


void STI2::on_pushButton_13_clicked() //rapunsen 3
{
    loadVideo(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/videos/rapunsen3.avi"));
}


void STI2::on_pushButton_12_clicked() //rapunsen 4
{
    loadVideo(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/videos/rapunsen4.mp4"));
}

void STI2::loadPlayer(int tipo){
    QString path=QCoreApplication::applicationDirPath()+(tipo==0 ? "/music" : "/videos")+"/STI2/"; //directorio donde estan los archivos
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

void STI2::on_pushButton_14_clicked() //galeria de videos
{
    loadPlayer(1); //1 indica que es video
}


void STI2::on_pushButton_15_clicked() //galeria de audios
{
    loadPlayer(0); //1 indica que es audio
}


void STI2::on_pushButton_17_clicked() //galeria de imagenes
{
    listWidget *listado=new listWidget(nullptr,"STI2",nullptr,true);
    listado->show();
}

