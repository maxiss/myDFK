#pragma once

#include "objects\IPosition.h"
#include "Coords.h"
#include "objects\IObject.h"
#include "map.h"

namespace game_engine
{
	class CMapPosition : public IPosition
	{
	public:
	   virtual PositionType getPositionType() const override final;

      CMapPosition( IObject::Ptr, CMap::Ptr, const Coords& );
      ~CMapPosition();

      const Coords& getCoords() const;
      CMap::Ptr getMap();
      void setCoords( const Coords& );

   private:
      IObject::Ptr getObject();

   private: // data
      const IObject::WeakPtr object;
      const CMap::WeakPtr map;
      Coords coords;
	};
}
