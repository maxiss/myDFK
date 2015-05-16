#pragma once

#include "map.h"

namespace gamemap
{
   class Map
   {
   public:
      static Map& Intance();
      void setMap( CMap* );
      CMap& getMap();

   private:
      Map();

   private: // data
      CMap* map;

   };

}
