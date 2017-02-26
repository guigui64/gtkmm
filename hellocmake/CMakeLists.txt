cmake_minimum_required (VERSION 2.6)
project (HelloCMake)
# The version number.
set (HelloCMake_VERSION_MAJOR 0)
set (HelloCMake_VERSION_MINOR 1)

# c++11
#set_property(TARGET tgt PROPERTY CXX_STANDARD 11)
if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
else ()
    set (CMAKE_CXX_STANDARD 11)
endif ()

# gtkmm
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0) # look into FindPkgConfig.cmake,
                                   # it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES
# contain what you expect
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

# set sources
file(GLOB SOURCES "src/*.cpp")

# add the executable
add_executable(HelloCMake ${SOURCES})
target_link_libraries(HelloCMake ${GTKMM_LIBRARIES})
