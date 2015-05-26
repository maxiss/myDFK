#pragma once

#include <memory>
#include "objects\IObject.h"

namespace game
{
	class IUserInterface
	{
	public:
      std::shared_ptr< IUserInterface > Ptr;
      virtual objects::IObject::Ptr selectObject( const objects::TObjectList& ) = 0;
	};
}
