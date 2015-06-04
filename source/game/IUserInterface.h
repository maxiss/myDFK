#pragma once

#include <memory>
#include "objects\INameable.h"

namespace game_engine
{
	class IUserInterface
	{
	public:
      typedef std::shared_ptr< IUserInterface > Ptr;
      virtual INameable::Ptr select( const TNameableVector& ) = 0;
	};
}
