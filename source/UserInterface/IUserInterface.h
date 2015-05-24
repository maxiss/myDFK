#pragma once

#include <memory>

namespace user_interface
{
	class IUserInterface
	{
	public:
      std::shared_ptr< IUserInterface > Ptr;
      virtual void start() = 0;
	
	};
}
