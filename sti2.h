#ifndef STI2_H
#define STI2_H

#include <QStackedWidget>
#include <QJsonArray>

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

private:
    Ui::STI2 *ui;
    void loadMiniSerie(QString serie);
    void loadCapitulo(int capitulo);
    QString serie;
    int capitulo;
    QJsonArray capitulos;
};

#endif // STI2_H
