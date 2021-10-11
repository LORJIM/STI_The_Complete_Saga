#ifndef STI1_H
#define STI1_H

#include <QStackedWidget>

namespace Ui {
class STI1;
}

class STI1 : public QStackedWidget
{
    Q_OBJECT

public:
    explicit STI1(QWidget *parent = nullptr);
    ~STI1();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::STI1 *ui;
    void loadPlayer(int tipo);
};

#endif // STI1_H
