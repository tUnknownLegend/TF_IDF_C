# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aint/park/c1/CC2/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aint/park/c1/CC2/project/build

# Include any dependencies generated for this target.
include CMakeFiles/IT1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IT1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IT1.dir/flags.make

CMakeFiles/IT1.dir/main.c.o: CMakeFiles/IT1.dir/flags.make
CMakeFiles/IT1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aint/park/c1/CC2/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IT1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -lm -o CMakeFiles/IT1.dir/main.c.o   -c /home/aint/park/c1/CC2/project/main.c

CMakeFiles/IT1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IT1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -lm -E /home/aint/park/c1/CC2/project/main.c > CMakeFiles/IT1.dir/main.c.i

CMakeFiles/IT1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IT1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -lm -S /home/aint/park/c1/CC2/project/main.c -o CMakeFiles/IT1.dir/main.c.s

# Object files for target IT1
IT1_OBJECTS = \
"CMakeFiles/IT1.dir/main.c.o"

# External object files for target IT1
IT1_EXTERNAL_OBJECTS =

IT1: CMakeFiles/IT1.dir/main.c.o
IT1: CMakeFiles/IT1.dir/build.make
IT1: src/libIT1_SRC.a
IT1: CMakeFiles/IT1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aint/park/c1/CC2/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable IT1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IT1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IT1.dir/build: IT1

.PHONY : CMakeFiles/IT1.dir/build

CMakeFiles/IT1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IT1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IT1.dir/clean

CMakeFiles/IT1.dir/depend:
	cd /home/aint/park/c1/CC2/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aint/park/c1/CC2/project /home/aint/park/c1/CC2/project /home/aint/park/c1/CC2/project/build /home/aint/park/c1/CC2/project/build /home/aint/park/c1/CC2/project/build/CMakeFiles/IT1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IT1.dir/depend

