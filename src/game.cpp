#include <iostream>
#include <string>
#include <vector>
#include <fstream>


std::string LoadRandomWord(std::string path)
{
    int lineCount = 0;
    std::string word;
    std::vector<std::string> v;
    std::ifstream reader(path);
    if (reader.is_open())
    {
        while (std::getline(reader, word))
            v.push_back(word);
 
        int randomLine = rand() % v.size();
 
        word = v.at(randomLine);
        reader.close();
    }
    return word;
}
int TriesLeft(std::string word, std::string guessed)
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == std::string::npos)
            error++;
    }
    return error;
}