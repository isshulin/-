#include "start.h"
#include<QTimer>
#include<QPushButton>
#include<QPixmap>

Start::Start(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(1000,800);
    setWindowTitle("制式转换");
    QPushButton *btn=new QPushButton(this);



    sec=new Second;
    QPixmap pix("://图片/start.png");
    btn->setFixedSize(pix.width(),pix.height());
    btn->setStyleSheet("QPushButton{border:0px;}");
    btn->setIcon(pix);
    btn->setIconSize(QSize(pix.width()*.8,pix.height()*.5));
    btn->move(this->width()*.3,this->height()*.7);
    connect(btn,&QPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            this->hide();
            sec->show();
        });

    });
}
void Start::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/图片/src=http___cdn.duitang.com_uploads_item_201409_08_20140908130732_kVXzh.jpeg&refer=http___cdn.duitang.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    painter.setFont(QFont("宋体",25,QFont::Bold,true));
    painter.drawText(QRect(350,300,700,500),"制   式  转  换");

}
Start::~Start()
{

}
