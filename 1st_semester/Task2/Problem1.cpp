#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

bool isItPunctMark(char character)
{
    std::string punctMarks = ",.?!;:)(-";
    for (int i = 0; i < punctMarks.length(); ++i)
    {
        if (character == punctMarks[i])
            {
                return true;
            }
    }
    return false;
}

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    string text;
    getline(cin, text);
    int length = text.length();

    vector<string> array;
    string tmp = "";

    for (int i = 0; i < length; ++i)
    {
        if (isItPunctMark(text[i]))
        {
           // cout << "punct";
           array.push_back(string(1, text[i]));
        }
        else
        {
            if (text[i] == ' ' && tmp != "")
            {
               // cout << "space";
                array.push_back(tmp);
                tmp = "";
            }
            else
            {
                //cout << "word";
                tmp += text[i];
            }
        }
    }
    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << " ";
    }
    return EXIT_SUCCESS;
}
