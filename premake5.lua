workspace "Eren"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Distribution"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "Eren/3rdPartyLibs/glfw/include"

include "Eren/3rdPartyLibs/glfw"

project "Eren"
	location "Eren"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "erenpch.h"
	pchsource "Eren/src/erenpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/3rdPartyLibs/spdlog/include",
		"%{IncludeDir.glfw}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		defines "EREN_BUILD_DLL"	

--		postbuildcommands {
--			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/" )
--		}

	filter "configurations:Debug"
		defines "EREN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "EREN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EREN_DIST"
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

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Eren/src",
		"Eren/3rdPartyLibs/spdlog/include",
		"Eren/vendor"
	}

	links {
		"Eren"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "EREN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EREN_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "EREN_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"