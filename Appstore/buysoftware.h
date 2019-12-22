#ifndef BUYSOFTWARE_H
#define BUYSOFTWARE_H

#include <QObject>
#include <function.h>
#include "ui_widget.h"
class Buysoftware : public QObject
{
    Q_OBJECT
public:
    explicit Buysoftware(QObject *parent = nullptr);

signals:

public slots:
    void Buyapp(Software_Tree * Head,string software_name,Ui::Widget * ui);
};

#endif // BUYSOFTWARE_H
