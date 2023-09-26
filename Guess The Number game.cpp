#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    cout<<endl<<endl;
	cout<<" ====================================================="<<endl;
    cout<<"|                  GUESS THE NUMBER                   |"<<endl;
    cout<<" ====================================================="<<endl;
	
    cout<<endl<<"\t\t\t:RULES:"<<endl<<endl;

    cout<<"1. You have to guess a number from 1 to 100."<<endl;
    cout<<"2. There are 3 Levels : "<<endl;
    cout<<"   Easy   : 10 chances allowed."<<endl;
    cout<<"   Medium : 7 chances allowed."<<endl;
    cout<<"   Hard   : 5 chances allowed."<<endl;
    cout<<endl<<"\t\t   || BEST OF LUCK ||"<<endl;
		

	while (true) {
		cout << "\nCHOOSE DIFFICULTY LEVEL : \n";
		cout << "FOR EASY   : PRESS 1\n";
		cout << "FOR MEDIUM : PRESS 2\n";
		cout << "FOR HARD   : PRESS 3\n";
		cout << "END GAME   : PRESS 0\n" << endl;

		int difficultyChoice;
		cout << "Enter the number: ";
		cin >> difficultyChoice;

		srand(time(0));
		int secretNumber = 1 + (rand() % 100);
		int playerChoice;


		
		if (difficultyChoice == 1) {
			cout << "\n AS PER RULES YOU HAVE 10 CHANCES TO GUESS THE SECRET NUMBER : ";
			int choicesLeft = 10;
			for (int i = 1; i <= 10; i++) {

				cout << "\n\nEnter the number: ";
				cin >> playerChoice;

				if (playerChoice == secretNumber) {
					cout << "\nWell played! You won, "<< playerChoice<< " is the secret number." << endl;
					cout << "\nThanks for playing...."<<endl<<endl;
					break;
				}
				else {
					cout << "\nNope, " << playerChoice << " is not the right number\n";
					if (playerChoice > secretNumber) {
						cout << "\nThe secret number is smaller than the number you have chosen\n"<< endl;
					}
					else {
						cout << "\nThe secret number is greater than the number you have chosen\n"<< endl;
					}
					choicesLeft--;
					cout << choicesLeft << " choices left. "<< endl;
					if (choicesLeft == 0) {
						cout << "\nYou Lose, it was "<< secretNumber<<endl;
						cout << "\nPlay the game again to win!!!\n\n";
					}
				}
			}
		}

	
		else if (difficultyChoice == 2) {
			cout << "\n AS PER RULES YOU HAVE 7 CHANCES TO GUESS THE SECRET NUMBER : ";
			int choicesLeft = 7;
			for (int i = 1; i <= 7; i++) {

				cout << "\n\nEnter the number: ";
				cin >> playerChoice;

				if (playerChoice == secretNumber) {
					cout << "\nWell played! You won, "<< playerChoice<< " is the secret number." << endl;
					cout << "\nThanks for playing...."<<endl<<endl;
					break;
				}
				else {
					cout << "\nNope, " << playerChoice << " is not the right number\n";
					if (playerChoice > secretNumber) {
						cout << "\nThe secret number is smaller than the number you have chosen\n"<< endl;
					}
					else {
						cout << "\nThe secret number is greater than the number you have chosen\n"<< endl;
					}
					choicesLeft--;
					cout << choicesLeft << " choices left. "<< endl;
					if (choicesLeft == 0) {
						cout << "\nYou Lose, it was "<< secretNumber<<endl;
						cout << "\nPlay the game again to win!!!\n\n";
					}
				}
			}
		}

		else if (difficultyChoice == 3) {
			cout << "\n AS PER RULES YOU HAVE 5 CHANCES TO GUESS THE SECRET NUMBER : ";
			int choicesLeft = 5;
			for (int i = 1; i <= 5; i++) {

				
				cout << "\n\nEnter the number: ";
				cin >> playerChoice;

				if (playerChoice == secretNumber) {
					cout << "\nWell played! You won, "<< playerChoice<< " is the secret number." << endl;
					cout << "\nThanks for playing...."<<endl<<endl;
					break;
				}
				else {
					cout << "\nNope, " << playerChoice << " is not the right number\n";
					if (playerChoice > secretNumber) {
						cout << "\nThe secret number is smaller than the number you have chosen\n"<< endl;
					}
					else {
						cout << "\nThe secret number is greater than the number you have chosen\n"<< endl;
					}
					choicesLeft--;
					cout << choicesLeft << " choices left. "<< endl;
					if (choicesLeft == 0) {
						cout << "\nYou Lose, it was "<< secretNumber<<endl;
						cout << "\nPlay the game again to win!!!\n\n";
					}
				}
			}
		}

		else if (difficultyChoice == 0) {
			exit(0);
		}
		else {
			cout << "Wrong choice, Enter valid choice to play the game again ! (0 / 1 / 2 / 3)"
				<< endl;
		}
	}
	return 0;
}