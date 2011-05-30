cmake_minimum_required (VERSION 2.6)
project (prelim)

# This acts as a preset and sets various compiler and linker flags.
# Options are: [Debug|Release|RelWithDebInfo|MinSizeRel]
#set(CMAKE_BUILD_TYPE Debug)

# However, you can also create your own names like this:
#set(CMAKE_BUILD_TYPE distribution)
#set(CMAKE_CXX_FLAGS_DISTRIBUTION "-O3")
#set(CMAKE_C_FLAGS_DISTRIBUTION "-O3")

# This sets compiler flags manually; CMAKE_BUILD_TYPE is a preset version
# First we make sure the compiler is GNU GCC as cmake works with many compilers.
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-g -Wall -std=gnu++0x")  ## Optimize
  set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()

# This sets the build directory to ./bin
# Note that the variable can be:
# ${PROJECT_BINARY_DIR} = Full path to build directory for the most recent project command.
# ${projectname_BINARY_DIR}
# ${CMAKE_BINARY_DIR} = The path to the top level of the build tree.
#set (BUILD_DIR ${CMAKE_BINARY_DIR}/bin)
#if(NOT EXISTS ${BUILD_DIR} OR NOT IS_DIRECTORY ${BUILD_DIR})
#  file(REMOVE ${BUILD_DIR})
#  file(MAKE_DIRECTORY ${BUILD_DIR})
#endif()
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

set (PRELIM_SRC program1.cc name.cc nametable.cc)
add_executable (program1 ${PRELIM_SRC})
set (TESTING_SRC testing.cc name.cc nametable.cc)
add_executable (testing ${TESTING_SRC})
set_source_files_properties(${PRELIM_SRC} ${TESTING_SRC} PROPERTIES LANGUAGE CXX)
