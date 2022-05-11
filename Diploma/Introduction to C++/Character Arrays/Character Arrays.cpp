// Character Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <regex>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <cctype>


//// EXERCISE 7
//bool isVowel(char c)
//{
//    return (c == 'A' || c == 'E' || c == 'I' ||
//            c == 'O' || c == 'U' || c == 'a' ||
//            c == 'e' || c == 'i' || c == 'o' ||
//            c == 'u');
//}
//
//std::string pigLatin(std::string s)
//{
//    // the index of the first vowel is stored.
//    int len = s.length();
//    int index = -1;
//    for (int i = 0; i < len; i++) {
//        if (isVowel(s[i])) {
//            index = i;
//            break;
//        }
//    }
//
//    // Pig Latin is possible only if vowels is present
//    if (index == -1)
//        return "-1";
//
//    // Take all characters after index (including index). Append all characters which are before index. Finally append "ay"
//    return s.substr(index) + s.substr(0, index) + "ay";
//}

std::string EncodeWord(std::string word)
{
    std::string result;
    for (int i = 0; i < word.length(); i++) 
    {
        result += (char)('a' + (word.at(i) - 'a' + 5) % 26);
    }
    return result;
}

int main()
{
    //// EXERCISE 1, 2, 3
    //// print full name
    //const int people = 5;
    //const int names = 2;
    //std::string fullNames[people][names];

    //for (int i = 0; i < people; i++)
    //{
    //    std::cout << "Enter first name, press enter, then enter last name..." << std::endl;
    //    for (int j = 0; j < names; j++)
    //    {          
    //        std::cin >> fullNames[i][j];
    //    }      
    //}
    //std::cout << std::endl;

    //// print names 
    //for (int i = 0; i < people; i++)
    //{
    //    for (int j = 0; j < names; j++)
    //    {
    //        std::cout << fullNames[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}
    //std::cout << std::endl;

    //// print names in reverse
    //for (int i = 0; i < people; i++)
    //{
    //    for (int j = 1; j >= 0; j--)
    //    {
    //        reverse(fullNames[i][j].begin(), fullNames[i][j].end());
    //        std::cout << fullNames[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}
    //return 0;

    // EXERCISE 4
    /*const std::regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[-+_!@#$%^&*.,?]).+$");

    std::string userName, password;
    std::cout << "Enter username: " << std::endl;
    std::cin >> userName; 
    std::cout << "Enter password: " << std::endl;
    std::cin >> password;

    while (!(regex_match(password, pattern) && password.length() >= 8 && !password.empty()))
    {
        std::cout << "Please enter a Valid Password: " << std::endl;
        std::cin >> password;
    }
    std::cout << "Password Accepted" << std::endl;*/

    //// EXERCISE 5
    //std::string userName, password;
    //std::string userCheck = "usr";
    //std::string pwordCheck = "Pa55w0rd";
    //std::cout << "Enter username: ";
    //std::cin >> userName;

    //// user check and prompt
    //while (userName.find(userCheck) == std::string::npos)
    //    {
    //    std::cout << "Enter username contain 'usr': ";
    //    std::cin >> userName;
    //    }

    //std::cout << "Enter password: ";
    //std::cin >> password;

    //// password check and prompt
    //while ((password != pwordCheck) && (password.length() != 8))
    //{
    //    std::cout << "We recommend using 'Pa55w0rd', please try again: ";
    //    std::cin >> password;
    //}

    //std::cout << "Account successfully created." << std::endl;

    //// prints user identifier
    //char* char_arr;
    //std::string identifier(userName + "-" + password);
    //char_arr = &identifier[0];
    //std::cout << char_arr << std::endl;

    //return 0;

    //// EXERCISE 7
    //std::string userWord;
    //std::string str;

    //std::cout << "Enter a word to convert to pig latin: ";
    //std::cin >> userWord;

    //str = pigLatin(userWord);
    //str = pigLatin(userWord);
    //if (str == "-1")
    //{
    //    std::cout << "No vowels found. Pig Latin not possible";
    //}
    //else
    //{
    //    std::cout << str << std::endl;
    //}
    
    //// EXERCISE 8
    //std::string statement;
    //int words = 1;
    //int characters = 0;
    //std::cout << "Enter a string: ";
    //getline(std::cin, statement); // stores complete statement in string not just first word

    //for (int i = 0; i < statement.length(); i++)
    //{
    //    if (!isspace(statement.at(i)))
    //    {
    //        characters++;
    //    }
    //    else
    //    {
    //        words++;
    //    }
    //}
    //std::cout << "\nThere are " << words << " words in the given string";
    //std::cout << "\nThere are " << characters << " characters in the given string" << std::endl;

    //return 0;

    ////EXERCISE 9
    //std::string palindrome, check, word;
    //std::cout << "Enetr a word to check if it is a palindrome: ";
    //std::cin >> palindrome;

    //word = palindrome; // store original word
    //std::for_each(palindrome.begin(), palindrome.end(), [](char& c) {c = ::tolower(c); }); // convert to lower to avoid caps errors
    //check = palindrome; // set check to same word in lower

    //reverse(palindrome.begin(), palindrome.end()); // reverse palindrome 

    //if (palindrome == check) // check if two strings are the same
    //{
    //    std::cout << word << " IS a plaindrome" << std::endl;
    //}
    //else
    //{
    //    std::cout << word << " IS NOT a plaindrome" << std::endl;
    //}
  
    //// EXERCISE 11
    //std::string statement;
    //std::cout << "Enter a sentence: ";
    //getline(std::cin, statement); // stores complete statement in string not just first word

    //int max = 0;
    //char res = '3';
    //int size = statement.length();
    //for (int i = 0; i < size; i++)
    //{
    //    int count = 0;
    //    /* counting frequency of each character */
    //    for (int j = 0; j < size; j++)
    //    {
    //        if (statement[j] == statement[i] && !isspace(statement.at(i)))
    //        {
    //            count++;
    //        }
    //    }
    //    if (count > max)
    //    {
    //        max = count;
    //        res = statement[i];
    //    }
    //}
    //std::cout << "The most frequent character of the string is '" << res << "'" << std::endl;

    //// EXERCISE 12
    //std::string date, day, month, year;
    //int monthNum = 0;
    //const int numOfMOnths = 12;

    //std::string months[numOfMOnths] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    //std::cout << "Enter a date in the format dd/mm/yyyy: ";
    //std::cin >> date;

    //// store individual values of string in seperate variables
    //day = date.substr(0, 2);
    //month = date.substr(3, 2);
    //year = date.substr(6, 4);

    //monthNum = stoi(month); // convert string to int
    //
    //month = months[monthNum - 1]; // set month to word format

    //std::cout << "The date is " << month << " " << day << ", " << year << std::endl;

    ////EXERCISE 13
    //std::string line, newLine;
    //std::cout << "Enter a statement to remove whitespace: ";
    //getline(std::cin, line); // stores complete statement in string not just first word

    //for (int i = 0; i < line.length(); i++)
    //{
    //    if (!isspace(line.at(i)))
    //    {
    //        newLine += line[i]; // create copy of string without whitespace
    //    }
    //}

    //std::cout << newLine << std::endl;

    // EXERCISE 14
    std::string encodedWord;
    std::cout << "Enter a word to be encoded: ";
    std::cin >> encodedWord;

    std::cout << "The word once it has been encoded is " << EncodeWord(encodedWord) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
