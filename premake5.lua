workspace "Black"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "Black/Vendor/Glad/include"
IncludeDir["ImGui"] = "Black/Vendor/ImGui"
IncludeDir["glm"] = "Black/Vendor/glm"


group "Dependencies"
include "Black/Vendor/GLFW"
include "Black/Vendor/Glad"
include "Black/Vendor/ImGui"
group ""

project "Black"
	location "Black"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "bpch.h"
	pchsource "Black/src/bpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/Vendor/glm/glm/**.inl",
		"%{prj.name}/Vendor/glm/glm/**.hpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"	
		systemversion "latest"

		defines
		{
			"BLACK_PLATFORM_WINDOWS",
			"BLACK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		--[[ Used for Dynamically linking
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}]]--
		

	filter "configurations:Debug"
		defines 
		{
			"BLACK_DEBUG",
			"BLACK_ENABLE_ASSERT"
		}
	
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BLACK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BLACK_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Black/src",
		"Black/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Black"
	}

	filter "system:windows"
		
		systemversion "latest"

		defines
		{
			"BLACK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BLACK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BLACK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BLACK_DIST"
		runtime "Release"
		optimize "on"