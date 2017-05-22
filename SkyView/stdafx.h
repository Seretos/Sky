// stdafx.h: Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once

#include "targetver.h"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN             // Selten verwendete Komponenten aus Windows-Headern ausschließen
#define _CRT_SECURE_NO_WARNINGS
// Windows-Headerdateien:
#include <windows.h>
#else
#include <cstddef>
#endif

#define ALLEGRO_NO_MAGIC_MAIN

// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
