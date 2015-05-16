#pragma once

#include <memory>
#include "PositionTypes.h"

namespace objects
{
	class IPositionBehavior
	{
	public:
      typedef std::shared_ptr< IPositionBehavior > Ptr;
      virtual TPositionType getPositionType() const = 0;
	};
}
