// #include <QTcpServer>
// #include <QTcpSocket>
// #include <QString>
// #include <QDebug>
// #include <QCoreApplication>
#include <string>

using namespace std;

typedef struct gameRecord
{
    int status;
    string opponentEmail;
} gameRecord;

class Player
{
private:
    string username;
    string email;
    string hPassword;
    gameRecord last3[3];
    int gameRecNum;

public:
    Player(string u, string e, string hp) : username(u), email(e), hPassword(hp), gameRecNum(0) {}
    string getUser()
    {
        return username;
    }
    string getEmail()
    {
        return email;
    }
    string getHPass()
    {
        return hPassword;
    }
    void setGameRec(int s, string o)
    {
        last3[gameRecNum].status = s;
        last3[gameRecNum].opponentEmail = o;
        gameRecNum++;
        gameRecNum %= 3;
    }
    gameRecord getLast(int i)
    {
        return last3[i % 3];
    }
    int getGameRecNum()
    {
        return gameRecNum;
    }
};

class Question
{
protected:
    int id;
    string questionText;
    string category;

public:
    Question(int i, string q, string c) : id(i), questionText(q), category(c) {}
    int getId()
    {
        return id;
    }
    string getQuestion()
    {
        return questionText;
    }
    string getCategory()
    {
        return category;
    }
};

class Multiple : public Question
{
protected:
};

class Short : public Question
{
protected:
    string answer;

public:
    Short(int i, string q, string c, string a) : Question(i, q, c), answer(a) {}
    string getAnswer()
    {
        return answer;
    }
};

class Number : public Question
{
protected:
    int answer;

public:
    Number(int i, string q, string c, int a) : Question(i, q, c), answer(a) {}
    int getAnswer()
    {
        return answer;
    }
};

class Box
{
private:
    int component;
    int qType;
    int cType;
    int file;
    int row;

public:
    Box(int c, int q, int ct, int f, int r) : component(c), qType(q), cType(ct), file(f), row(r) {}
    int getComponent()
    {
        return component;
    }
    void setComponent(int c)
    {
        component = c;
    }
    int getQ()
    {
        return qType;
    }
    int getC()
    {
        return cType;
    }
    int getFile()
    {
        return file;
    }
    int getRow()
    {
        return row;
    }
};

class Game
{
private:
    Player plyr1;
    Player plyr2;
};

int main()
{

    return 0;
}
