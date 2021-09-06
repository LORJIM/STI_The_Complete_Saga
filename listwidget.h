#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class listWidget;
}

class listWidget : public QWidget
{
    Q_OBJECT

public:
    explicit listWidget(QWidget *parent = nullptr, QString entrega = "1", QString arco = nullptr); //entrega 1 default para que no pete la query
    ~listWidget();

private slots:
    void on_listWidget_2_itemClicked(QListWidgetItem *item);

private:
    Ui::listWidget *ui;
};

#endif // LISTWIDGET_H
