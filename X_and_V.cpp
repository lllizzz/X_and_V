#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

void SetText(list<string>& text)
{
    string words;
    while (true)
    {
        getline(cin, words);
        if (words.empty())
        {
            break;
        }
        text.push_back(words);
    }
}

void NewText(list<string>& text)
{
    auto iter = text.begin();
    string copy;
    string commands;
    while (cin >> commands)
    {
        if (commands == "Down" && iter != text.end())
        {
            ++iter;
        }
        else if (commands == "Up" && iter != text.begin())
        {
            --iter;
        }
        else if (commands == "Ctrl+X" && iter != text.end())
        {
            copy = *iter;
            iter = text.erase(iter);
        }
        else if (commands == "Ctrl+V" && !copy.empty())
        {
            text.insert(iter, copy);
        }
    }
    for (const auto& i : text)
    {
        cout << i << endl;
    }
}

int main()
{
    list<string> text;
    SetText(text);
    NewText(text);
}