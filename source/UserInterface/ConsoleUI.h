#pragma once

#include "IUserInterface.h"

namespace user_interface
{
	class CConsoleUI : public IUserInterface
	{
	public:
      virtual void start() override final;

   };
}
