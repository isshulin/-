#ifndef START_H
#define START_H
#include<QPainter>
#include <QWidget>
#include<second.h>
#include<QTimer>
#include<QDateTime>
#include<QLabel>
class Start : public QWidget
{
    Q_OBJECT

public:
    Start(QWidget *parent = 0);
    ~Start();
    Second *sec=NULL;
    void paintEvent(QPaintEvent *);
    QLabel label;
};

#endif // START_H
