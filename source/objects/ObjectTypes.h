#pragma once

namespace game_engine
{
   enum class ObjectType
   {
      All,
      Item,
      Creature,
      Building,
   };

   inline bool matchObjectType( ObjectType left, ObjectType right )
   {
      return ( left == ObjectType::All ||
               right == ObjectType::All ||
               left == right );
   }
}
