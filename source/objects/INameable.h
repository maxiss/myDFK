#pragma once

#include <memory>
#include <string>
#include <vector>

namespace game_engine
{
   class INameable
   {
   public:
      typedef std::shared_ptr< INameable > Ptr;
      virtual std::string getName() const = 0;
   };

   typedef std::vector< INameable::Ptr > TNameableVector;

   template <class T>
   TNameableVector makeNameableVector( const T& input )
   {
      TNameableVector retVal;
      for ( const auto& it : input )
      {
         auto& item = std::dynamic_pointer_cast<INameable>( it );
         retVal.push_back( item );
      }
      return retVal;
   }
}
