workspace "Eren"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Eren"
	location "Eren"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/3rdPartyLibs/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"EREN_PLATFORM_WINDOWS", 
			"EREN_BUILD_DLL"	
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/" )
		}

	filter "configurations:Debug"
		defines {
			"EREN_DEBUG"
		}	
		symbols "On"

	filter "configurations:Release"
		defines {
			"EREN_RELEASE"

		}	
		optimize "On"
	
	filter "configurations:Distribution"
		defines {
			"EREN_DISTRIB"

		}	
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Eren/src",
		"Eren/3rdPartyLibs/spdlog/include"

	}

	links {
		"Eren"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"EREN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines {
			"EREN_DEBUG"
		}	
		symbols "On"

	filter "configurations:Release"
		defines {
			"EREN_RELEASE"

		}	
		optimize "On"
	
	filter "configurations:Distribution"
		defines {
			"EREN_DISTRIB"

		}	
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"
