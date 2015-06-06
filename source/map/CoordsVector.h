#pragma once

#include <vector>
#include "Coords.h"

namespace game_engine
{
   template <class T>
   class CCoordsVector : public std::vector< T >
   {
   public:
      CCoordsVector( const Coords& min, const Coords& max );
      T& operator[]( const Coords& );
      const T& operator[]( const Coords& ) const;

   private:
      size_t convert( const Coords& ) const;

   private:
      const Coords min, max;
      const size_t size_y;
   };

   template <class T>
   CCoordsVector<T>::CCoordsVector( const Coords& min_, const Coords& max_ )
      : std::vector<T>( (max_.x - min_.x + 1) * (max_.y - min_.y + 1) )
      , min( min_ ), max( max_ )
      , size_y( max.x - min.x + 1 )
   {}

   template <class T>
   T& CCoordsVector<T>::operator[]( const Coords& coords )
   {
      return std::vector<T>::operator[]( convert( coords ) );
   }

   template <class T>
   const T& CCoordsVector<T>::operator[]( const Coords& coords ) const
   {
      return std::vector<T>::operator[]( convert( coords ) );
   }

   template <class T>
   size_t CCoordsVector<T>::convert( const Coords& coords ) const
   {
      return ( (coords.y - min.y) * size_y + (coords.x - min.x) );
   }
}
