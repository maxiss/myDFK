#pragma once

#include <memory>
#include "PositionTypes.h"

namespace game_engine
{
	class IPosition
	{
	public:
      typedef std::shared_ptr< IPosition > Ptr;
      virtual TPositionType getPositionType() const = 0;
	};
}
