//*******************************************************************************************************
//
//        File:                   main.cpp
//
//        Student:                Lexi Corniello
//
//        Assignment:             Asssignment #9
//
//        Course Name:            Data Structures I
//
//        Course Number:          COSC 3050-10
//
//        Due:                    November 15th, 2021
//
//        This file executes the given functions in the header/file to calculate the results
//
//        Other files required:
//        1. AStack.h
//
//*******************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;
#include "AStack.h"

//*******************************************************************************************************

char isPalindrome(char *);
char isTautonym(char *);
char isPairIsogram(char *);
void displayResult(char *);

//*******************************************************************************************************

int main()
{
    ifstream myfile("pairiso_input.txt");
    char data[80];

    if (myfile.fail())
    {
        cout << "failed to open" << endl;
    }
    
    else
    {
        while(myfile.getline(data, 80))
        {
            displayResult(data);
            cout << endl;
        }
        myfile.close();
    }
    return 0;
}

//*******************************************************************************************************

char isPalindrome(char *data)
{
    bool success = true;
    int i = 0;
    char c;
    int l = strlen(data);
    Stack<char> s1;
    
    for(i = 0; success && i < l; i++)
    {
        if (!s1.push(data[i]))
            {
                cout << "Can't push" << endl;
                success = false;
            }
    }
    while(success && s1.pop(c))
    {
        if(c != data[i])
        {
            success = false;
        }
        i++;
    }
    return success;
}

//*******************************************************************************************************

char isTautonym(char *data)
{
    bool success = true;
    char w1,
         w2;
    int i;
    Stack<char> s1,
                s2;
    int l = strlen(data);
    
    if(l % 2 == 0)
    {
        for (i = 0; success && i < l / 2; i++)
        {
            s1.push(data[i]);
        }
        for(i = l / 2; success && i < l; i++)
        {
            s2.push(data[i]);
        }
        while(success && s1.pop(w1) && s2.pop(w2))
            {
                if(w1 != w2)
                    {
                        success = false;
                    }
            }
    }
    return success;
}
    
//*******************************************************************************************************

char isPairIsogram(char *data)
{
    bool success = true;
    Stack<char> letters[26];
    int l = strlen(data);
    int i;
    
    if(!isPalindrome(data) && !isTautonym(data))
    {
        for (i = 0; data[i] != '\0'; i++)
    {
        if(!letters[data[i] - 'a'].isEmpty())
        {
            letters[data[i] - 'a'].push(data[i]);
        }
            else
            {
                letters[data[i] - 'a'].pop(data[i]);
            }
    }
        for (int i = 0; letters[data[i] - 'a'].isEmpty(); i++)
        {
            if(letters[i].isEmpty())
            {
                success = false;
            }
        }
    }
        return success;
}

//*******************************************************************************************************

void displayResult(char *data)
{
    cout << data << endl;
    if(!isPairIsogram(data))
   {
       cout << "This string is a pair isogram." << endl;
   }
   else
   {
       cout << "This string is not a pair isogram" << endl;
   }
}

//*******************************************************************************************************

//SAMPLE OUTPUT
/*
 mama
 This string is not a pair isogram

 teammate
 This string is a pair isogram.

 blingbling
 This string is not a pair isogram

 horseshoer
 This string is a pair isogram.

 aviddiva
 This string is a pair isogram.

 appeases
 This string is a pair isogram.

 stellaeast
 This string is a pair isogram.

 Program ended with exit code: 0
 */

//*******************************************************************************************************
