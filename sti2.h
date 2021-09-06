#ifndef STI2_H
#define STI2_H

#include <QStackedWidget>

namespace Ui {
class STI2;
}

class STI2 : public QStackedWidget
{
    Q_OBJECT

public:
    explicit STI2(QWidget *parent = nullptr);
    ~STI2();

private:
    Ui::STI2 *ui;
};

#endif // STI2_H
