#include <iostream>
#include <cstdlib>
#include <string>
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
enum enOptionsPlay
{
    Stock = 1,
    Pepar=2,
    Scisser=3,
};
short RandomOPotionsComputer(short From, short To) {
    return rand() % (To - From +1) + From;
}
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
        if (Number <= 3 || Number >= 1) {
            cin >> Number;
        }
        else
        {
            cout << "Number Not Vaild  ";
            Number = 0;
        }
    } while (Number<=0);
    return Number;
}
void CheckWiner(int NumberRound , short &PlayerWiner , short &ComputerWiner) {
    short ChooseComputer = RandomOPotionsComputer(1, 3);
    short ChooseUser = ReadChooseUser();
    if (ChoosePlay(ChooseComputer) == ChoosePlay(ChooseUser))
    {
        cout << "-----------------Round[" << NumberRound << "]--------------------------\n";
        system("color 0E");
        cout << "Player Choice: " << Choices(ChoosePlay(ChooseUser)) << endl;
        cout << "Computer Choice: " << Choices(ChoosePlay(ChooseComputer)) << endl;
        cout << "Round Winner: " << "[No Winner]" << endl;
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
void StartGame() {
    short N = ReadNumberRound();
    short ComputerWiner=0, PlayerWiner = 0;
    for (int i = 0; i < N; i++)
    {
        CheckWiner(i+1 , PlayerWiner , ComputerWiner);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();

 
}
