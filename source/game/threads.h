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
      CThread(TData* data_, TFoo func_) : data(data_), func(func_)
      {
         threadId = (HANDLE) _beginthreadex(0, 0, _callback, this, 0, 0);
      }
      ~CThread()
      {
         WaitForSingleObject( threadId, INFINITE );
         CloseHandle( threadId );
      }

   private:
      TData* data;
      TFoo func;
      HANDLE threadId;

      static unsigned int __stdcall _callback( void* data )
      {
         CThread& thread = *(CThread*) data;
         ((thread.data)->*(thread.func))();
         _endthreadex(0);
         return 0;
      }

   };

}
