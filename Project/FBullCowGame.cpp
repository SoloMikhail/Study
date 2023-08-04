#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {	Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyCurrentTry = MAX_TRIES;

	MyMaxTries = 8;
	return;
}



bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
