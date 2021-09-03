#include "modalpj.h"
#include "ui_modalpj.h"
#include <QSqlQuery>

modalPJ::modalPJ(QWidget *parent, QString idpj) :
    QDialog(parent),
    ui(new Ui::modalPJ)
{
    ui->setupUi(this);

    //aqui ejecutamos la query con la id del pj para cargar su info en cualquier modal cuando se crea
    QSqlQuery query;
    query.exec("SELECT * FROM PJS WHERE ID LIKE "+idpj);
    while(query.next()){ //solo obtendremos un resultado
        ui->desc->setText(query.value("Desc").toString());
        ui->nombre->setText(query.value("Nombre").toString());
        QPixmap pix(query.value("Image").toString()); //accedemos a la imagen con la ruta de recursos de la columna Image
        ui->labelPic->setPixmap(pix); //seteamos la imagen
        if(!query.value("Image2").isNull()){
            QPixmap pix(query.value("Image2").toString()); //accedemos a la imagen con la ruta de recursos de la columna Image
            ui->labelPic2->setPixmap(pix); //seteamos la imagen
        }
    }
}

modalPJ::~modalPJ()
{
    delete ui;
}
