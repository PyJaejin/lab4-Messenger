#include "widget.h"
#include "ui_widget.h"
#include <QRegExp>
#include <QTcpSocket>
#include <stdlib.h>
#include <string.h>
#include <QProcess>
#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setLayout(ui->gridLayout);
    setWindowTitle("Chatting Client");
}

Widget::~Widget()
{
    delete ui;
    delete socket;
}

void Widget::readyRead()
{
    while(socket->canReadLine())
    {
        QString line=QString::fromUtf8(socket->readLine());
        line=line.left(line.length()-1);
        ui->listWidget->addItem(QString("%2").arg(line));
    }
    ui->listWidget->scrollToBottom();
}


void Widget::on_connectButton_clicked()
{
    socket=new QTcpSocket(this);

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
}

void Widget::on_sendButton_clicked()
{
    QString message=ui->messageLineEdit->text().trimmed();

    if(!message.isEmpty())
    {
        socket->write(QString(message+"\n").toUtf8());
    }
}


void Widget::on_pushButton_clicked()
{
    //ipLineEdit .. File Send IP
    //fileName_edit
    QString cmd_msg, send_ip, file_name;
    file_name = "./" + ui->fileName_edit->text();
    send_ip = "/home/parallels/ftp_test";
    cmd_msg = "scp " + file_name + " " + send_ip;
    qDebug() << cmd_msg;
    QProcess::execute("cmd_msg");
    //QProcess process;
    //process.start("gedit", QStringList() << "/home/parallels/test.txt");
}
