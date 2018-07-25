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



struct CharacterList
   {
    char MorseChar[6];
    char AlphaChar;
    // character converter.. use ASCII values to match.
  };

string CharacaterChanger(string);
string CharacaterChanger(char);

int main ()
{


  //CharacterChanger ConverterTable[254];

//Variables
  string UserInput;
  string AlphaString;
  string MorseString;

  char TestChar;


//Program
  SetConsoleTitle(ASSIGNMENT);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY );
  cout << "Type in what you want to translate.  Press enter to send." << endl;
  cout << "Single space between letters and double space between words." << endl;
//rough idea on how to interactively pull character input.

  do {
    int intMorseLooper = 0;
    string InnerMorseString = "";

    TestChar = _getch();

    //test to make certain if valid character for Alpha or Morse.  If valid output to screen and store in string otherwise ignore.

    while ((int(TestChar) == 45) || (int(TestChar) == 46))
    {
      //Enter Morse loop.  Loop through up to six characters to test.  If alpha or space break out of loop and return to main loop processing.
      cout << TestChar;
      UserInput.append(1,TestChar);
      //cout << CharacaterChanger(".");
      InnerMorseString.append(1,TestChar);
      intMorseLooper++;
    cout << "InnerMorseString in loop" << InnerMorseString << endl;
      if ((intMorseLooper > 5) || (int(TestChar) == 32) || (TestChar == '\n'))
      {
        cout << CharacaterChanger(InnerMorseString);
        break;
      }
      TestChar = _getch();
    }

    //if Alpha send to conversion.
    //If period or underscore store up to five char until space else throw error of some kind.  Once characters are pulled send to conversion.
    //     Capitol Letters                                  Lowercase Letters                                      Numeric                                             space
    if ( ((int(TestChar) >= 65) && (int(TestChar <= 90))) || ((int(TestChar) >= 97) && (int(TestChar) <= 122)) || ((int(TestChar) >= 48) && (int(TestChar) <= 57)) || (int(TestChar) == 32) )
    {
      cout << TestChar; //<< " Integer value " << int(TestChar);
      UserInput.append(1,TestChar);
      cout << CharacaterChanger(TestChar);
    }

    //period                   Dash
//Check for Morse character or if the morse string is <> zero length.
//  Then if space or alpha character is in the temp character then complete Morse processing and clear Morse string.
//  Else add character to Morse string.
//If alpha character then do alpha processing.
//If space print space

//This runs until the newline character.
  }while (int(TestChar) != 13);
  cout << endl;
  system("pause");

  system("cls");
  cout << "You typed" << endl;
  cout << UserInput;
}

string CharacaterChanger(string charTestString)
{
/*
 pack the array with the entire ASCII 256 table.  Then fill the Morse side
of the array with the matching Morse string.
*/

//if Alpha send to conversion.
//If period or underscore store up to four char until space else throw error of some kind.  Once characters are pulled send to conversion.
  return "MORSE";


//switch

}

string CharacaterChanger(char charTestChar)
{

  charTestChar = toupper(charTestChar);

  switch (charTestChar)
  {
    case 'A' :
      return ".-";
      break;  //Do I really need this break since I am already returning on the function?
    case 'B' :
      return "-...";
      break;
    case 'C' :
      return "-.-.";
      break;
    case 'D' :
      return "-..";
      break;
    case 'E':
      return ".";
      break;
    case 'F' :
      return "..-.";
      break;
    case 'G' :
      return "--.";
      break;
    case 'H' :
      return "....";
      break;
    case 'I' :
      return "..";
      break;
    case 'J' :
      return ".---";
      break;
    case 'K' :
      return "-.-";
      break;
    case 'L' :
      return ".-..";
      break;
    case 'M' :
      return "--";
      break;
    case 'N' :
      return "-.";
      break;
    case 'O' :
      return "---";
      break;
    case 'P' :
      return ".--.";
      break;
    case 'Q' :
      return "--.-";
      break;
    case 'R' :
      return ".-.";
      break;
    case 'S' :
      return "...";
      break;
    case 'T' :
      return "-";
      break;
    case 'U' :
      return "..-";
      break;
    case 'V' :
      return "...-";
      break;
    case 'W' :
      return ".--";
      break;
    case 'X' :
      return "-..-";
      break;
    case 'Y' :
      return "-.--";
      break;
    case 'Z' :
      return "__..";
      break;
    case '1' :
      return ".----";
      break;
    case '2' :
      return "..---";
      break;
    case '3' :
      return "...--";
      break;
    case '4' :
      return "....-";
      break;
    case '5' :
      return ".....";
      break;
    case '6' :
      return "-....";
      break;
    case '7' :
      return "--...";
      break;
    case '8' :
      return "---..";
      break;
    case '9' :
      return "----.";
      break;
    case '0' :
      return "----";
      break;
    default :
      return " ";
      break;

  }
}
