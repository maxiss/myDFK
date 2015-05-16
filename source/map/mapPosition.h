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

      CMapPosition( objects::IObject::Ptr, const TCoords& );

      const TCoords& getCoords() const;
      void setCoords( const TCoords& );

   private:
      gamemap::CMap& getMap() const;

   private: // data
      TCoords coords;
      const objects::IObject::WeakPtr object;
	};
}
