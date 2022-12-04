#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Delay{
    public:
    void delay(int millisecondsToWait);
};

class MainWindow : public QMainWindow,Delay
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void dda(float,float,float,float);
    void scanfill();
//    void delay(int n);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int ver,a[20],b[20],i,xi[20];
    float dx,dy,slope[100];
    bool start;
};
#endif // MAINWINDOW_H
