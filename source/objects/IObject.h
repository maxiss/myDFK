#pragma once

#include <memory>
#include <list>
#include "ObjectTypes.h"
#include "map\Coords.h"
#include "IPosition.h"
#include "INameable.h"

namespace game_engine
{
   class IObject
      : virtual public INameable
   {
   public:
      typedef std::shared_ptr< IObject > Ptr;
      typedef std::shared_ptr< const IObject > ConstPtr;
      typedef std::weak_ptr< IObject > WeakPtr;
      typedef std::weak_ptr< const IObject > ConstWeakPtr;
      typedef const IObject* RawPtr;

      virtual ObjectType getObjectType() const = 0;

      IPosition::Ptr getPosition() const { return position; }
      void setPosition( IPosition::Ptr position_ ) { position = position_; }

   protected:
      IPosition::Ptr position;
   };

   typedef std::list< IObject::Ptr > ObjectList;
   typedef std::list< IObject::ConstPtr > ConstObjectList;
}
