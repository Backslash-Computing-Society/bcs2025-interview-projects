#include <iostream>
#include <cstdlib> //For rand() and srand()
#include <ctime> //For time()
using namespace std;
int main() {
//Initialize random seed
srand(time(0));
int playerChoice, computerChoice;
cout<<"=========================\n";
cout<<"Rock, Paper, Scissors Game!\n";
cout<<"=========================\n";
cout<<"Choose one: \n";
cout<<"1. Rock\n";
cout<<"2. Paper\n";
cout<<"3. Scissors\n";
cout<<"Enter your choice (1-3): ";
cin>>playerChoice;
//Generate computer's choice
computerChoice = rand() % 3 + 1; //Random number between 1 and 3
//Display computer's choice
cout<<"Computer chose: ";
if(computerChoice == 1)
cout<<"Rock\n";
else if(computerChoice == 2)
cout<<"Paper\n";
else
cout<<"Scissors\n";
//Determine the winner
if(playerChoice == computerChoice) {
cout<<"It's a tie!\n";
} else if(
(playerChoice ==1 && computerChoice == 3) ||
(playerChoice == 2 && computerChoice == 1) ||
(playerChoice == 3 && computerChoice == 2)
) {
cout<<"You win!\n";
} else {
cout<<"You lose!\n";
}
return 0;
}