//
//  main.cpp
//  WoeHW9
//
//  Copyright © 2016 Melanie Woe. All rights reserved.
//

#include "HashTable.h"

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

// iterator declaration for hash table
typedef HashTable<string>::Iterator iterDec;

// hash table size
const int sizetable = 25025;

// strtok delimiters
const char* DELIMITERS = " ";

// function prototypes
void status(HashTable<string>& hashTable);
int SpellCheck(HashTable<string>& hashTable, string word);
string ToLowerCase(string word);

int main()
{
    // declare variables
    int result = 0;
    string input;
    string currWord;
    char response;
    ifstream infile;
    HashTable<string> hashTable(sizetable);
    
    // open the dictionary file
    infile.open("dict.dat");
    
    // check if the file exists, EXIT if it doesnt
    if(infile.fail())
    {
        cout<<"File cannot be open";
        exit(1);
    }
    
    
    // get data from file and put into hashtable
    while(infile >> currWord)
    {
        // makes sure duplicate words arent inserted into table
        if(!hashTable.Count(currWord))
        {
            hashTable.Insert(currWord);
        }
    }
    infile.close();
    status(hashTable);
   
    
    // separate
    cout<<endl << endl;
    
    
    cout<<"Please enter a word or sentence you want to check: "; // get user input
    getline(cin,input);
    cout<<endl;
        
    // split each word from the string into individual words to check if
    // they are spelled correctly
    char* splitInput = strtok(const_cast<char*>(input.c_str()),DELIMITERS);
    while(splitInput!=NULL)
    {
        currWord = splitInput;
        currWord = ToLowerCase(currWord);
        result += SpellCheck(hashTable,currWord);
        splitInput = strtok(NULL,DELIMITERS);
    }
        
        
    // display results
    if(result > 0)
    {
        cout<<"Number of words spelled incorrectly: "<<result<<endl;
        result = 0;
    }
    else if(result < 0)
    {
        cout << "word spelled correctly" << endl;
    }
        
    
    
    
    
    return 0;
}// end of main

void status(HashTable<string>& hashTable)
{
    // seperate lines
    cout<<endl;
    
    cout<<"There are "<<hashTable.TotalElems()<< " words in dictionary" <<endl;
    
}
// end of PrintTableStats

int SpellCheck(HashTable<string>& hashTable, string word)
{
    int result = 0;
    int suggestion = 0;
    string remove[256];
    int numRemove=0;
    
    if(!hashTable.Count(word))
    {
        ++result;
        cout<<word<<": ";
        // alteration & insertion
        for(unsigned x = 0; x < word.length(); ++x)
        {
            string alteration = word;
            for(char c = 'a'; c <= 'z'; ++c)
            {
                //alteration
                alteration[x] = c;
                if(hashTable.Count(alteration))
                {
                    cout<<alteration<<", ";
                    remove[numRemove++] = alteration;
                    ++suggestion;
                    // remove the entry so it isnt displayed multiple times
                    hashTable.Remove(alteration);
                }
                //insertion
                string insertion = word.substr(0, x) + c + word.substr(x);
                if(hashTable.Count(insertion))
                {
                    cout<<insertion<<", ";
                    remove[numRemove++] = insertion;
                    ++suggestion;
                    // remove the entry so it isnt displayed multiple times
                    hashTable.Remove(insertion);
                }
            }
        }
        // transposition & deletion
        for(unsigned x = 0; x < word.length()-1;++x)
        {
            // transposition
            string transposition = word.substr(0,x) + word[x+1] + word[x] + word.substr(x+2);
            if(hashTable.Count(transposition))
            {
                cout<<transposition<<", ";
                remove[numRemove++] = transposition;
                ++suggestion;
                // remove the entry so it isnt displayed multiple times
                hashTable.Remove(transposition);
                
            }
            // deletion
            string deletion = word.substr(0, x)+ word.substr(x + 1);
            if(hashTable.Count(deletion))
            {
                cout<<deletion<<", ";
                remove[numRemove++] = deletion;
                ++suggestion;
                // remove the entry so it isnt displayed multiple times
                hashTable.Remove(deletion);
            }
        }		
        // place the removed items back inside the hash table
        while(numRemove>=0)
        {
            hashTable.Insert(remove[numRemove--]);
        }
        if(suggestion < 1)
        {
            cout<<"No spelling suggestion found";
        }
        cout<<endl<<endl;
    }
    
    return result;
}// end of SpellCheck

string ToLowerCase(string word)
{
    for(unsigned x = 0; x < word.length(); ++x)
    {
        word[x] = tolower(word[x]);
    }
    return word;
}