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
      virtual objects::IObject::Ptr selectObject( const objects::TObjectList& ) override final;

   private:
      CConsoleUI();
   };
}
