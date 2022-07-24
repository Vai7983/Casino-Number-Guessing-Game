#include <iostream>
#include <iostream>
#include <string> // we shall use strings
#include <cstdlib> // To use random numbers
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int money_available; // stores player's available money
    int money_for_betting;
    int guess_number;
    int dice_number; // To store the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> money_available;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << money_available << "\n";
// To Get player's betting money
        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : $";
            cin >> money_for_betting;
            if(money_for_betting > money_available)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(money_for_betting > money_available);
// Get player's guessing numbers
        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess_number;
            if(guess_number <= 0 || guess_number > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess_number <= 0 || guess_number > 10);
        dice_number = rand()%10 + 1;
        if(dice_number == guess_number)
        {
            cout << "\n\n Waww!! You have won Rs." << money_for_betting * 10;
            money_available = money_available + money_for_betting * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< money_for_betting <<"\n";
            money_available = money_available - money_for_betting;
        }
        cout << "\nThe winning number was : " << dice_number <<"\n";
        cout << "\n"<<playerName<<", You have balance of $ " << money_available << "\n";
        if(money_available == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << money_available << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\tCASINO NUMBER GUESSING RULES!\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
