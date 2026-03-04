#pragma once
//HERE IT COMES... THE IMGUI meowgine too

#ifdef MG_WINDOWS
#if MG_DYN_LINK
	#ifdef MG_BUILD_DLL
		#define MG_API __declspec(dllexport)
	#else
		#define MG_API __declspec(dllimport)
	#endif
#else
	#define MG_API
#endif
#else
#error Meowgine right now is only on windows.
#endif

#ifdef MG_DEBUG
	#define MG_ENABLE_ASSERTS
#endif

#ifdef MG_ENABLE_ASSERTS
#define MG_ASSERT(x, ...) {if(!(x)) { MG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#define MG_CORE_ASSERT(x, ...) {if(!(x)) { MG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define MG_ASSERT(x, ...)
#define MG_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)
#define MG_BIND_EVENT(arg) std::bind(&arg,this,std::placeholders::_1)