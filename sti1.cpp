#include "sti1.h"
#include "ui_sti1.h"
#include "listwidget.h"

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

