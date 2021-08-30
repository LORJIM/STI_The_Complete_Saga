#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *e); //evento de cierre de la mainwindow
private slots:
    void on_actionAcerca_de_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui; //los * son punteros, como referencias para llamar a estas propiedades en el cpp
    QSystemTrayIcon *mSystemTrayIcon; //esto es para que salga abajo a la derecha como app en segundo plano y para notificaciones
};
#endif // MAINWINDOW_H
