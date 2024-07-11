#ifndef MDIALOG_H
#define MDIALOG_H

#include <QDialog>


namespace Ui {
class MDialog;
}

class MDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MDialog(QWidget *parent = nullptr);
    ~MDialog();

private slots:
    void on_usernameinfo_copyAvailable(bool b);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MDialog *ui;
};

#endif // MDIALOG_H
