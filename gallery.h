#ifndef GALLERY_H
#define GALLERY_H

#include <QStackedWidget>
#include <QJsonArray>

namespace Ui {
class gallery;
}

class gallery : public QStackedWidget
{
    Q_OBJECT

public:
    explicit gallery(QWidget *parent = nullptr,QJsonArray imagenes=QJsonArray(), int imagenActual=1);
    ~gallery();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_16_clicked();

    void on_actionAtras_triggered();

private:
    Ui::gallery *ui;
    void loadImagen(int imagen);
    QJsonArray imagenes;
    int imagen;
};

#endif // GALLERY_H
