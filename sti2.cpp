#include "sti2.h"
#include "ui_sti2.h"
#include "listwidget.h"
#include <QSqlQuery>
#include <QJsonObject>

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

    //query sql
    QSqlQuery query;
    query.exec("SELECT * FROM MINISERIES WHERE SUBSTR(ID,1,1) LIKE "+serie); //select de los caps de la serie
    while(query.next()){ //los vamos guardando en el array
        // use initializer list to construct QJsonObject
        auto data1 = QJsonObject(
        {
        qMakePair(QString("SERIE"), query.value("SERIE").toString()),
        qMakePair(QString("CAP"), query.value("CAP").toString()),
        qMakePair(QString("DESC"), query.value("DESC").toString()),
        qMakePair(QString("IMG"), query.value("IMG").toString()),
        qMakePair(QString("IMG2"), query.value("IMG2").toString()),
        qMakePair(QString("IMGDESC"), query.value("IMGDESC").toString()),
        qMakePair(QString("IMG2DESC"), query.value("IMG2DESC").toString())
        });

        this->capitulos.push_back(QJsonValue(data1));
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
    if(!this->capitulos.at(capitulo).toObject().value("IMG").isNull()){
        QPixmap pix(this->capitulos.at(capitulo).toObject().value("IMG").toString()); //accedemos a la imagen con la ruta de recursos de la columna Image
        ui->labelIMG->setPixmap(pix); //seteamos la imagen
    }
    if(!this->capitulos.at(capitulo).toObject().value("IMG2").isNull()){
        QPixmap pix(this->capitulos.at(capitulo).toObject().value("IMG2").toString()); //accedemos a la imagen con la ruta de recursos de la columna Image
        ui->labelIMG->setPixmap(pix); //seteamos la imagen
    }

    if(!this->capitulos.at(capitulo).toObject().value("IMGDESC").isNull())
        ui->labelIMGDESC->setText(this->capitulos.at(capitulo).toObject().value("IMGDESC").toString());
    if(!this->capitulos.at(capitulo).toObject().value("IMG2DESC").isNull())
        ui->labelIMG2DESC->setText(this->capitulos.at(capitulo).toObject().value("IMG2DESC").toString());

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

