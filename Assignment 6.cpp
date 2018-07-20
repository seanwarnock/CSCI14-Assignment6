/*

Sean Warnock
CSCI 14 Summer 2018
Assignment 6 due 7/26/2018
https://github.com/seanwarnock/CSCI14-Assignment6.git

Allow user to type in something either Morse Code or Alpha

build a comparison between each type.  Think structure for alpha characters
and a second list of Morse characters.

Can I essentually echo the character a user types?
*/

//#include <time.h>
#include <iostream>
#include <iomanip>
//#include <math.h>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <regex>
#ifdef _WIN32
  #include <winsock2.h>
  #include <windows.h>
#endif
#ifdef __linux__

#endif

using namespace std;



struct CharacterChanger
   {
    char MorseChar[6];
    char AlphaChar;
    // character converter.. use ASCII values to match.
  };

void CharacterTableFill(CharacterChanger[] );

int main ()
{


  CharacterChanger ConverterTable[254];
  string UserInput;

  char TestChar;
  cout << "Type in what you want to translate.  Press enter to send." << endl;
  cout << "Single space between letters and double space between words." << endl;
//rough idea on how to interactively pull character input.
  do {
    TestChar = _getch();
    cout << TestChar;
    //cout << "Some String ";
  }while (TestChar != '\n');
  cout << endl;
  system("pause");
}

void CharacterTableFill(CharacterChanger ArraytoFill[])
{
/*
 pack the array with the entire ASCII 256 table.  Then fill the Morse side
of the array with the matching Morse string.
*/
}
