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
CMAKE_SOURCE_DIR = /home/guo/Git/A_Star

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guo/Git/A_Star/build

# Include any dependencies generated for this target.
include CMakeFiles/A_Star.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A_Star.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A_Star.dir/flags.make

CMakeFiles/A_Star.dir/main.cpp.o: CMakeFiles/A_Star.dir/flags.make
CMakeFiles/A_Star.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guo/Git/A_Star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A_Star.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A_Star.dir/main.cpp.o -c /home/guo/Git/A_Star/main.cpp

CMakeFiles/A_Star.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A_Star.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guo/Git/A_Star/main.cpp > CMakeFiles/A_Star.dir/main.cpp.i

CMakeFiles/A_Star.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A_Star.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guo/Git/A_Star/main.cpp -o CMakeFiles/A_Star.dir/main.cpp.s

CMakeFiles/A_Star.dir/src/A_Star.cpp.o: CMakeFiles/A_Star.dir/flags.make
CMakeFiles/A_Star.dir/src/A_Star.cpp.o: ../src/A_Star.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guo/Git/A_Star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/A_Star.dir/src/A_Star.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A_Star.dir/src/A_Star.cpp.o -c /home/guo/Git/A_Star/src/A_Star.cpp

CMakeFiles/A_Star.dir/src/A_Star.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A_Star.dir/src/A_Star.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guo/Git/A_Star/src/A_Star.cpp > CMakeFiles/A_Star.dir/src/A_Star.cpp.i

CMakeFiles/A_Star.dir/src/A_Star.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A_Star.dir/src/A_Star.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guo/Git/A_Star/src/A_Star.cpp -o CMakeFiles/A_Star.dir/src/A_Star.cpp.s

# Object files for target A_Star
A_Star_OBJECTS = \
"CMakeFiles/A_Star.dir/main.cpp.o" \
"CMakeFiles/A_Star.dir/src/A_Star.cpp.o"

# External object files for target A_Star
A_Star_EXTERNAL_OBJECTS =

A_Star: CMakeFiles/A_Star.dir/main.cpp.o
A_Star: CMakeFiles/A_Star.dir/src/A_Star.cpp.o
A_Star: CMakeFiles/A_Star.dir/build.make
A_Star: /usr/lib/python3.8/config-3.8-x86_64-linux-gnu/libpython3.8.so
A_Star: CMakeFiles/A_Star.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guo/Git/A_Star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable A_Star"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A_Star.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A_Star.dir/build: A_Star

.PHONY : CMakeFiles/A_Star.dir/build

CMakeFiles/A_Star.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A_Star.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A_Star.dir/clean

CMakeFiles/A_Star.dir/depend:
	cd /home/guo/Git/A_Star/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guo/Git/A_Star /home/guo/Git/A_Star /home/guo/Git/A_Star/build /home/guo/Git/A_Star/build /home/guo/Git/A_Star/build/CMakeFiles/A_Star.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A_Star.dir/depend

