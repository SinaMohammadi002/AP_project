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

private:
    Ui::MDialog *ui;
};

#endif // MDIALOG_H
