#include "sti2.h"
#include "ui_sti2.h"

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
