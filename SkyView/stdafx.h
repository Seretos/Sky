// stdafx.h: Includedatei f�r Standardsystem-Includedateien
// oder h�ufig verwendete projektspezifische Includedateien,
// die nur in unregelm��igen Abst�nden ge�ndert werden.
//

#pragma once

#include "targetver.h"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN             // Selten verwendete Komponenten aus Windows-Headern ausschlie�en
#define _CRT_SECURE_NO_WARNINGS
// Windows-Headerdateien:
#include <windows.h>
#else
#include <cstddef>
#endif

#define ALLEGRO_NO_MAGIC_MAIN

// TODO: Hier auf zus�tzliche Header, die das Programm erfordert, verweisen.
