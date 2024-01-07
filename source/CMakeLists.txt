# set version
cmake_minimum_required(VERSION 3.22.0)

# set project name and programming language
project(study C)

# set C standard
set(CMAKE_C_STANDARD 99)

# specify cross-compilation toolchain file
#set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchains/mips/host/share/buildroot/toolchainfile.cmake")
# message(STATUS "Configuring build for ${CMAKE_TOOLCHAIN_FILE}.")

# Set compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -Wpedantic -Wwrite-strings -Waggregate-return -Wvla -Wfloat-equal -D_GNU_SOURCE -pthread -lm")

# inclide directories
include_directories(include)

# specify source files
file(GLOB MAIN
	"src/*.c"
	"include/*.h"
	)

# set target name and source files
add_executable(study ${MAIN})

# add custom target for valgrind
add_custom_target(run-valgrind
	COMMAND valgrind --leak-check=full ./study ARGS
	DEPENDS study
	COMMENT "Running Valgrind on study executable."
	VERBATIM
)
