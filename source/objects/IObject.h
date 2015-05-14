#pragma once

#include <memory>
#include <list>
#include "ObjectTypes.h"
#include "map\point.h"

namespace objects
{
   class IObject
   {
   public:
      typedef std::shared_ptr< IObject > Ptr;
      typedef std::shared_ptr< const IObject > ConstPtr;
      typedef const IObject* const RawPtr;

      IObject() : coords( gamemap::TCoords{ 0, 0 } ) {}
      virtual TObjectType getObjectType() const = 0;

      const gamemap::TCoords& getCoords() { return coords; }
      void setCoords( const gamemap::TCoords& coords_ ) { coords = coords_; }

   private:
      gamemap::TCoords coords; // !!! maybe remove ???
   };

   typedef std::list< IObject::Ptr > TObjectList;
   typedef std::list< IObject::ConstPtr > TConstObjectList;
}
