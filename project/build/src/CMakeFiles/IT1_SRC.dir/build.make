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
CMAKE_SOURCE_DIR = /home/aint/park/c1/C2/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aint/park/c1/C2/project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/IT1_SRC.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/IT1_SRC.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/IT1_SRC.dir/flags.make

src/CMakeFiles/IT1_SRC.dir/calc_hash.c.o: src/CMakeFiles/IT1_SRC.dir/flags.make
src/CMakeFiles/IT1_SRC.dir/calc_hash.c.o: ../src/calc_hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aint/park/c1/C2/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/IT1_SRC.dir/calc_hash.c.o"
	cd /home/aint/park/c1/C2/project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IT1_SRC.dir/calc_hash.c.o   -c /home/aint/park/c1/C2/project/src/calc_hash.c

src/CMakeFiles/IT1_SRC.dir/calc_hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IT1_SRC.dir/calc_hash.c.i"
	cd /home/aint/park/c1/C2/project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aint/park/c1/C2/project/src/calc_hash.c > CMakeFiles/IT1_SRC.dir/calc_hash.c.i

src/CMakeFiles/IT1_SRC.dir/calc_hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IT1_SRC.dir/calc_hash.c.s"
	cd /home/aint/park/c1/C2/project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aint/park/c1/C2/project/src/calc_hash.c -o CMakeFiles/IT1_SRC.dir/calc_hash.c.s

src/CMakeFiles/IT1_SRC.dir/ex.c.o: src/CMakeFiles/IT1_SRC.dir/flags.make
src/CMakeFiles/IT1_SRC.dir/ex.c.o: ../src/ex.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aint/park/c1/C2/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/IT1_SRC.dir/ex.c.o"
	cd /home/aint/park/c1/C2/project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IT1_SRC.dir/ex.c.o   -c /home/aint/park/c1/C2/project/src/ex.c

src/CMakeFiles/IT1_SRC.dir/ex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IT1_SRC.dir/ex.c.i"
	cd /home/aint/park/c1/C2/project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aint/park/c1/C2/project/src/ex.c > CMakeFiles/IT1_SRC.dir/ex.c.i

src/CMakeFiles/IT1_SRC.dir/ex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IT1_SRC.dir/ex.c.s"
	cd /home/aint/park/c1/C2/project/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aint/park/c1/C2/project/src/ex.c -o CMakeFiles/IT1_SRC.dir/ex.c.s

# Object files for target IT1_SRC
IT1_SRC_OBJECTS = \
"CMakeFiles/IT1_SRC.dir/calc_hash.c.o" \
"CMakeFiles/IT1_SRC.dir/ex.c.o"

# External object files for target IT1_SRC
IT1_SRC_EXTERNAL_OBJECTS =

src/libIT1_SRC.a: src/CMakeFiles/IT1_SRC.dir/calc_hash.c.o
src/libIT1_SRC.a: src/CMakeFiles/IT1_SRC.dir/ex.c.o
src/libIT1_SRC.a: src/CMakeFiles/IT1_SRC.dir/build.make
src/libIT1_SRC.a: src/CMakeFiles/IT1_SRC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aint/park/c1/C2/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libIT1_SRC.a"
	cd /home/aint/park/c1/C2/project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/IT1_SRC.dir/cmake_clean_target.cmake
	cd /home/aint/park/c1/C2/project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IT1_SRC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/IT1_SRC.dir/build: src/libIT1_SRC.a

.PHONY : src/CMakeFiles/IT1_SRC.dir/build

src/CMakeFiles/IT1_SRC.dir/clean:
	cd /home/aint/park/c1/C2/project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/IT1_SRC.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/IT1_SRC.dir/clean

src/CMakeFiles/IT1_SRC.dir/depend:
	cd /home/aint/park/c1/C2/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aint/park/c1/C2/project /home/aint/park/c1/C2/project/src /home/aint/park/c1/C2/project/build /home/aint/park/c1/C2/project/build/src /home/aint/park/c1/C2/project/build/src/CMakeFiles/IT1_SRC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/IT1_SRC.dir/depend

