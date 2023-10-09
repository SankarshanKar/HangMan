#include <iostream>
#include <string>


void PrintMessage(std::string message, bool printTop = true, bool printBottom = true)
{
    if (printTop)
    {
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|";
    }
    else
    {
        std::cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    std::cout << message.c_str();
 
    if (printBottom)
    {
        std::cout << "|" << std::endl;
        std::cout << "+---------------------------------+" << std::endl;
    }
    else
    {
        std::cout << "|" << std::endl;
    }
}
void DrawHangman(int guessCount = 0)
{
    if (guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
 
    if (guessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
 
    if (guessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);
 
    if (guessCount == 4)
        PrintMessage("/  ", false, false);
    
    if (guessCount == 5)
        PrintMessage("/| ", false, false);
 
    if (guessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);
 
    if (guessCount >= 7)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
 
    if (guessCount == 8)
        PrintMessage("/", false, false);
 
    if (guessCount >= 9)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);
}
void PrintLetters(std::string input, char from, char to)
{
    std::string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == std::string::npos)
        {
            s += i;
            s += " ";
        }
        else
            s += "  ";
    }
    PrintMessage(s, false, false);
}
void PrintAvailableLetters(std::string taken)
{
    PrintMessage("Available letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}
bool PrintWordAndCheckWin(std::string word, std::string guessed)
{
    bool won = true;
    std::string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == std::string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}