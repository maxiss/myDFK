#pragma once

#include "threads.h"
#include <process.h>
#include <Windows.h>

namespace threads
{
   typedef unsigned int (__stdcall * TFoo)(void*);

   template <class TData>
   class CThread
   {
   public:
      typedef void (*TThreadFunc)(TData*);
      CThread(TThreadFunc func, TData* data);

   private:
      TThreadFunc func;
      TData* data;
      HANDLE process;
      static unsigned __stdcall _callback( void* data );

   };

   template <class TData>
   CThread<TData>::CThread( TThreadFunc func_, TData* data_ )
    : func(func_), data(data_)
   {
      process = (HANDLE) _beginthreadex( NULL, 0, (TFoo)(_callback), this, 0, 0 );
   }

   template <class TData>
   static unsigned __stdcall CThread<TData>::_callback( void* data )
   {
      CThread<TData>& thread = *(CThread<TData>*) data;
      (thread.func)(thread.data);
      return 0;
   }

}



