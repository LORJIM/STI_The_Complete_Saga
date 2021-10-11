#ifndef STI2_H
#define STI2_H

#include <QStackedWidget>
#include <QJsonArray>
#include <player.h>

namespace Ui {
class STI2;
}

class STI2 : public QStackedWidget
{
    Q_OBJECT

public:
    explicit STI2(QWidget *parent = nullptr);
    ~STI2();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::STI2 *ui;
    void loadMiniSerie(QString serie);
    void loadCapitulo(int capitulo);
    void loadVideo(QUrl url);
    QString serie;
    int capitulo;
    QJsonArray capitulos;
    void loadPlayer(int tipo);
};

#endif // STI2_H
