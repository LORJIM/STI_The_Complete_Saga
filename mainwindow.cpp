#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modalpj.h"
#include "sti3.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //mostrar un qmessagebox que nos pregunte si queremos utilizar el asistente,
    //usar bajo propio riesgo para activar o desactivar a dani


    //propiedades de la app en segundo plano abajo a la derecha
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/icons/STI_The_Complete_Saga.ico")); //ruta de recursos
    mSystemTrayIcon->setToolTip("STI The Complete Saga"); //tooltip
    mSystemTrayIcon->show();

    //notificacion de bienvenida
    mSystemTrayIcon->showMessage(tr("¡Hola!"), //mensaje de cabecera
                                 tr("Hola soy Dani, desde este momento seré tu asistente en la app, ¿puedo ayudarte en algo? 7u7"),
                                 QIcon(":/icons/dani.ico"), //icono de la noti
                                 10000); //duracion en ms


    //mensajes de dani, utilizar qtimer singleshot para mostrarlos cada cierto tiempo,ponemos el if aqui
    //y si el asistente esta activado, llamamos a las funciones de dani que tienen qtimer
    //si me apuras hasta deberiamos meterlas en un DLL, utilizando thread para que se ejecute al mismo tiempo que el resto de la app...etc.
    //mostrar un segundo mensaje en plan noti de sigues ahi, estas ahi? hazme casoo
    //pasado un poco mas de tiempo ya sale el messagebox de advertencia
    //podriamos poner algun reto de dani como por ejemplo que no se mueva el usuario durante 30seg, y como lo vemos
    //con el mouseevent le podemos rayar y sacar un mensaje de error cada vez que se mueva
    //si cumple las ordenes de dani, sale otro mensaje de dani burlandose, diciendo jajaaa te tengo controlado
    //o sometido y que de momento le deja seguir utilizando la app
    //pintame algo anda jaja system(mspaint.exe)


    //A PACO PONERLE MUSICA DE TOROS DE FONDO
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAcerca_de_triggered()
{
    //para que en el about salga el icono de nuestra app, hay que ponerlo en la ui, en mainwindow
    QMessageBox::about(this,"Acerca de","STI The Complete Saga es una recopilación de la historia, personajes y "
    "mejores momentos de las andanzas de Jaime NP y Daniel Amorós en el desternillante mundo de STI.");
}

void MainWindow::closeEvent(QCloseEvent *e){ //mensaje de confirmacion antes de cerrar el programa
    QMessageBox msgBox;
    msgBox.setText("Dani no quiere que te vayas :(");
    msgBox.setInformativeText("¡No!, no te vayas por favor. Me haces daño...ugghh");
    msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Close);
    msgBox.setIconPixmap(QPixmap(":/icons/dani.ico")); //icono personalizado
    //traduccion de botones
    msgBox.setButtonText(QMessageBox::Close, tr("Cerrar")); //esto deberia hacerse con un translator externo pero meh
    msgBox.setButtonText(QMessageBox::Cancel, tr("Cancelar"));
    int ret = msgBox.exec(); //resultado de la modal dependiendo del boton que clickemos
    switch (ret) {
       case QMessageBox::Close:
           break;
       case QMessageBox::Cancel:
           e->ignore(); //evita que se cierre el programa ya que estamos diciendo que ignore el evento
           break;
       default:
           // should never be reached
           break;
     }

}


void MainWindow::on_pushButton_2_clicked()
{
    STI3 *sti3=new STI3();
    sti3->show();
}


void MainWindow::on_actionDani_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"2")); //en la creacion de la modal pasamos la ID para hacer la query de datos
}

void MainWindow::loadSubWindow(QDialog *dialog){ //funcion para ahorrar codigo ya que esto lo haran todas las modales de PJs
    dialog->setModal(true);
    dialog->exec(); //carga la modal estandar sin info
}


void MainWindow::on_actionJaime_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"1"));
}


void MainWindow::on_actionJesucristo_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"4"));
}


void MainWindow::on_actionAlfonso_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"5"));
}


void MainWindow::on_actionPaco_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"6"));
}


void MainWindow::on_actionRoberto_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"9"));
}


void MainWindow::on_actionDJ_Azael_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"7"));
}


void MainWindow::on_actionHector_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"8"));
}

