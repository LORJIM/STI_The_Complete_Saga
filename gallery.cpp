#include "gallery.h"
#include "ui_gallery.h"
#include <QJsonObject>

gallery::gallery(QWidget *parent, QJsonArray imagenes, int imagenActual) :
    QStackedWidget(parent),
    ui(new Ui::gallery),
    imagenes(imagenes)
{
    ui->setupUi(this);

    loadImagen(imagenActual);

}

void gallery::loadImagen(int imagen){
    //este seteo es necesario para manejar los botones de atras y siguiente capitulo
    this->imagen=imagen;
    if(this->imagen==0) ui->pushButton_8->hide(); //si es el primero no hay imagen anterior
    else if(this->imagen==1)ui->pushButton_8->show(); //a partir del 2 se muestra

    if(this->imagen+1==this->imagenes.count()) ui->pushButton_16->hide(); //si es el ultimo no hay imagen siguiente
    else ui->pushButton_16->show(); //a partir del 2 se muestra

    if(!this->imagenes.at(imagen).toObject().value("IMG").isNull()){
        QPixmap pix(this->imagenes.at(imagen).toObject().value("IMG").toString()); //accedemos a la imagen con la ruta de recursos de la columna Image
        ui->labelIMG->setPixmap(pix); //seteamos la imagen
    }

    if(!this->imagenes.at(imagen).toObject().value("IMGDESC").isNull())
        ui->labelIMGDESC->setText(this->imagenes.at(imagen).toObject().value("Desc").toString());

}

gallery::~gallery()
{
    delete ui;
}

void gallery::on_pushButton_8_clicked() //anterior imagen
{
    this->loadImagen(this->imagen-1);
}


void gallery::on_pushButton_16_clicked() //siguiente imagen
{
    this->loadImagen(this->imagen+1);
}
