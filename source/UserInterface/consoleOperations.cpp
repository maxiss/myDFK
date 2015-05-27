#include "consoleOperations.h"

#include <Windows.h>
#include <stdio.h>
#include <conio.h>

void hideConsoleCursor()
{
   HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
   CONSOLE_CURSOR_INFO cInfo;
   GetConsoleCursorInfo( hOuput, &cInfo );
   cInfo.bVisible = false;
   SetConsoleCursorInfo( hOuput, &cInfo );
}

void gotoXY( int x, int y )
{
   COORD scrn = { x, y };
   HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
   SetConsoleCursorPosition( hOuput, scrn );
}

void clearRectangle( int x1, int y1, int x2, int y2 )
{
   const int STR_LEN = 81;
   char str[ STR_LEN ];
   memset( str, 32, STR_LEN ); str[STR_LEN - 1] = '\0';
   str[ x2 - x1 + 1 ] = '\0';
   int num = y2 - y1 + 1;
   for ( int i = 0; i < num; i++ )
   {
      gotoXY( x1, y1 + i );
      printf( "%s", str ); // !!!
   }
}

int getKey()
{
   return _getch();
}

void SetColor( int text, int background )
{
   HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
   SetConsoleTextAttribute( hStdOut, (WORD) ((background << 4) | text) );
}
