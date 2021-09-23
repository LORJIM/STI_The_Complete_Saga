#include "listwidget.h"
#include "ui_listwidget.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QJsonObject>
#include "gallery.h"

listWidget::listWidget(QWidget *parent, QString entrega, QString arco, bool galeria) :
    QWidget(parent),
    ui(new Ui::listWidget)
{
    ui->setupUi(this);

    if(galeria) this->imagenes=QJsonArray(); //resetea array

    //aqui ejecutamos la query con la entrega y arco para cargar las conias
    QString queryString= "SELECT * FROM "+entrega+(arco!=nullptr ? " WHERE Arco LIKE "+arco+" AND" : " WHERE")+" IMG"+(galeria ? " NOT" : " IS" )+" NULL";
    QSqlQuery query;
    query.exec(queryString);
    while(query.next()){ //rellenamos la lista con los resultados
        ui->listWidget_2->addItem(query.value("Desc").toString());

        if(galeria){
            // use initializer list to construct QJsonObject
            auto data1 = QJsonObject(
            {
            qMakePair(QString("Desc"), query.value("Desc").toString()),
            qMakePair(QString("IMG"), query.value("IMG").toString())
            });
            this->imagenes.push_back(QJsonValue(data1));
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
    if(!this->imagenes.empty()){

        //stacked widget con la galeria de imagenes, le pasamos el array y la row de la imagen actual
        gallery *galeria=new gallery(nullptr, this->imagenes, ui->listWidget_2->row(item));
        galeria->show();


//        QMessageBox::about(this,"Coña",item->data(1).toString());
    }else QMessageBox::about(this,"Coña",item->text());

}

