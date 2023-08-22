/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible forr all
user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using Ftext = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game, with we re-use across plays

//the entry point for our application
int32 main()
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

void PrintIntro() 
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game!\n";
	std::cout << '\n';
	std::cout << "           }   {            ___" << '\n';
	std::cout << "           (o o)           (o o)" << '\n';
	std::cout << "    /-------\\ /             \\ /------\\ " << '\n';
	std::cout << "   / | BULL |O               O| COW | \\ " << '\n';
	std::cout << " *   |-,--- |                 |-----|  * " << '\n';
	std::cout << "     ^      ^                 ^     ^ " << '\n';
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	std::cout << '\n';
	
	std::cout << std::endl;
	return;
}

// play a single game to complection
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
		
	// loop asking for guess while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		Ftext Guess = GetValidGuess();
				
		// submit valid guess to the game, and rececive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}
// loop continually until the user gives a valid guess
Ftext GetValidGuess() 
{
	Ftext Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do	{	
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << " Enter your guess: ";
		std::getline(std::cin, Guess);

		//check if the users guess is valid or not
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (a word with no repeating letters).\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a word with only lowercase letters!\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); //keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)?";
	Ftext Responce = "";
	std::getline(std::cin, Responce);
	return (Responce[0] == 'y') || (Responce[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
