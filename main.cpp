#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //cargamos nuestra database
    if(!QSqlDatabase::isDriverAvailable("QSQLITE")){
        qDebug() << "Error: QSQLITE no esta disponible";
        return -1;
    }
    QSqlDatabase bd= QSqlDatabase::addDatabase("QSQLITE");
    QString path=QCoreApplication::applicationDirPath()+"/data/STI.db"; //la DB la pondremos con el installer en carpeta data con respecto a la ruta del .exe
    bd.setDatabaseName(path); //pasamos el path dinamico de la database
    if(!bd.open()){
        qDebug() << bd.lastError().text();
        return -2;
    }

    return a.exec();
}
