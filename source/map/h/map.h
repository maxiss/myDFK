#pragma once

#include <map>
#include "point.h"
#include "object.h"

namespace map
{
   typedef std::multimap< TPoint, CObject > TMap;

   class CMap
   {
   private:
      TMap content;

   };

}