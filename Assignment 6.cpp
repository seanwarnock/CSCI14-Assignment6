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

void AlphatoMorse();
void MorsetoAlpha();

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
  char charMenuChoice;

//Program
  SetConsoleTitle(ASSIGNMENT);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY );

do {
    system("cls");
    cout << "[1] Translate from alphanumeric to Morse code." << endl;
    cout << "[2] Translate from Morse code to alphanumeric." << endl;
    cout << "[3] Translate from either alphanumeric and/or Morse code to both."  << endl;
    cout << "[9] Exit program." << endl;

    cin >> charMenuChoice;

    switch (charMenuChoice)
    {
      case '1' :
        cout << "Alpha to Morse.";
        AlphatoMorse();
        break;
      case '2' :
        cout << "Morse to Alpha.";
        MorsetoAlpha();
        break;
      case '3' :
        cout << "Uber translator. (Work in Progress)";
        break;
      case '9' :
        cout << "Later Aligator.";
        break;
    }



//rough idea on how to interactively pull character input.




  }while (charMenuChoice != '9');
}

/*

    cout << "Type in what you want to translate.  Press enter to send." << endl;
    cout << "Single space between letters and double space between words." << endl;



   do
      {
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
      }while (charMenuChoice != '9');
    cout << endl;
    system("pause");

    system("cls");
    cout << "You typed" << endl;
    cout << UserInput;
    system("pause");
    cout << "Run again [Y]n ?";
    cin >> charMenuChoice;


*/

void AlphatoMorse()
{
  string stringAlphaString;
  int n;

  system("cls");
  cout << "Please type in a sentence to convert to Morse Code: " << endl;
  cin.ignore();
  getline(cin,stringAlphaString);

  system("cls");
  cout << "Alpha Numeric:" << endl << stringAlphaString << endl;
  cout << "Morse Code:" << endl << endl;
  for (n=0;n<(stringAlphaString.size());n++)
  {
      cout << CharacaterChanger(stringAlphaString[n]);
  }
  cout << endl;
  system("pause");


}

void MorsetoAlpha()
{
  string stringMorseString;
  string stringTempMorse = "";
  int n;
  //int intCharCounter = 0;

  system("cls");
  cout << "Please type in a sentence to convert to Morse Code." << endl << "Use a single space between each Morse character and a double space between words: " << endl;
  cin.ignore();
  getline(cin,stringMorseString);

  system("cls");
  cout << "Morse Code:" << endl;
  cout << stringMorseString << endl << endl;
  cout << "Alpha Numeric:" << endl;

  for (n=0;n<(stringMorseString.size());n++)
  {
//cout << "Character : "<< n << "\"" << stringMorseString[n] << "\"";
      if ((stringMorseString[n] != ' ') && (stringTempMorse.size() < 6))
      {
        stringTempMorse+=stringMorseString[n];

        //intCharCounter++;
      }
      else
      {
        cout << CharacaterChanger(stringTempMorse) << " ";
        stringTempMorse.clear();
        //intCharCounter = 0;
      }
      if (n == (stringMorseString.size() - 1))
      {
        //cout << "end string process: ";
        //stringTempMorse+=stringMorseString[n];
        cout << CharacaterChanger(stringTempMorse) << endl;
      }

  }
  system("pause");

}

string CharacaterChanger(string charTestString)
{
//Utter garbage but quick and dirty for getting the job done.

  if (charTestString ==  ".-")
  {
    return "A";
  }
  else if (charTestString ==  "-...")
  {
    return "B";
  }
  else if (charTestString ==  "-.-.")
  {
    return "C"    ;
  }
  else if (charTestString ==  "-..")
  {
    return "D"    ;
  }
  else if (charTestString ==  ".")
  {
    return "E"    ;
  }
  else if (charTestString ==  "..-.")
  {
    return "F"    ;
  }
  else if (charTestString ==  "--.")
  {
    return "G";
  }
  else if (charTestString ==  "....")
  {
    return "H";
  }
  else if (charTestString ==  "..")
  {
    return "I";
  }
  else if (charTestString ==  ".---")
  {
    return "J";
  }
  else if (charTestString ==  "-.-")
  {
    return "K";
  }
  else if (charTestString ==  ".-..")
  {
    return "L";
  }
  else if (charTestString ==  "--")
  {
    return "M";
  }
  else if (charTestString ==  "-.")
  {
    return "N";
  }
  else if (charTestString ==  "---")
  {
    return "O";
  }
  else if (charTestString ==  ".--.")
  {
    return "P";
  }
  else if (charTestString ==  "--.-")
  {
    return "Q";
  }
  else if (charTestString ==  ".-.")
  {
    return "R";
  }
  else if (charTestString ==  "...")
  {
    return "S";
  }
  else if (charTestString ==  "-")
  {
    return "T";
  }
  else if (charTestString ==  "..-")
  {
    return "U";
  }
  else if (charTestString ==  "...-")
  {
    return "V";
  }
  else if (charTestString ==  ".--")
  {
    return "W";
  }
  else if (charTestString ==  "-..-")
  {
    return "X";
  }
  else if (charTestString ==  "-.--")
  {
    return "Y";
  }
  else if (charTestString ==  "__..")
  {
    return "Z";
  }
  else if (charTestString ==  ".----")
  {
    return "1";
  }
  else if (charTestString ==  "..---")
  {
    return "2";
  }
  else if (charTestString ==  "...--")
  {
    return "3";
  }
  else if (charTestString ==  "....-")
  {
    return "4";
  }
  else if (charTestString ==  ".....")
  {
    return "5";
  }
  else if (charTestString ==  "-....")
  {
    return "6";
  }
  else if (charTestString ==  "--...")
  {
    return "7";
  }
  else if (charTestString ==  "---..")
  {
    return "8";
  }
  else if (charTestString ==  "----.")
  {
    return "9";
  }
  else if (charTestString ==  "----")
  {
    return "0";
  }
  else
  {
    return "";
  }
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
    case ' ' :
      return " ";
      break;
    default :
      return "";
      break;

  }
}
