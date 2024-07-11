#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <memory>

using namespace std;

typedef struct gameRecord
{
    int status = 0; // 0 : D, 1 : W, 2 : L
    string opponentUser = "No one";
} gameRecord;

class Player
{
private:
    string username;
    string email;
    int hPassword; // Hashed Password
    gameRecord last3[3];
    int gameRecNum;

public:
    Player(string u, string e, int hp) : username(u), email(e), hPassword(hp), gameRecNum(0) {}
    string getUser() const
    {
        return username;
    }
    string getEmail() const
    {
        return email;
    }
    int getHPass() const
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
    gameRecord getLast(int i) const
    {
        return last3[i % 3];
    }
    int getGameRecNum() const
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
    Question(int i, const string &q, const string &c) : id(i), questionText(q), category(c) {}
    virtual ~Question() = 0;
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
    virtual void setOption(int, const string &) {}
    virtual string getOption(int) const
    {
        return "";
    }
    virtual string getAnswer() const
    {
        return "";
    }
    virtual int getnAnswer() const
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
    Multiple(int i, const string &q, const string &c, const string &a) : Question(i, q, c), answer(a) {}
    void setOption(int i, const string &o)
    {
        if (i >= 0 && i < 4)
            option[i] = o;
    }
    string getOption(int i) const
    {
        return (i >= 0 && i < 4) ? option[i] : "";
    }
    string getAnswer() const
    {
        return answer;
    }
};

class Short : public Question
{
protected:
    string answer;

public:
    Short(int i, const string &q, const string &c, const string &a) : Question(i, q, c), answer(a) {}
    string getAnswer() const
    {
        return answer;
    }
};

class Number : public Question
{
protected:
    int answer;

public:
    Number(int i, const string &q, const string &c, int a) : Question(i, q, c), answer(a) {}
    int getnAnswer() const
    {
        return answer;
    }
};

typedef struct Box
{
    int component; // 0 : -, 1 : X, 2 : O, 3 : ...
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
    unique_ptr<Question> downloadQuestion(int i, int j)
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
        cin.ignore();
        cout << "questionText : " << endl;
        getline(cin, questionText);
        cout << "category : " << endl;
        getline(cin, category);
        unique_ptr<Question> quest;
        if (type == "multiple")
        {
            string option[4];
            string answer;
            cout << "option 1 : " << endl;
            getline(cin, option[0]);
            cout << "option 2 : " << endl;
            getline(cin, option[1]);
            cout << "option 3 : " << endl;
            getline(cin, option[2]);
            cout << "option 4 : " << endl;
            getline(cin, option[3]);
            cout << "answer : " << endl;
            getline(cin, answer);
            quest = make_unique<Multiple>(id, questionText, category, answer);
            static_cast<Multiple *>(quest.get())->setOption(0, option[0]);
            static_cast<Multiple *>(quest.get())->setOption(1, option[1]);
            static_cast<Multiple *>(quest.get())->setOption(2, option[2]);
            static_cast<Multiple *>(quest.get())->setOption(3, option[3]);
        }
        else if (type == "short")
        {
            string answer;
            cout << "answer : " << endl;
            getline(cin, answer);
            quest = make_unique<Short>(id, questionText, category, answer);
        }
        else if (type == "number")
        {
            int answer;
            cout << "answer : " << endl;
            cin >> answer;
            quest = make_unique<Number>(id, questionText, category, answer);
        }
        return quest;
    }
    void checkGame()
    {
        for (int i = 0; i < 3; i++)
        {
            if (bx[i][0].component == bx[i][1].component && bx[i][1].component == bx[i][2].component)
            {
                if (bx[i][0].component == 1)
                    winner = 1;
                else if (bx[i][0].component == 2)
                    winner = 2;
            }
            if (bx[0][i].component == bx[1][i].component && bx[1][i].component == bx[2][i].component)
            {
                if (bx[0][i].component == 1)
                    winner = 1;
                else if (bx[0][i].component == 2)
                    winner = 2;
            }
        }
        if (bx[0][0].component == bx[1][1].component && bx[1][1].component == bx[2][2].component)
        {
            if (bx[0][0].component == 1)
                winner = 1;
            else if (bx[0][0].component == 2)
                winner = 2;
        }
        if (bx[0][2].component == bx[1][1].component && bx[1][1].component == bx[2][0].component)
        {
            if (bx[0][2].component == 1)
                winner = 1;
            else if (bx[0][2].component == 2)
                winner = 2;
        }
    }
    void displayGame()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " ";
                switch (bx[i][j].component)
                {
                case 0:
                    cout << "-";
                    break;
                case 1:
                    cout << "X";
                    break;
                case 2:
                    cout << "O";
                    break;
                case 3:
                    cout << ".";
                    break;

                default:
                    break;
                }
            }
            cout << endl;
        }
    }
    int getWinner() const
    {
        return winner;
    }
    void setWinner(int w)
    {
        winner = w % 4;
    }
};

unsigned int hashPassword(const string &password)
{
    unsigned int hashedPass = 0;
    for (char c : password)
    {
        hashedPass = hashedPass * 31 + static_cast<unsigned int>(c);
    }
    return hashedPass;
}

void signupLogin()
{
    cout << "Player 1\n\n"
         << "1. Log in\n"
         << "2. Sign up\n";
}

void loggedIn(const Player &plyr)
{
    cout << "Hey " << plyr.getUser() << endl
         << endl;
    cout << "Last 3 Matches : " << endl;
    for (int i = 2; i >= 0; i--)
    {
        switch (plyr.getLast(plyr.getGameRecNum() + i).status)
        {
        case 0:
            cout << "D " << plyr.getLast(plyr.getGameRecNum() + i).opponentUser << endl;
            break;
        case 1:
            cout << "W " << plyr.getLast(plyr.getGameRecNum() + i).opponentUser << endl;
            break;
        case 2:
            cout << "L " << plyr.getLast(plyr.getGameRecNum() + i).opponentUser << endl;
            break;
        default:
            break;
        }
    }
    cout << "\nPress 1 to if you're ready!\n";
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Player plyr1("me", "me@gmail.com", 1234);
    Player plyr2("you", "you@gmail.com", 5432);
    int choice;
    signupLogin();
    cin >> choice;
    system("cls");
    loggedIn(plyr1);
    cin >> choice;
    system("cls");
    Game game1(&plyr1, &plyr2);
    game1.displayGame();
    cin >> choice;


    return 0;
}
