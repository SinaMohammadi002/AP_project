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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_signpush_clicked();

    void on_logpush_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database ;
};
#endif // MAINWINDOW_H
