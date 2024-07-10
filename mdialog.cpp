#include "mdialog.h"
#include "ui_mdialog.h"

MDialog::MDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MDialog)
{
    ui->setupUi(this);
}

MDialog::~MDialog()
{
    delete ui;
}
