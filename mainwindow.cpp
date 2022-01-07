#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(&socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));

    socket.open(QUrl("ws://192.168.0.134:28081"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnected(){
    connect(&socket, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));
    qDebug() << "connected..";

    socket.sendTextMessage("asdf");
}

void MainWindow::onDisconnected(){

}

void MainWindow::onTextMessageReceived(QString message){
    qDebug() << message;
}
