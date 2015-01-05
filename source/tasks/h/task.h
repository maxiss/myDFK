#pragma once

#include "map\h\object.h"

namespace tasks
{
   using namespace gamemap;

   class CTask
   {
   };

   class CMoveTask
   {
   public:
      CObject* object;
      TPoint point;

   };

}
