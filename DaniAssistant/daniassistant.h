#ifndef DANIASSISTANT_H
#define DANIASSISTANT_H

#include "DaniAssistant_global.h"
#include <QSystemTrayIcon>

class DANIASSISTANT_EXPORT DaniAssistant : public QObject
{
    Q_OBJECT
public:
    DaniAssistant(QWidget *parent,QSystemTrayIcon *trayIcon);
    DaniAssistant(QWidget *parent=nullptr);
    ~DaniAssistant(void){};
signals:
    void mouseMovedSignal();
    void mouseMovedSignalFinished();
private:
    QSystemTrayIcon *sistemaNotis;
    QWidget *appPrincipal;
private slots:
    void notiBienvenida();
    void insist();
    void advertencia();
    void mouseMoved();
    void juego();
    void pintar();
};

#endif // DANIASSISTANT_H
