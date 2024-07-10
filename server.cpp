// #include <QTcpServer>
// #include <QTcpSocket>
// #include <QString>
// #include <QDebug>
// #include <QCoreApplication>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

typedef struct gameRecord
{
    int status; // 0 : D, 1 : W, 2 : L
    string opponentUser;
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
        last3[gameRecNum].opponentUser = o;
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
    virtual void setOption(int, string) {};
    virtual string getOption(int)
    {
        return "";
    }
    virtual string getAnswer()
    {
        return "";
    }
    virtual int getnAnswer()
    {
        return 0;
    }
};

class Multiple : public Question
{
protected:
    string option[4];
    string answer;

public:
    Multiple(int i, string q, string c, string a) : Question(i, q, c), answer(a) {}
    void setOption(int i, string o)
    {
        option[i] = o;
    }
    string getOption(int i)
    {
        return option[i];
    }
    string getAnswer()
    {
        return answer;
    }
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
    int getnAnswer()
    {
        return answer;
    }
};

typedef struct Box
{
    int component; // 0 : - , 1 : X, 2 : O, 3 : ...
    int cType;     // 1 : Normal, 2 : Bomb, 3 : Treasure
    int qType;     // 1 : Multiple, 2 : Short, 3 : Number
    int row;
    int column;
} Box;

class Game
{
private:
    Player *plyr1;
    Player *plyr2;
    Box bx[3][3];
    int winner; // 0 : neither, 1 : Player 1, 2 : Player 2, 3 : Tie
    public:
    Game(Player *p1, Player *p2) : plyr1(p1), plyr2(p2), winner(0)
    {
        vector<int> vec = {1, 1, 1, 2, 3, 4, 4, 5, 6};
        int r;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                bx[i][j].component = 0;
                bx[i][j].row = i;
                bx[i][j].column = j;
                r = rand() % vec.size();
                switch (vec[r])
                {
                case 1:
                    bx[i][j].cType = 1;
                    bx[i][j].qType = 1;
                    break;
                case 2:
                    bx[i][j].cType = 1;
                    bx[i][j].qType = 2;
                    break;
                case 3:
                    bx[i][j].cType = 1;
                    bx[i][j].qType = 3;
                    break;
                case 4:
                    bx[i][j].cType = 2;
                    bx[i][j].qType = 1;
                    break;
                case 5:
                    bx[i][j].cType = 2;
                    bx[i][j].qType = 2;
                    break;
                case 6:
                    bx[i][j].cType = 3;
                    bx[i][j].qType = 1;
                    break;
                default:
                    break;
                }
                vec.erase(vec.begin() + r);
            }
        }
    }
    Question &downloadQuestion(int i, int j)
    {
        int id;
        string questionText;
        string category;
        string type;
        switch (bx[i][j].qType)
        {
        case 1:
            type = "multiple";
            break;
        case 2:
            type = "short";
            break;
        case 3:
            type = "number";
            break;
        default:
            break;
        }
        cout << "id : " << endl;
        cin >> id;
        cout << "questionText : " << endl;
        cin >> questionText;
        cout << "category : " << endl;
        cin >> category;
        Question *quest;
        if (type == "multiple")
        {
            string option[4];
            string answer;
            cout << "option 1 : " << endl;
            cin >> option[0];
            cout << "option 2 : " << endl;
            cin >> option[1];
            cout << "option 3 : " << endl;
            cin >> option[2];
            cout << "option 4 : " << endl;
            cin >> option[3];
            cout << "answer : " << endl;
            cin >> answer;
            quest = new Multiple(id, questionText, category, answer);
            quest->setOption(0, option[0]);
            quest->setOption(1, option[1]);
            quest->setOption(2, option[2]);
            quest->setOption(3, option[3]);
        }
        else if (type == "short")
        {
            string answer;
            cout << "answer : " << endl;
            cin >> answer;
            quest = new Short(id, questionText, category, answer);
        }
        else if (type == "number")
        {
            int answer;
            cout << "answer : " << endl;
            cin >> answer;
            quest = new Number(id, questionText, category, answer);
        }
        return *quest;
    }

    int getWinner()
    {
        return winner;
    }
    void setWinner(int w)
    {
        winner = w % 4;
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    return 0;
}
