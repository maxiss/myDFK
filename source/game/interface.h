#pragma once

#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)

#ifdef EXPORTS
   #define DLLEXPORT DllExport
#else
   #define DLLEXPORT DllImport
#endif

#include "game.h"

extern "C++"
{
   DLLEXPORT game::CGame::Ptr startGame();
}
