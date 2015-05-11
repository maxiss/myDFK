#pragma once

#include "map\object.h"

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
