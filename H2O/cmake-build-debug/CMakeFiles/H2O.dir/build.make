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
CMAKE_SOURCE_DIR = /home/rjzhb/Project/interview/H2O

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rjzhb/Project/interview/H2O/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/H2O.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/H2O.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/H2O.dir/flags.make

CMakeFiles/H2O.dir/main.cpp.o: CMakeFiles/H2O.dir/flags.make
CMakeFiles/H2O.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/interview/H2O/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/H2O.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/H2O.dir/main.cpp.o -c /home/rjzhb/Project/interview/H2O/main.cpp

CMakeFiles/H2O.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/H2O.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/interview/H2O/main.cpp > CMakeFiles/H2O.dir/main.cpp.i

CMakeFiles/H2O.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/H2O.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/interview/H2O/main.cpp -o CMakeFiles/H2O.dir/main.cpp.s

# Object files for target H2O
H2O_OBJECTS = \
"CMakeFiles/H2O.dir/main.cpp.o"

# External object files for target H2O
H2O_EXTERNAL_OBJECTS =

H2O: CMakeFiles/H2O.dir/main.cpp.o
H2O: CMakeFiles/H2O.dir/build.make
H2O: CMakeFiles/H2O.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjzhb/Project/interview/H2O/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable H2O"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/H2O.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/H2O.dir/build: H2O

.PHONY : CMakeFiles/H2O.dir/build

CMakeFiles/H2O.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/H2O.dir/cmake_clean.cmake
.PHONY : CMakeFiles/H2O.dir/clean

CMakeFiles/H2O.dir/depend:
	cd /home/rjzhb/Project/interview/H2O/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjzhb/Project/interview/H2O /home/rjzhb/Project/interview/H2O /home/rjzhb/Project/interview/H2O/cmake-build-debug /home/rjzhb/Project/interview/H2O/cmake-build-debug /home/rjzhb/Project/interview/H2O/cmake-build-debug/CMakeFiles/H2O.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/H2O.dir/depend

