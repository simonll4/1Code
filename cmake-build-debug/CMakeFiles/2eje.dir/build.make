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
include CMakeFiles/2eje.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/2eje.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2eje.dir/flags.make

CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.obj: CMakeFiles/2eje.dir/flags.make
CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.obj: ../parcial2/2.LlamosasSimon_eje2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2eje.dir\parcial2\2.LlamosasSimon_eje2.cpp.obj -c "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\parcial2\2.LlamosasSimon_eje2.cpp"

CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\parcial2\2.LlamosasSimon_eje2.cpp" > CMakeFiles\2eje.dir\parcial2\2.LlamosasSimon_eje2.cpp.i

CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\parcial2\2.LlamosasSimon_eje2.cpp" -o CMakeFiles\2eje.dir\parcial2\2.LlamosasSimon_eje2.cpp.s

# Object files for target 2eje
2eje_OBJECTS = \
"CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.obj"

# External object files for target 2eje
2eje_EXTERNAL_OBJECTS =

2eje.exe: CMakeFiles/2eje.dir/parcial2/2.LlamosasSimon_eje2.cpp.obj
2eje.exe: CMakeFiles/2eje.dir/build.make
2eje.exe: CMakeFiles/2eje.dir/linklibs.rsp
2eje.exe: CMakeFiles/2eje.dir/objects1.rsp
2eje.exe: CMakeFiles/2eje.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2eje.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2eje.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2eje.dir/build: 2eje.exe
.PHONY : CMakeFiles/2eje.dir/build

CMakeFiles/2eje.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2eje.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2eje.dir/clean

CMakeFiles/2eje.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug" "G:\Mi unidad\segundo_semestre\info 2\codigos1\Clion codigos\cmake-build-debug\CMakeFiles\2eje.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/2eje.dir/depend

