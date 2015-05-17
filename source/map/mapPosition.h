#pragma once

#include "objects\IPositionBehavior.h"
#include "TCoords.h"
#include "objects\IObject.h"
#include "map.h"

namespace gamemap
{
	class CMapPosition : public objects::IPositionBehavior
	{
	public:
	   virtual objects::TPositionType getPositionType() const override final;

      CMapPosition( objects::IObject::Ptr, gamemap::CMap::Ptr, const TCoords& );
      ~CMapPosition();

      const TCoords& getCoords() const;
      gamemap::CMap::Ptr getMap();
      void setCoords( const TCoords& );

   private:
      objects::IObject::Ptr getObject();

   private: // data
      const objects::IObject::WeakPtr object;
      const gamemap::CMap::WeakPtr map;
      TCoords coords;
	};
}
