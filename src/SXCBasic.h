#pragma once

/*
	Reference: https://dev.to/tenry/predefined-c-c-macros-43id
*/

// platform
#if _WIN32 || _WIN64
#define WINDOWS 1
#elif defined(__linux__) && !defined(__ANDROID__)
#define LINUX 1 
#elif __ANDROID__
#define ANDROID 1
#elif !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#define UNIX 1
#elif ARM9
#define NDS 1 //!!
#elif _3DS
#define N3DS 1
#elif __SWITCH__
#define NS 1
#endif 


// compiler
#if _MSC_VER
#define VS 1
#elif __GNUC__
#define GCC 1
#elif __clang__
#define CLANG 1
#elif __EMSCRIPTEN__
#define EMSC 1
#endif 

#include<tuple>

namespace sxc {

	template<typename... Types>
	using _pkg = std::tuple<Types...>;

	template<typename... Types>
	constexpr auto _pack(Types&&... Args) { return std::make_tuple(Args...); }

}