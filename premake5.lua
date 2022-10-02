workspace "Black"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Black/Vendor/GLFW/include"


include "Black/Vendor/GLFW"

project "Black"
	location "Black"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "bpch.h"
	pchsource "Black/src/bpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BLACK_PLATFORM_WINDOWS",
			"BLACK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines 
		{
			"BLACK_DEBUG",
			"BLACK_ENABLE_ASSERT"
		}
		symbols "On"

	filter "configurations:Release"
		defines "BLACK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLACK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Black/Vendor/spdlog/include",
		"Black/src"
	}

	links
	{
		"Black"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BLACK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BLACK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLACK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLACK_DIST"
		optimize "On"