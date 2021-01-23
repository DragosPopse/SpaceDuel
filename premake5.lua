
local OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


workspace "SpaceDuel"
    configurations 
    {
        "Debug",
        "Release"
    }
    platforms
    {
        "Win32",
        "Win64"
    }

    defines
    {
        "NOMINMAX",
        "SDL_MAIN_HANDLED"
    }

    language "C++"
    cppdialect "C++17"
    systemversion "latest"
    flags { 
        "MultiProcessorCompile" -- faster compile time
    }
    warnings "Extra" -- as requested by the project brief
    startproject "Raytracer"
   

    filter "configurations:Debug"
        symbols "On"
        runtime "Debug"
    
    filter "configurations:Release"
        optimize "Full"
        runtime "Release"

    filter "platforms:Win32"
        architecture "x86"
        libdirs
        {
            "%{wks.solution}/external/lib/x86"
        }
        debugenvs 
        {
            "PATH=$(SolutionDir)/external/bin/x86;%PATH%"
        }
    
    filter "platforms:Win64"
        architecture "x86_64"
        libdirs
        {
            "%{wks.solution}/external/lib/x86_64"
        }
        debugenvs 
        {
            "PATH=$(SolutionDir)/external/bin/x86_64;%PATH%"
        }
        -- buildoptions { "/bigobj" } -- In case the code uses too many templates :) activate on a per-need basis
    

    project "SpaceDuel"
        location "%{wks.location}/"
        kind "ConsoleApp"
        buildoptions{"/openmp"}

        targetdir("bin/" .. OutputDir .. "/%{prj.name}")
        objdir("bin-int/" .. OutputDir .. "/%{prj.name}")
    
        includedirs
        {
            "%{prj.location}/include",
            "GameMath/include",
            "%{wks.location}/external/include"
        }

        files
        {
            "%{prj.location}/src/**.cpp",
            "%{prj.location}/include/**.hpp",
            "%{prj.location}/include/**.h"
        }

        filter "configurations:Debug"
            links 
            {
                "opengl32",
                "glew32",
                "SDL2"          
            }

        filter "configurations:Release"
            links 
            {
                "opengl32",
                "glew32",
                "SDL2",  
            }
        


