/* The Matrix  falling numbers */

#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;


#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define KB_F8 66


/* Variables*/

char screen_buffer[2000]={' '};
int y_coord[2000]={0};
int x=0, y=0,dy=0;
int XMAX=77;
int YMAX=23;
int KB_code=0;
bool QuitGame=false;
int platformX=35, platformY=23;

/* function prototypes*/

void gotoxy(int x, int y);
void clrscr(void);
void setcolor(WORD color);
void simple_keyboard_input();
void draw_falling_numbers();
void draw_platform();

/*  main  */

int main(void)
{
  /* generate random seed */
  srand ( time(NULL) );

  /* generate random number*/
  for(int i=0;i<XMAX;i++) y_coord[i]=   rand() % YMAX;

  while(!QuitGame)
  {
      /* simple keyboard input */
      simple_keyboard_input();

      /* draw falling numbers */
      draw_falling_numbers();

  }

  /* restore text color */
  setcolor(7);
  clrscr( );
  cout<<" \n";

  cout<<" \nPress any key to continue\n";
  cin.ignore();
  cin.get();

   return 0;
}

/* functions  */

void draw_falling_numbers()
{

    for(x=0;x<=XMAX;x++)
    {
        /* generate random number */
        int MatixNumber=rand() % 2 ;

        /* update falling number */
        y_coord[x]=y_coord[x]+1;

        if (y_coord[x]>YMAX) y_coord[x]=0;

        /* draw dark color */
        setcolor(2);
        gotoxy(x ,y_coord[x]-1); cout<<"  "<<MatixNumber<<"   ";

        /* draw light color */
        setcolor(10);
        gotoxy(x ,y_coord[x]); cout<<"  "<<MatixNumber<<"   ";
    }
    /* wait some milliseconds */
    Sleep(50);
    //clrscr( );
}


void draw_platform()
{
  setcolor(7);
 gotoxy(platformX ,platformY);cout<<"       ";

 gotoxy(platformX ,platformY);cout<<"ÜÜÜÜÜÜ";
 setcolor(7);
 Sleep(5);
}




void simple_keyboard_input()
{
    if (kbhit())
      {
            KB_code = getch();
            //cout<<"KB_code = "<<KB_code<<"\n";

            switch (KB_code)
            {

                case KB_ESCAPE:

                    QuitGame=true;

                break;

                case KB_LEFT:
                           //Do something
                    platformX=platformX-4;if(platformX<3) platformX=3;
                break;

                case KB_RIGHT:
                           //Do something
                    platformX=platformX+4;if(platformX>74) platformX=74;
                break;

                case KB_UP:
                           //Do something
                break;

                case KB_DOWN:
                           //Do something
                break;

            }

      }

}


void setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    return;
}


void gotoxy(int x, int y)
{
  static HANDLE hStdout = NULL;
  COORD coord;

  coord.X = x;
  coord.Y = y;

  if(!hStdout)
  {
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  }

  SetConsoleCursorPosition(hStdout,coord);
}


void clrscr(void)
{
  static HANDLE hStdout = NULL;
  static CONSOLE_SCREEN_BUFFER_INFO csbi;
  const COORD startCoords = {0,0};
  DWORD dummy;

  if(!hStdout)
  {
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout,&csbi);
  }

  FillConsoleOutputCharacter(hStdout,
                             ' ',
                             csbi.dwSize.X * csbi.dwSize.Y,
                             startCoords,
                             &dummy);
  gotoxy(0,0);
}
