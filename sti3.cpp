#include "sti3.h"
#include "ui_sti3.h"
#include "listwidget.h"

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


void STI3::on_pushButton_clicked()
{
    listWidget *listado=new listWidget(nullptr,"STI3","1");
    listado->show();
}


void STI3::on_pushButton_2_clicked()
{
    listWidget *listado=new listWidget(nullptr,"STI3","2");
    listado->show();
}

