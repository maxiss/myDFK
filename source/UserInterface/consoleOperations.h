#pragma once

void hideConsoleCursor();
void gotoXY( int x, int y );
void clearRectangle( int x1, int y1, int x2, int y2 );
int getKey();
void SetColor( int text, int background );

enum ConsoleColor
{
   Black = 0,
   Blue = 1,
   Green = 2,
   Cyan = 3,
   Red = 4,
   Magenta = 5,
   Brown = 6,
   LightGray = 7,
   DarkGray = 8,
   LightBlue = 9,
   LightGreen = 10,
   LightCyan = 11,
   LightRed = 12,
   LightMagenta = 13,
   Yellow = 14,
   White = 15
};
