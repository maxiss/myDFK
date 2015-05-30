#pragma once

#include "objects\IPosition.h"
#include "TCoords.h"
#include "objects\IObject.h"
#include "map.h"

namespace gamemap
{
	class CMapPosition : public objects::IPosition
	{
	public:
	   virtual objects::TPositionType getPositionType() const override final;

      CMapPosition( objects::IObject::Ptr, CMap::Ptr, const TCoords& );
      ~CMapPosition();

      const TCoords& getCoords() const;
      CMap::Ptr getMap();
      void setCoords( const TCoords& );

   private:
      objects::IObject::Ptr getObject();

   private: // data
      const objects::IObject::WeakPtr object;
      const CMap::WeakPtr map;
      TCoords coords;
	};
}
