#pragma once

#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)

#ifdef UI_EXPORT
#define UI_EXPORT_DLL DllExport
#else
#define UI_EXPORT_DLL DllImport
#endif

extern "C"
{
   UI_EXPORT_DLL void startUI();
}
