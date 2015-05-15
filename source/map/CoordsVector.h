#pragma once
#include "point.h"

namespace gamemap
{
   template <class T>
   class CCoordsVector : public std::vector< T >
   {
   public:
      CCoordsVector( const TCoords& min, const TCoords& max );
      T& operator[]( const TCoords& );
      const T& operator[]( const TCoords& ) const;

   private:
      size_t convert( const TCoords& ) const;

   private:
      const TCoords min, max;
      const size_t size_y;
   };

   template <class T>
   CCoordsVector<T>::CCoordsVector( const TCoords& min_, const TCoords& max_ )
      : std::vector<T>( (max_.x - min_.x + 1) * (max_.y - min_.y + 1) )
      , min( min_ ), max( max_ )
      , size_y( max.x - min.x + 1 )
   {}

   template <class T>
   T& CCoordsVector<T>::operator[]( const TCoords& coords )
   {
      return std::vector<T>::operator[]( convert( coords ) );
   }

   template <class T>
   const T& gamemap::CCoordsVector<T>::operator[]( const TCoords& coords ) const
   {
      return std::vector<T>::operator[]( convert( coords ) );
   }

   template <class T>
   size_t CCoordsVector<T>::convert( const TCoords& coords ) const
   {
      return ( (coords.y - min.y) * size_y + (coords.x - min.x) );
   }
}
