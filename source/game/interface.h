#pragma once

#include "game_export.h"
#include "IGame.h"

extern "C++"
{
   GAME_EXPORT game_engine::IGame::Ptr startGame();
}
