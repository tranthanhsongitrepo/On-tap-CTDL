# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = "/media/tran/ハンム人/Codes/Algorithms/Xem phim"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/tran/ハンム人/Codes/Algorithms/Xem phim/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Xem_phim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Xem_phim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Xem_phim.dir/flags.make

CMakeFiles/Xem_phim.dir/main.cpp.o: CMakeFiles/Xem_phim.dir/flags.make
CMakeFiles/Xem_phim.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/tran/ハンム人/Codes/Algorithms/Xem phim/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Xem_phim.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Xem_phim.dir/main.cpp.o -c "/media/tran/ハンム人/Codes/Algorithms/Xem phim/main.cpp"

CMakeFiles/Xem_phim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Xem_phim.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/tran/ハンム人/Codes/Algorithms/Xem phim/main.cpp" > CMakeFiles/Xem_phim.dir/main.cpp.i

CMakeFiles/Xem_phim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Xem_phim.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/tran/ハンム人/Codes/Algorithms/Xem phim/main.cpp" -o CMakeFiles/Xem_phim.dir/main.cpp.s

# Object files for target Xem_phim
Xem_phim_OBJECTS = \
"CMakeFiles/Xem_phim.dir/main.cpp.o"

# External object files for target Xem_phim
Xem_phim_EXTERNAL_OBJECTS =

Xem_phim: CMakeFiles/Xem_phim.dir/main.cpp.o
Xem_phim: CMakeFiles/Xem_phim.dir/build.make
Xem_phim: CMakeFiles/Xem_phim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/tran/ハンム人/Codes/Algorithms/Xem phim/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Xem_phim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Xem_phim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Xem_phim.dir/build: Xem_phim

.PHONY : CMakeFiles/Xem_phim.dir/build

CMakeFiles/Xem_phim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Xem_phim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Xem_phim.dir/clean

CMakeFiles/Xem_phim.dir/depend:
	cd "/media/tran/ハンム人/Codes/Algorithms/Xem phim/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/tran/ハンム人/Codes/Algorithms/Xem phim" "/media/tran/ハンム人/Codes/Algorithms/Xem phim" "/media/tran/ハンム人/Codes/Algorithms/Xem phim/cmake-build-debug" "/media/tran/ハンム人/Codes/Algorithms/Xem phim/cmake-build-debug" "/media/tran/ハンム人/Codes/Algorithms/Xem phim/cmake-build-debug/CMakeFiles/Xem_phim.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Xem_phim.dir/depend
