#pragma once

#include "game\IUserInterface.h"

namespace user_interface
{
	class CConsoleUI final
      : virtual public game_engine::IUserInterface
	{
	public:
      static CConsoleUI& Instance();
      void start();
      virtual game_engine::INameable::Ptr select( const game_engine::NameableVector& ) override final;

   private:
      CConsoleUI();
   };
}
