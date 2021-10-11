#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modalpj.h"
#include "sti3.h"
#include "sti2.h"
#include "sti1.h"
#include "daniassistant.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QSystemTrayIcon>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qApp->installEventFilter(this); //necesario para disparar mouse move event sin tener que apretar boton
    //setmousetracking true solo sirve para widgets, aqui no me sirvio
    ui->setupUi(this);

    //antes de que arranque la app,
    //mostramos un mensaje para activar o desactivar a dani
    QMessageBox msgBox;
    msgBox.setText("¿Desea usar el asistente?");
    msgBox.setInformativeText("ADVERTENCIA: El uso del asistente puede ser peligroso para el funcionamiento correcto de aplicación, "
"utilizar bajo propia responsabilidad.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    QCheckBox *chkBoxS=new QCheckBox("Sí, deseo utilizar el asistente de ahora en adelante.");
    msgBox.setCheckBox(chkBoxS);
    msgBox.setIconPixmap(QPixmap(":/icons/STI_The_Complete_Saga.ico")); //icono personalizado
    if(msgBox.exec() && chkBoxS->isChecked()){
           this->asistenteDani=true; //indicador
    }

    //propiedades de la app en segundo plano abajo a la derecha
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/icons/STI_The_Complete_Saga.ico")); //ruta de recursos
    mSystemTrayIcon->setToolTip("STI The Complete Saga"); //tooltip
    mSystemTrayIcon->show();

    if(asistenteDani){ //llegados a este punto inicializamos a dani si procede
        //DaniAssistant *daniassistant=
        new DaniAssistant(this,mSystemTrayIcon); //le pasamos el sistema de notis de la app
    }

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
    //lamentablemente esta funcion no puede estar en el DLL ya que contiene un protected event y no podemos acceder a el desde el DLL
    //de todas formas, el DLL esta pensado para funciones en segundo plano, y esta no es una de ellas asi que OK
    if(this->asistenteDani){
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


void MainWindow::on_pushButton_3_clicked()
{
    STI2 *sti2=new STI2();
    sti2->show();
}

//el juego del raton de dani
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        emit mouseMoved(); //emite la signal al asistente para que sepa que se ha movido el raton
    }
    return false;
}

void MainWindow::on_pushButton_clicked()
{
    STI1 *sti1=new STI1();
    sti1->show();
}


void MainWindow::on_actionGeorgie_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"3"));
}


void MainWindow::on_actionAbel_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"10"));
}


void MainWindow::on_actionSanti_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"11"));
}


void MainWindow::on_actionCarmen_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"12"));
}


void MainWindow::on_actionTorresano_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"13"));
}


void MainWindow::on_actionCamacho_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"14"));
}


void MainWindow::on_actionCarmelo_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"15"));
}


void MainWindow::on_actionJulio_triggered()
{
    loadSubWindow(new modalPJ(nullptr,"16"));
}

