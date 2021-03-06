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
signals:
    void mouseMoved();
protected:
    void closeEvent(QCloseEvent *e); //evento de cierre de la mainwindow
private slots:
    void on_actionAcerca_de_triggered();

    void on_pushButton_2_clicked();

    void on_actionDani_triggered();

    void on_actionJaime_triggered();

    void on_actionJesucristo_triggered();

    void on_actionAlfonso_triggered();

    void on_actionPaco_triggered();

    void on_actionRoberto_triggered();

    void on_actionDJ_Azael_triggered();

    void on_actionHector_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_actionGeorgie_triggered();

    void on_actionAbel_triggered();

    void on_actionSanti_triggered();

    void on_actionCarmen_triggered();

    void on_actionTorresano_triggered();

    void on_actionCamacho_triggered();

    void on_actionCarmelo_triggered();

    void on_actionJulio_triggered();

private:
    Ui::MainWindow *ui; //los * son punteros, como referencias para llamar a estas propiedades en el cpp
    QSystemTrayIcon *mSystemTrayIcon; //esto es para que salga abajo a la derecha como app en segundo plano y para notificaciones
    void loadSubWindow(QDialog *widget); //funcion que muestra las modales de pjs (custom dialogs)
    bool eventFilter(QObject *obj, QEvent *event); //para el juego del raton de dani
    bool asistenteDani=false; //indicador de activacion del asistente
};
#endif // MAINWINDOW_H
