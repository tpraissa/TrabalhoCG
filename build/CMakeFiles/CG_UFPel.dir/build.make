# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/raissasp/CG_UFPel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raissasp/CG_UFPel/build

# Include any dependencies generated for this target.
include CMakeFiles/CG_UFPel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CG_UFPel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CG_UFPel.dir/flags.make

CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o: CMakeFiles/CG_UFPel.dir/flags.make
CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o: ../src/CG_UFPel/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raissasp/CG_UFPel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o -c /home/raissasp/CG_UFPel/src/CG_UFPel/main.cpp

CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raissasp/CG_UFPel/src/CG_UFPel/main.cpp > CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.i

CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raissasp/CG_UFPel/src/CG_UFPel/main.cpp -o CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.s

CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.requires:

.PHONY : CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.requires

CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.provides: CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG_UFPel.dir/build.make CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.provides.build
.PHONY : CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.provides

CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.provides.build: CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o


# Object files for target CG_UFPel
CG_UFPel_OBJECTS = \
"CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o"

# External object files for target CG_UFPel
CG_UFPel_EXTERNAL_OBJECTS =

CG_UFPel: CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o
CG_UFPel: CMakeFiles/CG_UFPel.dir/build.make
CG_UFPel: /usr/lib/x86_64-linux-gnu/libglfw.so
CG_UFPel: /usr/lib/x86_64-linux-gnu/libassimp.so
CG_UFPel: libSTB_IMAGE.a
CG_UFPel: libGLAD.a
CG_UFPel: CMakeFiles/CG_UFPel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raissasp/CG_UFPel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CG_UFPel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CG_UFPel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CG_UFPel.dir/build: CG_UFPel

.PHONY : CMakeFiles/CG_UFPel.dir/build

CMakeFiles/CG_UFPel.dir/requires: CMakeFiles/CG_UFPel.dir/src/CG_UFPel/main.cpp.o.requires

.PHONY : CMakeFiles/CG_UFPel.dir/requires

CMakeFiles/CG_UFPel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CG_UFPel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CG_UFPel.dir/clean

CMakeFiles/CG_UFPel.dir/depend:
	cd /home/raissasp/CG_UFPel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raissasp/CG_UFPel /home/raissasp/CG_UFPel /home/raissasp/CG_UFPel/build /home/raissasp/CG_UFPel/build /home/raissasp/CG_UFPel/build/CMakeFiles/CG_UFPel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CG_UFPel.dir/depend

