//
//  main.cpp
//  Three Card Monte
//
//  Created by Kevin Vo on 4/28/24.
// This program is the game of Three Card Monte, the game itself is within a while loop and is designed to keep running until the bet is larger than the inhand cash or if the user decides to exit the game. The game generates a random number between 1-3 in which the user guesses one of the cards, if the user is correct, the code adds 2 times the bet amount to the inhand cash, if the user gets it wrong, they lose the bet. After each round the user is prompted with a question to keep playing or to leave.

#include <iostream>
#include <cmath>
using namespace std;


int main() {

    int inhand_cash;
    int bet_amount;
    int wins;
    int losses;
    
    cout << "Three Card Monte: Enter an amount $ to start the game: ";
    while (!(cin >> inhand_cash) || inhand_cash <= 0) {
         cout << "Invalid input. Please enter a positive amount $: ";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }
    cout << endl;
    
    cout << "Enter your bet $: ";
    while (!(cin >> bet_amount) || bet_amount <= 0 || bet_amount > inhand_cash) {
        cout << "Invalid input. Please enter a valid bet: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl;
    
    if(bet_amount > inhand_cash) {
        cout << "Invalid bet amount, please enter a valid bet: ";
        cin >> bet_amount;
        cout << endl;
    }
    
    
    
    int userGuess;
    int target_card;
    wins = 0;
    losses = 0;
    
    while (true) {
        target_card = rand() % 3 + 1;
        
        cout << "Let's start the game! Guess the position of the target card (1, 2, or 3): ";
            while (!(cin >> userGuess) || userGuess < 1 || userGuess > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(userGuess < 1 || userGuess > 3) {
            cout << "Invalid guess. Please enter a number between 1 and 3." << endl;
            continue;
        }
        
        if(userGuess == target_card) {
            cout << "You guessed correctly! You win: $" << bet_amount*2 << endl;
            inhand_cash = inhand_cash - bet_amount + (2*bet_amount);
            cout << "Inhand cash: $" << inhand_cash << endl << endl;
            wins = wins + 1;
        } else {
            cout << "You guessed incorrectly! The card was at: " << target_card << ". You lost: $" << bet_amount << endl;
            inhand_cash = inhand_cash - bet_amount;
            cout << "Inhand cash: $" << inhand_cash << endl << endl;
            losses = losses + 1;
            
            if(inhand_cash < bet_amount) {
                cout << "Thank you for playing. Your remaining balance is $" << inhand_cash << endl;
                cout << "Total wins: " << wins << endl;
                cout << "Total losses: " << losses << endl;
                    break;
                }
        }
        
        char choice;
            cout << "Do you want to continue playing? (y/n): ";
            cin >> choice;
            cout << endl;
        
                if(choice == 'n'|| choice == 'N') {
                    cout << "Thank you for playing. Your remaining balance is $" << inhand_cash << endl;
                    cout << "Total wins: " << wins << endl;
                    cout << "Total losses: " << losses << endl;
                    break;
                } else if (choice == 'y' || choice == 'Y') {
                    continue;
                } else {
                    cout << "Invalid input. Please enter either y or n" << endl;
                }
    }
    

    return 0;
}
