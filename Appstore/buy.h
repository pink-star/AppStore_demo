#ifndef BUY_H
#define BUY_H

#include <QObject>
#include <function.h>
#include "ui_widget.h"

class Buy : public QObject
{
    Q_OBJECT
public:
    explicit Buy(QObject *parent = nullptr);

signals:

public slots:
     void Buyapp(Software_Tree * Head,Ui::Widget * ui,int & total);
};

#endif // BUY_H
