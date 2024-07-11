#include "maingame.h"
#include "ui_maingame.h"
#include"mainwindow.h"

mainGame::mainGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainGame)
{
    ui->setupUi(this);

    QString Jsonpath = "jsontest.json";
    QFile file (Jsonpath);
    if (file.open(QIODevice::ReadOnly)){
        QByteArray data = file.readAll();
        file.close();
        QJsonParseError Jsonerror ;
        QJsonDocument Document = QJsonDocument::fromJson(data,&Jsonerror);
        if (Jsonerror.error != QJsonParseError::NoError){
            qDebug() << "Error in Json Data : " << Jsonerror.errorString();
            return ;
        }
    else {
        if (Document.isObject()){
            QJsonObject obj = Document.object();
            for (int i =0 ; i < 3 ; i++){
                for(int j =0 ; j < 3 ; j++){
            int status = obj.value("copponent").toInt();
            switch (status){
            case 0 :
                ui->place1->setPlainText("-");
                break ;
            case 1 :
                ui->place1->setPlainText("X");
                break ;
            case 2 :
                ui->place1->setPlainText("O");
                break;
            case 3 :
                ui->place1->setPlainText("...");
                break ;
            default :
                ui->place1->setPlainText("-");
            }

            }
        }
        }
        }
    int place[3][3];
    // for (int i =0 ; i < 3 ; i++){
    //     for(int j =0 ; j < 3 ; j++){

    //     }
    // }
    }
}

mainGame::~mainGame()
{
    delete ui;
}
