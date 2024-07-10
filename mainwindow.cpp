#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->username->setPlaceholderText("Enter your username");
    ui->password->setPlaceholderText("Enter your password");
    ui->Password->setPlaceholderText("Enter your password");
    ui->Username->setPlaceholderText("Enter your username");
    ui->mail->setPlaceholderText("Enter your email");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signpush_clicked()
{
    //connection
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("file name");



    if (database.open()){

        //retreive Data from input fields
        QString username = ui->Username->text();
        QString password = ui->Password->text();
        QString email = ui->mail->text();

        //run our insert
        QSqlQuery qry ;
        qry.prepare("insert into user (username , password , email)"
                    "values (:username, :password ,:email)");
        qry.bindValue(":username",username);
        qry.bindValue(":password",password);
        qry.bindValue(":email",email);

        if (qry.exec()){
            QMessageBox::information(this,"inserted","data inserted susscesfully");
        }
    }

    else{
        QMessageBox::information(this,"not connected","database is not connected ");
    }
}


void MainWindow::on_logpush_clicked()
{
    QSqlDatabase db ;
    //connection
    database = QSqlDatabase::addDatabase("QMYSQL","Myconnect");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("file name");

    //retrieve data from fields
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (db.open()){
        //creating quereis
        //QMessageBox::information(this,"database succeed", "database connction succeed");
        QSqlQuery query(QSqlDatabase::database("connection name"));
        query.prepare(QString("select * from table_name where username = :username and passwrod = :password"));
        query.bindValue(":username",username);
        query.bindValue(":password" , password);

        if(!query.exec()){
            QMessageBox::information (this,"Failed","Query Failed to Run");
        }
        else{
            while(query.next()){
                QString usernameFromDB = query.value(1).toString();
                QString passwordFromDB = query.value(2).toString();
                //check this value with input field
                if(usernameFromDB == username && passwordFromDB == password){
                    QMessageBox::information (this,"success" , "Login succeed");
                    MDialog Menue ;
                    Menue.setModal(true);
                    Menue.exec();


                }
                else {
                    QMessageBox::information(this , "Failed","Login Failed");
                }
            }
        }

    }

    else {
        QMessageBox::information(this,"database failed", "database connction failed");
    }

}

