workspace "LeetCodeCpp"
    architecture "x64"
	startproject "LeetCodeCpp"
	configurations
    {
        "Debug",
        "Release"
    }
	outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"
	Macro ={}
    Macro["DebugMode"]="AQ_DEBUG"
    Macro["Windows"]="AQ_PLATFORM_WINDOWS"
    Macro["VS_NoWarning"]="_CRT_SECURE_NO_WARNINGS"

	IncludeDir ={}
	IncludeDir["nlohmannjson"] ="LeetCodeCpp/vendor/nlohmannjson/include"

	Lib ={}  


	project "LeetCodeCpp"
        location "LeetCodeCpp"
        kind "ConsoleApp"
        language "C++"

        staticruntime "on"
    

        targetdir ("bin/" .. outputdir.. "/%{prj.name}")
        objdir ("bin-inter/" .. outputdir.. "/%{prj.name}")


        pchheader "PCH.h"
        pchsource "%{prj.name}/source/PCH.cpp"
		
		includedirs
        {
            "%{prj.name}/source/",
			IncludeDir.nlohmannjson,
		}
		
		files
        {
            "%{prj.name}/source/**.h",
            "%{prj.name}/source/**.cpp",
		}

		filter "system:windows"
            cppdialect "C++20"
            systemversion "latest"