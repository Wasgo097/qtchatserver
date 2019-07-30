#ifndef CHAT_H
#define CHAT_H
#include <QDialog>
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
namespace Ui {
class Chat;
}
class Chat : public QDialog
{
    Q_OBJECT
public:
    explicit Chat(QString ip,QString port,QString nick,QWidget *parent = nullptr);
    ~Chat();
private slots:
    void on_send_clicked();
    void newConnection();
    void readyRead();
private:
    QTcpSocket * socket{nullptr};
    QTcpServer * server{nullptr};
private:
    Ui::Chat *ui;
    QString ip{""};
    QString port{""};
    QString nick{""};
};
#endif // CHAT_H
