#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMouseEvent"
#include "QColorDialog"
#include <QTimer>
#include <QTime>
#include <iostream>

using namespace std;
static QImage img(500,500,QImage :: Format_RGB888);
static QColor color;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver=0;
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start){
        int q = ev->pos().x();
        int p = ev->pos().y();
        a[ver] = q;
        b[ver] = p;
        if(ev->button() == Qt :: RightButton){
            dda(a[ver-1],b[ver-1],a[0],b[0]);
            start = false;
        }
        else{
            if(ver>0){dda(a[ver],b[ver],a[ver-1],b[ver-1]);}
        }
        ver++;
    }
}



void MainWindow::dda(float x1, float  y1, float x2, float y2)
{
    double dx,x,y,dy,len,xin,yin;
    x = x1;
    y = y1;
    img.setPixel(x,y,color.rgb());
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy)){
        len = abs(dx);
    }
    else{
        len = abs(dy);
    }
    int i = 0;
    xin = dx/len;
    yin = dy/len;
    while(i<=len){
        x = x+xin;
        y = y+yin;
        img.setPixel(x,y,color.rgb());
        i++;
    }
    ui->label->setPixmap(QPixmap ::fromImage(img));
}

void MainWindow::scanfill()
{
    int yMin = 10000000,yMax = 0,temp;
    float slope[100];
    //find yMax and yMin
    for(int i =0;i<ver;i++){
        if(b[i]>yMax)
            yMax = b[i];
        if(b[i]<yMin)
            yMin = b[i];
    }
    a[ver] = a[0];
    b[ver] = b[0];
    for(int i =0;i<ver;i++){
        dx = a[i+1]-a[i];
        dy = b[i+1]-b[i];
        if(dx==0.0)slope[i]=0.0;
        if(dy==0.0)slope[i]=1.0;
        if(dx!=0.0 && dy!=0.0){
            slope[i]=(float)dx/(float)dy;
        }
    }
    int k;
    for(int j=yMin;j<yMax;j++)
        {

            k=0;

            for(int i=0;i<ver;i++){

                if(((b[i]<=j) && (b[i+1]>j)) || ((b[i]>j) && (b[i+1]<=j))){

                    xi[k]=(int)(a[i]+(slope[i]*(j-b[i])));
                    k++;
                }
            }
            for(int m=0;m<k-1;m++){

                for(int i=0;i<k-m-1;i++){

                    if(xi[i]>xi[i+1]){

                        temp=xi[i];

                        xi[i]=xi[i+1];

                        xi[i+1]=temp;

                    }

                }
            }
            for(int i=0;i<k;i+=2){
                dda(xi[i],j,xi[i+1]+1,j);
                delay(10);
            }
    }
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    scanfill();
}

void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog :: getColor();
}




void Delay::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
        while (QTime::currentTime() < dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
}
