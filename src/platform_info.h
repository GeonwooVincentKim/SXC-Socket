#pragma once

/*
	Reference: https://dev.to/tenry/predefined-c-c-macros-43id
*/

// platform
#if _WIN32 || _WIN64
#define WINDOWS
#elif defined(__linux__) && !defined(__ANDROID__)
#define LINUX
#elif __ANDROID__
#define ANDROID
#elif !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#define UNIX
#elif ARM9
#define NDS //!!
#elif _3DS
#define N3DS
#elif __SWITCH__
#define NS
#endif 


// compiler
#if _MSC_VER
#define VS
#elif __GNUC__
#define GCC
#elif __clang__
#define CLANG
#elif __EMSCRIPTEN__
#define EMSC
#endif 