#include "listwidget.h"
#include "ui_listwidget.h"
#include <QSqlQuery>
#include <QMessageBox>

listWidget::listWidget(QWidget *parent, QString entrega, QString arco) :
    QWidget(parent),
    ui(new Ui::listWidget)
{
    ui->setupUi(this);

    //aqui ejecutamos la query con la entrega y arco para cargar las conias
    QString queryString= "SELECT * FROM "+entrega+(arco!=nullptr ? " WHERE Arco LIKE "+arco : "");
    QSqlQuery query;
    query.exec(queryString);
    while(query.next()){ //rellenamos la lista con los resultados
        ui->listWidget_2->addItem(query.value("Desc").toString());
    }
}

listWidget::~listWidget()
{
    delete ui;
}

void listWidget::on_listWidget_2_itemClicked(QListWidgetItem *item) //'zoom' de la conia
{
    QMessageBox::about(this,"Coña",item->text());
}

