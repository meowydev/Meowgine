workspace "Meowgine"
	configurations { "Debug", "Release", "Dist" }
	architecture "x64"
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Meowgine/vendor/GLFW/include"
IncludeDir["GLAD"] = "Meowgine/vendor/GLAD/include"
IncludeDir["IMGUI"] = "Meowgine/vendor/imgui"
IncludeDir["GLM"] = "Meowgine/vendor/glm"

include "Meowgine/vendor/GLFW"
include "Meowgine/vendor/GLAD"
include "Meowgine/vendor/imgui"

project "Meowgine"
	location "Meowgine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "mgpch.h"
	pchsource "Meowgine/src/mgpch.cpp"
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/Platform/**.h",
		"%{prj.name}/src/Platform/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}",
		"%{IncludeDir.GLM}"
	}
	
	links {
		"GLFW",
		"opengl32.lib",
		"GLAD",
		"imgui"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MG_WINDOWS",
			"MG_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"_CRT_SECURE_NO_WARNINGS"
		}
	
	filter "configurations:Debug"
		defines "MG_DEBUG"
		buildoptions "/MTd"
		symbols "On"
			
	filter "configurations:Release"
		defines "MG_RELEASE"
		buildoptions "/MT"
		optimize "On"
			
	filter "configurations:Dist"
		defines "MG_DIST"
		buildoptions "/MT"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Meowgine/vendor/spdlog/include",
		"Meowgine/src",
		"%{IncludeDir.GLM}",
		"Meowgine/vendor"
	}
	
	links
	{
		"Meowgine"
	}
	
	filter "system:windows"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"MG_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "MG_DEBUG"
		buildoptions "/MTd"
		symbols "On"
			
	filter "configurations:Release"
		defines "MG_Release"
		buildoptions "/MT"
		optimize "On"
			
	filter "configurations:Dist"
		defines "MG_DIST"
		buildoptions "/MT"
		optimize "On"
		