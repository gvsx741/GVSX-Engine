#pragma once 

#ifdef ENGINE_API
#define ENGINE_API __declspec(dllimport)
#else
#define ENGINE_API __declspec(dllexport)
#endif