# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/sysop/Snake3D/opengl/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sysop/Snake3D/opengl/glfw

# Include any dependencies generated for this target.
include tests/CMakeFiles/tearing.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tearing.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/tearing.dir/flags.make

tests/CMakeFiles/tearing.dir/tearing.c.o: tests/CMakeFiles/tearing.dir/flags.make
tests/CMakeFiles/tearing.dir/tearing.c.o: tests/tearing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sysop/Snake3D/opengl/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/tearing.dir/tearing.c.o"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tearing.dir/tearing.c.o   -c /home/sysop/Snake3D/opengl/glfw/tests/tearing.c

tests/CMakeFiles/tearing.dir/tearing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/tearing.c.i"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sysop/Snake3D/opengl/glfw/tests/tearing.c > CMakeFiles/tearing.dir/tearing.c.i

tests/CMakeFiles/tearing.dir/tearing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/tearing.c.s"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sysop/Snake3D/opengl/glfw/tests/tearing.c -o CMakeFiles/tearing.dir/tearing.c.s

tests/CMakeFiles/tearing.dir/tearing.c.o.requires:

.PHONY : tests/CMakeFiles/tearing.dir/tearing.c.o.requires

tests/CMakeFiles/tearing.dir/tearing.c.o.provides: tests/CMakeFiles/tearing.dir/tearing.c.o.requires
	$(MAKE) -f tests/CMakeFiles/tearing.dir/build.make tests/CMakeFiles/tearing.dir/tearing.c.o.provides.build
.PHONY : tests/CMakeFiles/tearing.dir/tearing.c.o.provides

tests/CMakeFiles/tearing.dir/tearing.c.o.provides.build: tests/CMakeFiles/tearing.dir/tearing.c.o


tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o: tests/CMakeFiles/tearing.dir/flags.make
tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o: deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sysop/Snake3D/opengl/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tearing.dir/__/deps/getopt.c.o   -c /home/sysop/Snake3D/opengl/glfw/deps/getopt.c

tests/CMakeFiles/tearing.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/getopt.c.i"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sysop/Snake3D/opengl/glfw/deps/getopt.c > CMakeFiles/tearing.dir/__/deps/getopt.c.i

tests/CMakeFiles/tearing.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/getopt.c.s"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sysop/Snake3D/opengl/glfw/deps/getopt.c -o CMakeFiles/tearing.dir/__/deps/getopt.c.s

tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.requires:

.PHONY : tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.requires

tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.provides: tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f tests/CMakeFiles/tearing.dir/build.make tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.provides.build
.PHONY : tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.provides

tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.provides.build: tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o


tests/CMakeFiles/tearing.dir/__/deps/glad.c.o: tests/CMakeFiles/tearing.dir/flags.make
tests/CMakeFiles/tearing.dir/__/deps/glad.c.o: deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sysop/Snake3D/opengl/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/tearing.dir/__/deps/glad.c.o"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tearing.dir/__/deps/glad.c.o   -c /home/sysop/Snake3D/opengl/glfw/deps/glad.c

tests/CMakeFiles/tearing.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/glad.c.i"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sysop/Snake3D/opengl/glfw/deps/glad.c > CMakeFiles/tearing.dir/__/deps/glad.c.i

tests/CMakeFiles/tearing.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/glad.c.s"
	cd /home/sysop/Snake3D/opengl/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sysop/Snake3D/opengl/glfw/deps/glad.c -o CMakeFiles/tearing.dir/__/deps/glad.c.s

tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.requires:

.PHONY : tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.requires

tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.provides: tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.requires
	$(MAKE) -f tests/CMakeFiles/tearing.dir/build.make tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.provides.build
.PHONY : tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.provides

tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.provides.build: tests/CMakeFiles/tearing.dir/__/deps/glad.c.o


# Object files for target tearing
tearing_OBJECTS = \
"CMakeFiles/tearing.dir/tearing.c.o" \
"CMakeFiles/tearing.dir/__/deps/getopt.c.o" \
"CMakeFiles/tearing.dir/__/deps/glad.c.o"

# External object files for target tearing
tearing_EXTERNAL_OBJECTS =

tests/tearing: tests/CMakeFiles/tearing.dir/tearing.c.o
tests/tearing: tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o
tests/tearing: tests/CMakeFiles/tearing.dir/__/deps/glad.c.o
tests/tearing: tests/CMakeFiles/tearing.dir/build.make
tests/tearing: src/libglfw.so.3.2
tests/tearing: /usr/lib/x86_64-linux-gnu/libm.so
tests/tearing: tests/CMakeFiles/tearing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sysop/Snake3D/opengl/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable tearing"
	cd /home/sysop/Snake3D/opengl/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tearing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/tearing.dir/build: tests/tearing

.PHONY : tests/CMakeFiles/tearing.dir/build

tests/CMakeFiles/tearing.dir/requires: tests/CMakeFiles/tearing.dir/tearing.c.o.requires
tests/CMakeFiles/tearing.dir/requires: tests/CMakeFiles/tearing.dir/__/deps/getopt.c.o.requires
tests/CMakeFiles/tearing.dir/requires: tests/CMakeFiles/tearing.dir/__/deps/glad.c.o.requires

.PHONY : tests/CMakeFiles/tearing.dir/requires

tests/CMakeFiles/tearing.dir/clean:
	cd /home/sysop/Snake3D/opengl/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/tearing.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/tearing.dir/clean

tests/CMakeFiles/tearing.dir/depend:
	cd /home/sysop/Snake3D/opengl/glfw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sysop/Snake3D/opengl/glfw /home/sysop/Snake3D/opengl/glfw/tests /home/sysop/Snake3D/opengl/glfw /home/sysop/Snake3D/opengl/glfw/tests /home/sysop/Snake3D/opengl/glfw/tests/CMakeFiles/tearing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/tearing.dir/depend

