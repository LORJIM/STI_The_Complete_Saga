#include "daniassistant.h"
#include <QSystemTrayIcon>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QEventLoop>

DaniAssistant::DaniAssistant(QWidget *parent,QSystemTrayIcon *trayIcon)
    : sistemaNotis(trayIcon), appPrincipal(parent)
{
    connect( this->appPrincipal, SIGNAL(mouseMoved()), this, SLOT(mouseMoved()) );
    //aqui iran todas las llamadas a las funciones que se iran lanzando
    this->notiBienvenida();
    //30 seg
    QTimer::singleShot(30000, this, &DaniAssistant::insist);
    //el siguiente QTimer NO espera a que el otro haya terminado, por lo que se lanza 30 seg despues
    QTimer::singleShot(60000, this, &DaniAssistant::advertencia);
    QTimer::singleShot(90000, this, &DaniAssistant::juego);
    QTimer::singleShot(150000, this, &DaniAssistant::pintar);
}


void DaniAssistant::notiBienvenida(){
    //notificacion de bienvenida
    this->sistemaNotis->showMessage("¡Hola!", //mensaje de cabecera
                                 "Hola soy Dani, desde este momento seré tu asistente en la app, ¿puedo ayudarte en algo? 7u7",
                                 QIcon(":/icons/dani.ico"), //icono de la noti
                                 10000); //duracion en ms
}
void DaniAssistant::insist(){
    //notificacion de insistencia
    this->sistemaNotis->showMessage("¿Hola?", //mensaje de cabecera
                                 "¿Sigues ahí, estás ahí? Hazme casoo",
                                 QIcon(":/icons/dani.ico"), //icono de la noti
                                 10000); //duracion en ms
}
void DaniAssistant::advertencia(){
    //notificacion de advertencia
    QMessageBox msgBox;
    msgBox.setText("Advertencia");
    msgBox.setInformativeText("Hola soy Dani otra vez, tu asistente :) \nTe advierto, si me sigues ignorando, empezarán a ocurrir cosas malas, imbécil.");
    msgBox.setIconPixmap(QPixmap(":/icons/dani.ico"));
    msgBox.exec();
}
void DaniAssistant::juego(){
    QMessageBox msgBox;
    msgBox.setText("Juego");
    msgBox.setInformativeText("Vamos a jugar a un juego, debes aguantar 30seg sin moverte, y prometo que te dejo en paz ;)");
    msgBox.setIconPixmap(QPixmap(":/icons/dani.ico"));
    msgBox.exec();
    //cuando se cierre el aviso de dani empieza el juego
    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop loop;
    connect( this, &DaniAssistant::mouseMovedSignal, &loop, &QEventLoop::quit );
    connect( &timer, &QTimer::timeout, &loop, &QEventLoop::quit );
    timer.start(30000);
    bool seMovio=false;
    do{
        loop.exec();
        //estas lineas de abajo no se ejecutan hasta que no hayamos salido del loop (que podriamos verlo como un listener)
        //que o bien es por timeout del timer o bien por mouseMoveEvent
        if(timer.isActive()){
            qDebug("semovio");
            //sacar un mensaje de error cada vez que se mueva
            seMovio=true;
        }else if(!seMovio){
            qDebug("nosemovio");
            //si cumple las ordenes de dani, sale otro mensaje de dani burlandose, diciendo jajaaa te tengo controlado
            //o sometido y que de momento le deja seguir utilizando la app
        }
    }while(timer.isActive());

}
void DaniAssistant::mouseMoved(){
    emit mouseMovedSignal();
}
void DaniAssistant::pintar(){
    QMessageBox msgBox;
    msgBox.setText("Píntame algo anda jaja");msgBox.setIconPixmap(QPixmap(":/icons/dani.ico"));
    msgBox.exec();
    system("mspaint.exe"); //te abre el paint xDDDD
}
