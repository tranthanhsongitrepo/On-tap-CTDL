# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/tran/Downloads/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tran/Downloads/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/tran/ハンム人/Codes/On tap/Problem 38"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/tran/ハンム人/Codes/On tap/Problem 38/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Problem_38.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Problem_38.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Problem_38.dir/flags.make

CMakeFiles/Problem_38.dir/main.cpp.o: CMakeFiles/Problem_38.dir/flags.make
CMakeFiles/Problem_38.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/tran/ハンム人/Codes/On tap/Problem 38/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Problem_38.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Problem_38.dir/main.cpp.o -c "/media/tran/ハンム人/Codes/On tap/Problem 38/main.cpp"

CMakeFiles/Problem_38.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Problem_38.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/tran/ハンム人/Codes/On tap/Problem 38/main.cpp" > CMakeFiles/Problem_38.dir/main.cpp.i

CMakeFiles/Problem_38.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Problem_38.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/tran/ハンム人/Codes/On tap/Problem 38/main.cpp" -o CMakeFiles/Problem_38.dir/main.cpp.s

# Object files for target Problem_38
Problem_38_OBJECTS = \
"CMakeFiles/Problem_38.dir/main.cpp.o"

# External object files for target Problem_38
Problem_38_EXTERNAL_OBJECTS =

Problem_38: CMakeFiles/Problem_38.dir/main.cpp.o
Problem_38: CMakeFiles/Problem_38.dir/build.make
Problem_38: CMakeFiles/Problem_38.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/tran/ハンム人/Codes/On tap/Problem 38/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Problem_38"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Problem_38.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Problem_38.dir/build: Problem_38

.PHONY : CMakeFiles/Problem_38.dir/build

CMakeFiles/Problem_38.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Problem_38.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Problem_38.dir/clean

CMakeFiles/Problem_38.dir/depend:
	cd "/media/tran/ハンム人/Codes/On tap/Problem 38/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/tran/ハンム人/Codes/On tap/Problem 38" "/media/tran/ハンム人/Codes/On tap/Problem 38" "/media/tran/ハンム人/Codes/On tap/Problem 38/cmake-build-debug" "/media/tran/ハンム人/Codes/On tap/Problem 38/cmake-build-debug" "/media/tran/ハンム人/Codes/On tap/Problem 38/cmake-build-debug/CMakeFiles/Problem_38.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Problem_38.dir/depend

