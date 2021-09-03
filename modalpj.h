#ifndef MODALPJ_H
#define MODALPJ_H

#include <QDialog>

namespace Ui {
class modalPJ;
}

class modalPJ : public QDialog
{
    Q_OBJECT

public:
    explicit modalPJ(QWidget *parent = nullptr, QString idpj = "1"); //le ponemos por defecto 1 pero vamos, siempre vendra informado
    ~modalPJ();

private:
    Ui::modalPJ *ui;
};

#endif // MODALPJ_H
