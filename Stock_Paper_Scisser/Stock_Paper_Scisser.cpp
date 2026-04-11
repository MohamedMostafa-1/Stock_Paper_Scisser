#include <iostream>
#include <cstdlib>
#include <string>
void StartGame();
using namespace std;

short ReadNumberRound() {
    short Number =0;
    do
    {
        cout << "Please Enter How Many Round You Want To Play? ";
        cin >> Number;
    } while (Number ==0);
    return Number;
}
short RandomOPotionsComputer(short From, short To) {
    return rand() % (To - From +1) + From;
}

enum enOptionsPlay
{
    Stock = 1,
    Pepar=2,
    Scisser=3,
};
enOptionsPlay ChoosePlay (short Num) {
    switch (Num) {
    case 1:
        return enOptionsPlay::Stock;
    case 2:
        return enOptionsPlay::Pepar;
    case 3:
        return enOptionsPlay::Scisser;
    default:
        return enOptionsPlay::Stock;
    }
}

string Choices(enOptionsPlay Option) {
    switch (Option) {
    case enOptionsPlay::Stock:
        return "Stock";
    case enOptionsPlay::Pepar:
        return "Pepar";
    case enOptionsPlay::Scisser:
        return "Scisser";
    default:
        return "Unknown";
    }
}
int ReadChooseUser() {
    int Number = 0;
    do
    {
        cout << "\nPlease Enter Your Option Stock(1)/Papar(2)/Scisser(3): ";
        cin >> Number;
        if (Number > 3 || Number < 1) {
            cout << "Number Not Vaild  ";
            Number = 0;
        }

    } while (Number<=0);
    return Number;
}

void CheckWiner(int NumberRound , short &PlayerWiner , short &ComputerWiner , short &Draw) {
    enOptionsPlay ChooseComputer = ChoosePlay(RandomOPotionsComputer(1, 3));
    enOptionsPlay ChooseUser = ChoosePlay(ReadChooseUser());
    if (ChooseComputer ==ChooseUser)
    {
        cout << "-----------------Round[" << NumberRound << "]--------------------------\n";
        system("color 6F");
        cout << "Player Choice: " << Choices(ChoosePlay(ChooseUser)) << endl;
        cout << "Computer Choice: " << Choices(ChoosePlay(ChooseComputer)) << endl;
        cout << "Round Winner: " << "[No Winner]" << endl;
        Draw++;
    }
    else if((ChooseUser ==1 && ChooseComputer==3)|| (ChooseUser == 2 && ChooseComputer == 1) || (ChooseUser == 3 && ChooseComputer == 2)) {
         cout << "-----------------Round[" << NumberRound << "]--------------------------\n";
            system("color 2F");
            cout << "Player Choice: " << Choices(ChoosePlay(ChooseUser)) << endl;
            cout << "Computer Choice: " << Choices(ChoosePlay(ChooseComputer)) << endl;
            cout << "Round Winner: " << "Player" << endl;
            PlayerWiner++;
    }
    else
    {
        cout << "-----------------Round[" << NumberRound << "]--------------------------\n\a";
        system("color 4F");
        cout << "Player Choice: " << Choices(ChoosePlay(ChooseUser)) << endl;
        cout << "Computer Choice: " << Choices(ChoosePlay(ChooseComputer)) << endl;
        cout << "Round Winner: " << "Computer" << endl;
        ComputerWiner++;
    }
}
string FinalWinner(short PlayerWiner, short ComputerWiner) {
    if (PlayerWiner == ComputerWiner) {
        return "Not Winner\n";
        system("color 6F");
    }
    else if (PlayerWiner > ComputerWiner) {
        return "Player is won\n";
        system("color 2F");
    }
    else {
        return "Coputer is won\n";
        system("color 4F");
    }
}
void PlayAgain() {
    cout << "Do you want to play again? Y(1)/N(0)? ";
    bool Again = false;
    cin >> Again;
    if (Again)
    {
        StartGame();
    }
}
void GameOver(short NumberRounds, short PlayerWiner, short ComputerWiner, short Draw) {
    cout << "\n__________________________________________________________\n";
    cout << "\n                 +++ G a m e  O v e r +++                  \n";
    cout << "\n__________________________________________________________\n";
    cout << "\n_____________________[Game Results]________________________\n";
    cout << "Game Rounds         : " << NumberRounds << endl;
    cout << "Player Won Times    : " << PlayerWiner << endl;
    cout << "Computer Won Times  : " << ComputerWiner << endl;
    cout << "Draw Times          : " << Draw << endl;
    cout << "Final Winner        : " << FinalWinner(PlayerWiner , ComputerWiner) << endl;
    cout << "\n__________________________________________________________\n";
    PlayAgain();
}

void StartGame() {
    short N = ReadNumberRound();
    short ComputerWiner=0, PlayerWiner = 0 , Draw=0;
    for (int i = 0; i < N; i++)
    {
        CheckWiner(i+1 , PlayerWiner , ComputerWiner , Draw);
    }
    GameOver(N , PlayerWiner , ComputerWiner , Draw);
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();

 
}
