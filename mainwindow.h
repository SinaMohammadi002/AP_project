#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<Qtsql>
#include<QSqlDatabase>
#include<QMessageBox>
#include"MDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase database ;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connClose (){
        database.close ();
        database.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        database =QSqlDatabase::addDatabase("connection type");
        database.setDatabaseName("address of database");

        if (!database.open ()){
            return false ;
        }
        else {
            return true ;
        }
    }

private slots:
    void on_signpush_clicked();

    void on_logpush_clicked();

private:
    Ui::MainWindow *ui;
    //QSqlDatabase database ;
};
#endif // MAINWINDOW_H
