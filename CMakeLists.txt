cmake_minimum_required(VERSION 3.00)

project(Ashley)

if (CMAKE_SIZEOF_VOID_P MATCHES 8)
	set( PROJECT_ARCH "x64" )
else(CMAKE_SIZEOF_VOID_P MATCHES 8)
	set( PROJECT_ARCH "x86" )
endif(CMAKE_SIZEOF_VOID_P MATCHES 8)

# FFmpeg

set(FFmpeg "./ThirdParty/FFmpeg" CACHE PATH "Root of FFmpeg library")

foreach (lib "avformat" "avcodec" "avutil" "swscale" "avformat" "postproc" "avdevice" "swresample")

	# Library files
	find_library(${lib}_LIB_RELEASE "${lib}" PATH ${FFmpeg}/lib)
	if (NOT ${lib}_LIB_RELEASE)
		message(FATAL_ERROR "Could not find release version of library \"${lib}\"")
	endif()

	find_library(${lib}_LIB_DEBUG "${lib}" PATH ${FFmpeg}/lib)
	if (NOT ${lib}_LIB_DEBUG)
		message(FATAL_ERROR "Could not find debug version of library \"${lib}\"")
	endif()

	target_link_libraries(${PROJECT_NAME} PUBLIC 
		$<$<CONFIG:Release>:${${lib}_LIB_RELEASE}>
		$<$<CONFIG:Debug>:${${lib}_LIB_DEBUG}>
	)

	# Header file
	find_path(${lib}_INCLUDE "lib${lib}/${lib}.h" PATHS ${FFmpegROOT}/include)
	if (NOT ${lib}_INCLUDE)
		message(FATAL_ERROR "Could not find header file of library \"${lib}\"")
	endif()

	target_include_directories(${PROJECT_NAME} PRIVATE ${${lib}_INCLUDE})
	
endforeach()

# SDL2


# Ashley

target_compile_features(Ashley PRIVATE cxx_std_17)

add_executable(Ashley
    src/main.cpp
)
# add_subdirectory(./src)
