#include "chat.h"
#include "ui_chat.h"
#include <QDebug>
Chat::Chat(QString ip,QString port,QString nick,QWidget *parent) :
    QDialog(parent),ui(new Ui::Chat){
    ui->setupUi(this);
    this->ip=ip;
    this->port=port;
    this->nick=nick;
    server=new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,port.toUShort())){
        ui->chat->append("Server not start");
    }
    else{
        ui->chat->append("Server start");
    }
}
Chat::~Chat(){
    delete ui;
    socket->close();
}
void Chat::on_send_clicked(){
    QString fullmess=nick+": "+ui->message->toPlainText();
    ui->chat->append(fullmess);
    ui->message->setText("");
    QByteArray mess=(fullmess+"\r\n").toLocal8Bit();
    const char * fullmes=mess.data();
    socket->write(fullmes);
    socket->flush();
    socket->waitForBytesWritten(2000);
}
void Chat::newConnection(){
    ui->chat->append("New connection");
    socket=server->nextPendingConnection();
    socket->write("Connection succesful\r\n");
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    socket->flush();
    socket->waitForBytesWritten(3000);
}
void Chat::readyRead(){
//    while(socket->canReadLine()){
//        ui->chat->append(socket->readLine().trimmed());
//    }
}
