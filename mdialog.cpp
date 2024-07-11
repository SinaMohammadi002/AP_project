#include "mdialog.h"
#include "ui_mdialog.h"
#include"mainwindow.h"


MDialog::MDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MDialog)
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
                QString name = obj.value("username").toString();
                QString mail = obj.value("email").toString();
                QString Enemy1 = obj.value("opponent1").toString();
                QString Enemy2 = obj.value("opponent2").toString();
                QString Enemy3 = obj.value("opponent3").toString();
                QString status1 = obj.value("statues1").toString();
                QString status2 = obj.value("statues2").toString();
                QString status3 = obj.value("statues3").toString();
                ui->Playerusername->setPlainText(name);
                ui->Playeremail->setPlainText(mail);
                ui->Enemy1N->setPlainText(Enemy1);
                ui->Enemy2N->setPlainText(Enemy2);
                ui->Enemy3N->setPlainText(Enemy3);
                ui->statues1->setPlainText(status1);
                ui->statues2->setPlainText(status2);
                ui->statues3->setPlainText(status3);
            }
        }
    }
}

MDialog::~MDialog()
{
    delete ui;
}




// void MDialog::on_pushButton_clicked()
// {

//     // MainWindow conn ;
//     // QSqlQueryModel * modal = new QSqlQueryModel();

//     // conn.connOpen();
//     // QSqlQuery * qry=new QSqlQuery(conn.database);
//     // qry->prepare("select * from tabel_name");
//     // qry->exec();
//     // modal->setQuery(*qry);
//     // ui->tableView->setModel(modal);
//     // conn.connClose();


// }





void MDialog::on_startpush_clicked()
{

}

