# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crs/cf/contest/1575/j

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crs/cf/contest/1575/j/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/j.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/j.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/j.dir/flags.make

CMakeFiles/j.dir/j.cpp.o: CMakeFiles/j.dir/flags.make
CMakeFiles/j.dir/j.cpp.o: ../j.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crs/cf/contest/1575/j/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/j.dir/j.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/j.dir/j.cpp.o -c /home/crs/cf/contest/1575/j/j.cpp

CMakeFiles/j.dir/j.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/j.dir/j.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crs/cf/contest/1575/j/j.cpp > CMakeFiles/j.dir/j.cpp.i

CMakeFiles/j.dir/j.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/j.dir/j.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crs/cf/contest/1575/j/j.cpp -o CMakeFiles/j.dir/j.cpp.s

# Object files for target j
j_OBJECTS = \
"CMakeFiles/j.dir/j.cpp.o"

# External object files for target j
j_EXTERNAL_OBJECTS =

j : CMakeFiles/j.dir/j.cpp.o
j : CMakeFiles/j.dir/build.make
j : CMakeFiles/j.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crs/cf/contest/1575/j/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable j"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/j.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/j.dir/build: j
.PHONY : CMakeFiles/j.dir/build

CMakeFiles/j.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/j.dir/cmake_clean.cmake
.PHONY : CMakeFiles/j.dir/clean

CMakeFiles/j.dir/depend:
	cd /home/crs/cf/contest/1575/j/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crs/cf/contest/1575/j /home/crs/cf/contest/1575/j /home/crs/cf/contest/1575/j/cmake-build-debug /home/crs/cf/contest/1575/j/cmake-build-debug /home/crs/cf/contest/1575/j/cmake-build-debug/CMakeFiles/j.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/j.dir/depend

