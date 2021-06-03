#include "third.h"
#include "ui_third.h"
#include<second.h>
#include<start.h>
#include<QDebug>
void Third::back(){
    emit comeback();
}

Third::Third(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Third)
{
    ui->setupUi(this);
    setWindowTitle("制式转换");
    connect(ui->pushButton,&QPushButton::clicked,this,&Third::back);
//货币转换
    //0人民币 1美元 2英镑 3日元
//0.1554  0.1102  16.987
//6.4367  0.7092  109.34
//9.0757  1.41  154.1694
//0.0589  0.0091  0.006486
    connect(ui->equal1,&QPushButton::clicked,[=](){
        QString string=ui->line1->text();
        double num=string.toDouble();//左边框中的数
        int i=ui->xlk1->currentIndex();//左侧下拉框的index
        int j=ui->xlk2->currentIndex();//右侧下拉框的index
        if(i==j)ui->line2->setText(QString::number(num,'f',3));
        if(i==0){
            if(j==1)ui->line2->setText(QString::number(num*0.1554,'f',4));
            if(j==2)ui->line2->setText(QString::number(num*0.1102,'f',4));
            if(j==3)ui->line2->setText(QString::number(num*16.987,'f',4));
        }
        if(i==1){
            if(j==0)ui->line2->setText(QString::number(num*6.4367,'f',4));
            if(j==2)ui->line2->setText(QString::number(num*0.7092,'f',4));
            if(j==3)ui->line2->setText(QString::number(num*109.34,'f',4));
        }
        if(i==2){
            if(j==0)ui->line2->setText(QString::number(num*9.0757,'f',4));
            if(j==1)ui->line2->setText(QString::number(num*1.41,'f',4));
            if(j==3)ui->line2->setText(QString::number(num*154.1694,'f',4));
        }
        if(i==3){
            if(j==0)ui->line2->setText(QString::number(num*0.0589,'f',4));
            if(j==1)ui->line2->setText(QString::number(num*0.0091,'f',4));
            if(j==2)ui->line2->setText(QString::number(num*0.006486,'f',4));
        }
    });
    ui->line1->setTextMargins(10,0,0,0);
    ui->line2->setTextMargins(10,0,0,0);
    ui->line3->setTextMargins(10,0,0,0);
    ui->line4->setTextMargins(10,0,0,0);

}

Third::~Third()
{
    delete ui;
}
void Third::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/图片/src=http___cdn.duitang.com_uploads_item_201408_23_20140823055947_8fX48.png&refer=http___cdn.duitang.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
//进制转化
void Third::on_equal1_3_clicked()
{
    QString string=ui->line3->text();
    int i=ui->xlk3->currentIndex();//左侧下拉框的index
    int j=ui->xlk4->currentIndex();//右侧下拉框的index
    if(i==j)ui->line4->setText(string);
    if(i==2){
        int num=string.toInt();//获取十进制数
        if(j==0){
            string=string.setNum(num,2);
            ui->line4->setText(string);
        }
        if(j==1){
            string=string.setNum(num,8);
            ui->line4->setText(string);
        }
        if(j==3){
            string=string.setNum(num,16);
            ui->line4->setText(string);
        }
    }
    if(i==0){
        int length=string.size();int sum=0,ji=1,a[length];
        while(length-1){
            ji*=2;length--;}
        for(int i=0;i<string.size();i++){
            a[i]=string[i].toLatin1()-'0';//将string[i]转换为char类型，qt要注意类型转换
            a[i]*=ji;
            ji/=2;
            sum+=a[i];//sum获取十进制值
        }
        if(j==1){
            string=string.setNum(sum,8);
            ui->line4->setText(string);
        }
        if(j==2){
            string=string.setNum(sum);
            ui->line4->setText(string);
        }
        if(j==3){
            string=string.setNum(sum,16);
            string=string.toUpper();//转大写字母输出
            ui->line4->setText(string);
        }
    }
    if(i==1){
        int length=string.size();int sum=0,ji=1,a[length];
        while(length-1){
            ji*=8;length--;}
        for(int i=0;i<string.size();i++){
            a[i]=string[i].toLatin1()-'0';//将string[i]转换为char类型，qt要注意类型转换
            a[i]*=ji;
            ji/=8;
            sum+=a[i];//sum获取十进制值
        }
        if(j==0){
            string=string.setNum(sum,2);
            ui->line4->setText(string);
        }
        if(j==2){
            string=string.setNum(sum);
            ui->line4->setText(string);
        }
        if(j==3){
            string=string.setNum(sum,16);
            string=string.toUpper();//转大写字母输出
            ui->line4->setText(string);
        }
    }
    if(i==3){
        int length=string.size();int sum=0,ji=1,a[length];
        while(length-1){
            ji*=16;length--;}
        for(int i=0;i<string.size();i++){
            a[i]=string[i].toLatin1()-'0';//将string[i]转换为char类型，qt要注意类型转换
            a[i]*=ji;
            ji/=16;
            sum+=a[i];//sum获取十进制值
        }
        if(j==0){
            string=string.setNum(sum,2);
            ui->line4->setText(string);
        }
        if(j==1){
            string=string.setNum(sum,8);
            ui->line4->setText(string);
        }
        if(j==2){
            string=string.setNum(sum);
            string=string.toUpper();//转大写字母输出
            ui->line4->setText(string);
        }
    }
}
//时区转换 0北京 1美国  2英国
void Third::on_equal1_2_clicked()
{
    QString string=ui->lineEdit_5->text();
    int a=(string[0].toLatin1()-'0')*10+(string[1].toLatin1()-'0');
    int b=(string[3].toLatin1()-'0')*10+(string[4].toLatin1()-'0');
    int i=ui->xlk5->currentIndex();//左侧下拉框的index
    int j=ui->xlk6->currentIndex();//右侧下拉框的index
    if(i==j)ui->lineEdit_6->setText(string);
    if(i==0){
        if(j==1){
            a-=12;  if(a<0)a+=24;
            string[0]=a/10+'0';
            string[1]=a%10+'0';
            ui->lineEdit_6->setText(string);
        }
        if(j==2){
            a-=7;  if(a<0)a+=24;
            string[0]=a/10+'0';
            string[1]=a%10+'0';
            ui->lineEdit_6->setText(string);
        }
    }
    if(i==1){
        if(j==0){
            a+=12; a%=24;
            string[0]=a/10+'0';
            string[1]=a%10+'0';
            ui->lineEdit_6->setText(string);
        }
        if(j==2){
            a+=5;  if(a<0)a+=24;
            string[0]=a/10+'0';
            string[1]=a%10+'0';
            ui->lineEdit_6->setText(string);
        }
    }
    if(i==2){
        if(j==1){
            a-=5;  a%=24;
            string[0]=a/10+'0';
            string[1]=a%10+'0';
            ui->lineEdit_6->setText(string);
        }
        if(j==0){
            a+=7;  a%=24;
            string[0]=a/10+'0';
            string[1]=a%10+'0';
            ui->lineEdit_6->setText(string);
        }
    }
}
