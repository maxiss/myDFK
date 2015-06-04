#pragma once

namespace game_engine
{
   enum class TObjectType
   {
      all,
      item,
      creature,
      building,
   };

   inline bool matchObjectType( TObjectType left, TObjectType right )
   {
      return ( left == TObjectType::all ||
               right == TObjectType::all ||
               left == right );
   }
}
