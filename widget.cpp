#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkMoney(){
    if(money<100)ui->pbCoffee->setEnabled(false);
    else ui->pbCoffee->setEnabled(true);
    if(money<150)ui->pbTea->setEnabled(false);
    else ui->pbTea->setEnabled(true);
    if(money<200)ui->pbMilk->setEnabled(false);
    else ui->pbMilk->setEnabled(true);
}

void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);
    checkMoney();
}

void Widget::on_pbCoin10_clicked(){
    changeMoney(10);
}

void Widget::on_pbCoin50_clicked(){
    changeMoney(50);
}

void Widget::on_pbCoin100_clicked(){
    changeMoney(100);
}

void Widget::on_pbCoin500_clicked(){
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked(){
    changeMoney(-100);
}

void Widget::on_pbTea_clicked(){
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked(){
    changeMoney(-200);
}

void Widget::on_pbReset_clicked(){

    int tmpmoney=money;
    int coin[4]={0,0,0,0};
    int arr[4]={500,100,50,10};
    for(int i=0;i<4;i++){
        coin[i]=tmpmoney/arr[i];
        tmpmoney%=arr[i];
    }
    char mes[100];
    sprintf(mes,"500won : %d\n100won : %d\n50won : %d\n10won : %d\n",coin[0],coin[1],coin[2],coin[3]);

    QMessageBox mb;
    mb.information(this,"Changes",mes);

    money=0;
    changeMoney(-money);
}
