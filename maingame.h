#ifndef MAINGAME_H
#define MAINGAME_H

#include <QDialog>

namespace Ui {
class mainGame;
}

class mainGame : public QDialog
{
    Q_OBJECT

public:
    explicit mainGame(QWidget *parent = nullptr);
    ~mainGame();

private:
    Ui::mainGame *ui;
};

#endif // MAINGAME_H
