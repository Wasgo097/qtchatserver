#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->lbl_ip->hide();
    ui->ip->hide();
}
MainWindow::~MainWindow(){
    delete ui;
    if(chat!=nullptr)delete chat;
}
void MainWindow::on_connect_clicked(){
    chat= new Chat(ui->ip->text(),ui->port->text(),ui->nick->text());
    chat->show();
    this->hide();
}
