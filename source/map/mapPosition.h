#pragma once

#include "objects\IPosition.h"
#include "TCoords.h"
#include "objects\IObject.h"
#include "map.h"

namespace game_engine
{
	class CMapPosition : public IPosition
	{
	public:
	   virtual TPositionType getPositionType() const override final;

      CMapPosition( IObject::Ptr, CMap::Ptr, const TCoords& );
      ~CMapPosition();

      const TCoords& getCoords() const;
      CMap::Ptr getMap();
      void setCoords( const TCoords& );

   private:
      IObject::Ptr getObject();

   private: // data
      const IObject::WeakPtr object;
      const CMap::WeakPtr map;
      TCoords coords;
	};
}
