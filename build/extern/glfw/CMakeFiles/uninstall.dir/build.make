# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/etoski/Personal_Project/EventPlanner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/etoski/Personal_Project/EventPlanner/build

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include extern/glfw/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include extern/glfw/CMakeFiles/uninstall.dir/progress.make

extern/glfw/CMakeFiles/uninstall:
	cd /home/etoski/Personal_Project/EventPlanner/build/extern/glfw && /usr/bin/cmake -P /home/etoski/Personal_Project/EventPlanner/build/extern/glfw/cmake_uninstall.cmake

uninstall: extern/glfw/CMakeFiles/uninstall
uninstall: extern/glfw/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
extern/glfw/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : extern/glfw/CMakeFiles/uninstall.dir/build

extern/glfw/CMakeFiles/uninstall.dir/clean:
	cd /home/etoski/Personal_Project/EventPlanner/build/extern/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : extern/glfw/CMakeFiles/uninstall.dir/clean

extern/glfw/CMakeFiles/uninstall.dir/depend:
	cd /home/etoski/Personal_Project/EventPlanner/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/etoski/Personal_Project/EventPlanner /home/etoski/Personal_Project/EventPlanner/extern/glfw /home/etoski/Personal_Project/EventPlanner/build /home/etoski/Personal_Project/EventPlanner/build/extern/glfw /home/etoski/Personal_Project/EventPlanner/build/extern/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : extern/glfw/CMakeFiles/uninstall.dir/depend

