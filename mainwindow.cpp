#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newDoraemonPushButton_clicked()
{
    //muestra una ventana emergente, en este caso informativa
    QMessageBox::information(this,"Bienvenido","Hola soy Dani, desde este momento seré tu asistente en la app, ¿puedo ayudarte en algo? 7u7");
}


void MainWindow::on_pushButton_clicked()
{
     QMessageBox::warning(this,"Advertencia","Hola soy Dani otra vez, tu asistente :) \nTe advierto, si me sigues ignorando, empezarán a ocurrir cosas malas, imbécil.");
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::critical(this,"SYSTEM_ERROR","ERROR ERROR ERROR ERROR");
}


void MainWindow::on_pushButton_3_clicked()
{
    //ventana emergente que pide un valor
    QString s= QInputDialog::getText(this, "Introducir una frase", "Ingrese su frase");
    //label es el nombre del objeto en la ui donde seteamos la frase introducida
    ui->label->setText("Resultado: "+s);
    /* Si fuera un numero int o double lo seteariamos asi
    ui->label->setText(QString::number(s));*/
}


void MainWindow::on_actionAcerca_de_triggered()
{
    //para que en el about salga el icono de nuestra app, hay que ponerlo en la ui, en mainwindow
    QMessageBox::about(this,"Acerca de","STI The Complete Saga es una recopilación de la historia, personajes y "
    "mejores momentos de las andanzas de Jaime NP y Daniel Amorós en el desternillante mundo de STI.");
}

