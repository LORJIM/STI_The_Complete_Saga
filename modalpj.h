#ifndef MODALPJ_H
#define MODALPJ_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class modalPJ;
}

class modalPJ : public QDialog
{
    Q_OBJECT

public:
    explicit modalPJ(QWidget *parent = nullptr, QString idpj = "1"); //le ponemos por defecto 1 pero vamos, siempre vendra informado
    ~modalPJ();
protected:
    void closeEvent(QCloseEvent *e); //evento de cierre de la modal
private:
    Ui::modalPJ *ui;
    QMediaPlayer *music = new QMediaPlayer(); //el qmediaplayer lo ponemos como propiedad para poder manejarlo en el closeEvent
};

#endif // MODALPJ_H
