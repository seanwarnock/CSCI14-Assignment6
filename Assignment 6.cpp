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

//#include <math.h>
//#include <regex>
//#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
#ifdef _WIN32
  #include <winsock2.h>
  #include <windows.h>
#endif
#ifdef __linux__

#endif

#define ASSIGNMENT "CSCI 14 Assignment 6"


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

//Variables
  string UserInput;
  char TestChar;


//Program
  SetConsoleTitle(ASSIGNMENT);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY );
  cout << "Type in what you want to translate.  Press enter to send." << endl;
  cout << "Single space between letters and double space between words." << endl;
//rough idea on how to interactively pull character input.

  do {
    TestChar = _getch();

    //test to make certain if valid character for Alpha or Morse.  If valid output to screen and store in string otherwise ignore.

    //     Capitol Letters                                  Lowercase Letters                                      Numeric                                             space                   period                   Dash
    if ( ((int(TestChar) >= 65) && (int(TestChar <= 90))) || ((int(TestChar) >= 97) && (int(TestChar) <= 122)) || ((int(TestChar) >= 48) && (int(TestChar) <= 57)) || (int(TestChar) == 32) || (int(TestChar) == 46) || (int(TestChar) == 45) )
    {
      cout << TestChar; //<< " Integer value " << int(TestChar);
      UserInput.append(1,TestChar);
    }

  }while (int(TestChar) != 13);
  cout << endl;
  system("pause");

  system("cls");
  cout << "You typed" << endl;
  cout << UserInput;
}

void CharacterTableFill(CharacterChanger ArraytoFill[])
{
/*
 pack the array with the entire ASCII 256 table.  Then fill the Morse side
of the array with the matching Morse string.
*/
}
