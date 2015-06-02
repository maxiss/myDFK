#pragma once

#include <memory>
#include "objects\INameable.h"

namespace game
{
	class IUserInterface
	{
	public:
      typedef std::shared_ptr< IUserInterface > Ptr;
      virtual objects::INameable::Ptr select( const objects::TNameableVector& ) = 0;
	};
}
