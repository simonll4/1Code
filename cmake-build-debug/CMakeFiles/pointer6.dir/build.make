# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/pointer6.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/pointer6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pointer6.dir/flags.make

CMakeFiles/pointer6.dir/punteros/6.main.cpp.obj: CMakeFiles/pointer6.dir/flags.make
CMakeFiles/pointer6.dir/punteros/6.main.cpp.obj: ../punteros/6.main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pointer6.dir/punteros/6.main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pointer6.dir\punteros\6.main.cpp.obj -c "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\punteros\6.main.cpp"

CMakeFiles/pointer6.dir/punteros/6.main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pointer6.dir/punteros/6.main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\punteros\6.main.cpp" > CMakeFiles\pointer6.dir\punteros\6.main.cpp.i

CMakeFiles/pointer6.dir/punteros/6.main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pointer6.dir/punteros/6.main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\punteros\6.main.cpp" -o CMakeFiles\pointer6.dir\punteros\6.main.cpp.s

# Object files for target pointer6
pointer6_OBJECTS = \
"CMakeFiles/pointer6.dir/punteros/6.main.cpp.obj"

# External object files for target pointer6
pointer6_EXTERNAL_OBJECTS =

pointer6.exe: CMakeFiles/pointer6.dir/punteros/6.main.cpp.obj
pointer6.exe: CMakeFiles/pointer6.dir/build.make
pointer6.exe: CMakeFiles/pointer6.dir/linklibs.rsp
pointer6.exe: CMakeFiles/pointer6.dir/objects1.rsp
pointer6.exe: CMakeFiles/pointer6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pointer6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pointer6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pointer6.dir/build: pointer6.exe
.PHONY : CMakeFiles/pointer6.dir/build

CMakeFiles/pointer6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pointer6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pointer6.dir/clean

CMakeFiles/pointer6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug\CMakeFiles\pointer6.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pointer6.dir/depend
