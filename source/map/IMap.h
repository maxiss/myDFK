#pragma once

#include <memory>
#include <list>
#include "game/game_export.h"
#include "mapData.h"

namespace game_engine
{
	struct TMapPoint
	{
	   Coords coords;
	   StructureType structureType;
	   ConstObjectList objectList;
	};
	
	typedef std::list< TMapPoint > MapPointList;
	
	class GAME_EXPORT IMap
	{
	public:
	   typedef std::shared_ptr< const IMap > ConstPtr;
      virtual MapPointList getMapPositionList() const = 0;
      virtual MapPointList getMapChanges() const = 0;
	};
}
