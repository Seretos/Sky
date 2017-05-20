#pragma once
#ifdef CWINDOW_EXPORTS
#define CWINDOW_API __declspec(dllexport) 
#else
#define CWINDOW_API __declspec(dllimport) 
#endif

class CWindow {
protected:
};