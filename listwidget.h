#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QJsonArray>
#include "gallery.h"

namespace Ui {
class listWidget;
}

class listWidget : public QWidget
{
    Q_OBJECT

public:
    explicit listWidget(QWidget *parent = nullptr, QString entrega = nullptr, QString arco = nullptr, bool galeria=false);
    ~listWidget();
protected:
    void closeEvent(QCloseEvent *e); //evento de cierre de la modal
private slots:
    void on_listWidget_2_itemClicked(QListWidgetItem *item);

private:
    Ui::listWidget *ui;
    QJsonArray imagenes; //puede ser de imagenes, video o audio
    gallery *galeria=new gallery();
};

#endif // LISTWIDGET_H
