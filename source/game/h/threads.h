#pragma once

#include <Windows.h>
#include <process.h>

namespace threads
{
   template <class TData>
   class CThread
   {
   public:
      typedef void (TData::*TFoo)();
      CThread(TData& data_, TFoo func_) : data(data_), func(func_)
      {
         process = (HANDLE) _beginthread(_callback, 0, this);
      }

   private:
      TData& data;
      TFoo func;
      HANDLE process;

      static void __cdecl _callback( void* data )
      {
         CThread& thread = *(CThread*) data;
         ((thread.data).*(thread.func))();
      }

   };

}
