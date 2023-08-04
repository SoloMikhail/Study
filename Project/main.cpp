#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

//the entry point for our application
int main()
{
	std::cout << BCGame.GetCurrentTry();
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
	std::cout << "Welcome to BULLS AND COWS, a fun word game. \n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	// loop for the  number of turns asking for guess
	
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() 
{
	int CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player
	std::cout << " Try " << CurrentTry << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	std::string Responce = "";
	std::getline(std::cin, Responce);
	return (Responce[0] == 'y') || (Responce[0] == 'Y');
}
