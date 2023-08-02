#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0; //exit the application
}


//introduce the game
void PrintIntro() 
{
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to BULLS AND COWS, a fun word game. \n";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}


void PlayGame()
{
	// loop for the  number of turns asking for guess
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() 
{
	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)?";
	string Responce = "";
	getline(cin, Responce);
	return (Responce[0] == 'y') || (Responce[0] == 'Y');
}
