#ifndef STI3_H
#define STI3_H

#include <QStackedWidget>
#include <QMediaPlayer>

namespace Ui {
class STI3;
}

class STI3 : public QStackedWidget
{
    Q_OBJECT

public:
    explicit STI3(QWidget *parent = nullptr);
    ~STI3();
protected:
    void closeEvent(QCloseEvent *e); //evento de cierre de la modal
private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();


    void on_pushButton_15_clicked();


    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::STI3 *ui;
    void loadPlayer(int tipo,int arco);
    QMediaPlayer *music = new QMediaPlayer(); //el qmediaplayer lo ponemos como propiedad para poder manejarlo en el closeEvent
};

#endif // STI3_H
