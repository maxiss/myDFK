#pragma once

#include "game\IUserInterface.h"

namespace user_interface
{
	class CConsoleUI final
      : virtual public game::IUserInterface
	{
	public:
      static CConsoleUI& Instance();
      void start();
      virtual objects::INameable::Ptr select( const objects::TNameableVector& ) override final;

   private:
      CConsoleUI();
   };
}
