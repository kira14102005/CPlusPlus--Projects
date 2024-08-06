#include "/HeaderFile/file.h"
using namespace std;
class tictactoe
{
public:
    string base;
    string p1;
    string p2;
    int choice;
    int row, col;
    bool turn;
    bool draw;

    tictactoe(string p1 = "Player1", string p2 = "Player2") //CONSTRUCTOR
    {
        this->base = "123456789";
        this->draw = false;
        this->p1 = p1;
        this->p2 = p2;
        this->turn = true;
        this->row = -1;
        this->col = -1;
    }
    void show()     //FUNCTION TO DISPLAY THE BOARD AFTER CHANGES
    {
        cout << "\t     |     |     " << endl;
        cout << "\t  " << base[0] << "  |  " << base[1] << "  |  " << base[2] << endl;
        cout << "\t_____|_____|_____" << endl;
        cout << "\t     |     |     " << endl;
        cout << "\t  " << base[3] << "  |  " << base[4] << "  |  " << base[5] << endl;
        cout << "\t_____|_____|_____" << endl;
        cout << "\t     |     |     " << endl;
        cout << "\t  " << base[6] << "  |  " << base[7] << "  |  " << base[8] << endl;
        cout << "\t     |     |     " << endl;
        cout<<endl;
    }
    void player_turn()  //FUNCTION TO TAKE PLAYER TURNS
    {
        if (turn)
        {
            cout << "\tPlayer - 1 " << p1 << " turn : ";
        }
        else
        {
            cout << "\tPlayer - 2 " << p2 << " turn : ";
        }
        cin >> choice;

        for (int i = 1; i < 10; i++)
        {
            row = (i - 1) / 3;
            col = (i - 1) % 3;
        }
        int idx = choice - 1;

        if (turn && base[idx] != 'X' && base[idx] != '0')
            base[idx] = 'X';

        else if (!turn && base[idx] != 'X' && base[idx] != '0')
            base[idx] = '0';
        else
        {
            cout << "\tBox already filled!\n Please choose another!!" << endl;
            player_turn();
        }
        turn = !turn;
        show();
    }

    bool gameover() //FUNCTION TO MARK GAME IS STILL FINISHED OR NOT
    {
        int k = 0;
        int j = 0;
        for (int i = 0; i < 3; i++)
        {
            if (base[k] == base[k + 1] && base[k + 1] == base[k + 2])
                return false;
            k += 3;
            if (base[j] == base[j + 3] && base[j + 3] == base[j + 6])
                return false;
            k++;
        }

        if (base[0] == base[4] && base[4] == base[8] || base[2] == base[4] && base[4] == base[6])
            return false;

        for (int i = 0; i < 9; i++)
            if (base[i] != 'X' && base[i] != '0')
                return true;

        draw = true;
        return false;
    }
};

int main()
{
    cout << "\tT I C  -- T A C -- T O E -- G A M E\n";
    cout << endl;
    string p1, p2;
    cout << "\tEnter the name of Player-1: ";
    cin >> p1;
    cout<<endl;
    cout << "\tEnter the name of Player-2: ";
    cin >> p2;
    cout<<endl;
    tictactoe *gm = new tictactoe(p1, p2);
    gm->show();
    while (gm->gameover())
    {
        gm->player_turn();
        gm->gameover();
    }
    if (gm->draw)
        cout << "\n\tGAME DRAWW!!" << endl;
    else if (!gm->turn)
        cout << "\n\tCongratulations! Player-1  : " << gm->p1 << " has won the game\n";
    else
        cout << "\n\tCongratulations! Player-2 : " << gm->p2 << " has won the game\n";
}
