#pragma once

#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)

#ifdef UI_EXPORT_DLL
   #define UI_EXPORT DllExport
#else
   #define UI_EXPORT DllImport
#endif
