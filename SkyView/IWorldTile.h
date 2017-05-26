#pragma once
#if defined(_WIN32)
#ifdef IWORLDTILE_EXPORTS
#define IWORLDTILE_API __declspec(dllexport)
#else
#define IWORLDTILE_API __declspec(dllimport)
#endif
#else
#define IWORLDTILE_API
#endif

class IWorldTile {
public:
	virtual int getFoodValue() = 0;
};