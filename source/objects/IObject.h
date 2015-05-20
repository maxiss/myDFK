#pragma once

#include <memory>
#include <list>
#include "ObjectTypes.h"
#include "map\TCoords.h"
#include "IPositionBehavior.h"

namespace objects
{
   class IObject
   {
   public:
      typedef std::shared_ptr< IObject > Ptr;
      typedef std::shared_ptr< const IObject > ConstPtr;
      typedef std::weak_ptr< IObject > WeakPtr;
      typedef std::weak_ptr< const IObject > ConstWeakPtr;
      typedef const IObject* RawPtr;

      virtual TObjectType getObjectType() const = 0;

      IPositionBehavior::Ptr getPosition() const { return position; }
      void setPosition( IPositionBehavior::Ptr position_ ) { position = position_; }

   protected:
      IPositionBehavior::Ptr position;
   };

   typedef std::list< IObject::Ptr > TObjectList;
   typedef std::list< IObject::ConstPtr > TConstObjectList;
}
