# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /home/kpo8/Documents/OOP/milestone2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kpo8/Documents/OOP/milestone2

# Include any dependencies generated for this target.
include CMakeFiles/race.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/race.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/race.dir/flags.make

CMakeFiles/race.dir/main.cpp.o: CMakeFiles/race.dir/flags.make
CMakeFiles/race.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kpo8/Documents/OOP/milestone2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/race.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/race.dir/main.cpp.o -c /home/kpo8/Documents/OOP/milestone2/main.cpp

CMakeFiles/race.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/race.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kpo8/Documents/OOP/milestone2/main.cpp > CMakeFiles/race.dir/main.cpp.i

CMakeFiles/race.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/race.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kpo8/Documents/OOP/milestone2/main.cpp -o CMakeFiles/race.dir/main.cpp.s

# Object files for target race
race_OBJECTS = \
"CMakeFiles/race.dir/main.cpp.o"

# External object files for target race
race_EXTERNAL_OBJECTS =

race: CMakeFiles/race.dir/main.cpp.o
race: CMakeFiles/race.dir/build.make
race: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.0
race: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.0
race: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.0
race: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.0
race: CMakeFiles/race.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kpo8/Documents/OOP/milestone2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable race"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/race.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/race.dir/build: race

.PHONY : CMakeFiles/race.dir/build

CMakeFiles/race.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/race.dir/cmake_clean.cmake
.PHONY : CMakeFiles/race.dir/clean

CMakeFiles/race.dir/depend:
	cd /home/kpo8/Documents/OOP/milestone2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kpo8/Documents/OOP/milestone2 /home/kpo8/Documents/OOP/milestone2 /home/kpo8/Documents/OOP/milestone2 /home/kpo8/Documents/OOP/milestone2 /home/kpo8/Documents/OOP/milestone2/CMakeFiles/race.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/race.dir/depend

