# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\zzj\Documents\workspace\kafka\project\demo1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zzj\Documents\workspace\kafka\project\demo1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/action3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/action3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/action3.dir/flags.make

CMakeFiles/action3.dir/main.cpp.obj: CMakeFiles/action3.dir/flags.make
CMakeFiles/action3.dir/main.cpp.obj: CMakeFiles/action3.dir/includes_CXX.rsp
CMakeFiles/action3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zzj\Documents\workspace\kafka\project\demo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/action3.dir/main.cpp.obj"
	\usr\local\gcc-9.3.0\bin\g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\action3.dir\main.cpp.obj -c C:\Users\zzj\Documents\workspace\kafka\project\demo1\main.cpp

CMakeFiles/action3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/action3.dir/main.cpp.i"
	\usr\local\gcc-9.3.0\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zzj\Documents\workspace\kafka\project\demo1\main.cpp > CMakeFiles\action3.dir\main.cpp.i

CMakeFiles/action3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/action3.dir/main.cpp.s"
	\usr\local\gcc-9.3.0\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zzj\Documents\workspace\kafka\project\demo1\main.cpp -o CMakeFiles\action3.dir\main.cpp.s

# Object files for target action3
action3_OBJECTS = \
"CMakeFiles/action3.dir/main.cpp.obj"

# External object files for target action3
action3_EXTERNAL_OBJECTS =

action3.exe: CMakeFiles/action3.dir/main.cpp.obj
action3.exe: CMakeFiles/action3.dir/build.make
action3.exe: CMakeFiles/action3.dir/linklibs.rsp
action3.exe: CMakeFiles/action3.dir/objects1.rsp
action3.exe: CMakeFiles/action3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\zzj\Documents\workspace\kafka\project\demo1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable action3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\action3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/action3.dir/build: action3.exe

.PHONY : CMakeFiles/action3.dir/build

CMakeFiles/action3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\action3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/action3.dir/clean

CMakeFiles/action3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zzj\Documents\workspace\kafka\project\demo1 C:\Users\zzj\Documents\workspace\kafka\project\demo1 C:\Users\zzj\Documents\workspace\kafka\project\demo1\cmake-build-debug C:\Users\zzj\Documents\workspace\kafka\project\demo1\cmake-build-debug C:\Users\zzj\Documents\workspace\kafka\project\demo1\cmake-build-debug\CMakeFiles\action3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/action3.dir/depend

