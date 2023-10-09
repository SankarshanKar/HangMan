#pragma once

#include <string>


void PrintMessage(std::string message, bool printTop = true, bool printBottom = true);
void DrawHangman(int guessCount = 0);
void PrintLetters(std::string input, char from, char to);
void PrintAvailableLetters(std::string taken);
bool PrintWordAndCheckWin(std::string word, std::string guessed);