# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\seda\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\seda\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\CLionProjects\Array Stacks"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\CLionProjects\Array Stacks\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/stack_array_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stack_array_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stack_array_.dir/flags.make

CMakeFiles/stack_array_.dir/main.c.obj: CMakeFiles/stack_array_.dir/flags.make
CMakeFiles/stack_array_.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CLionProjects\Array Stacks\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stack_array_.dir/main.c.obj"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\stack_array_.dir\main.c.obj   -c "D:\CLionProjects\Array Stacks\main.c"

CMakeFiles/stack_array_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stack_array_.dir/main.c.i"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\CLionProjects\Array Stacks\main.c" > CMakeFiles\stack_array_.dir\main.c.i

CMakeFiles/stack_array_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stack_array_.dir/main.c.s"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\CLionProjects\Array Stacks\main.c" -o CMakeFiles\stack_array_.dir\main.c.s

# Object files for target stack_array_
stack_array__OBJECTS = \
"CMakeFiles/stack_array_.dir/main.c.obj"

# External object files for target stack_array_
stack_array__EXTERNAL_OBJECTS =

stack_array_.exe: CMakeFiles/stack_array_.dir/main.c.obj
stack_array_.exe: CMakeFiles/stack_array_.dir/build.make
stack_array_.exe: CMakeFiles/stack_array_.dir/linklibs.rsp
stack_array_.exe: CMakeFiles/stack_array_.dir/objects1.rsp
stack_array_.exe: CMakeFiles/stack_array_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\CLionProjects\Array Stacks\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable stack_array_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stack_array_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stack_array_.dir/build: stack_array_.exe

.PHONY : CMakeFiles/stack_array_.dir/build

CMakeFiles/stack_array_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stack_array_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stack_array_.dir/clean

CMakeFiles/stack_array_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\CLionProjects\Array Stacks" "D:\CLionProjects\Array Stacks" "D:\CLionProjects\Array Stacks\cmake-build-debug" "D:\CLionProjects\Array Stacks\cmake-build-debug" "D:\CLionProjects\Array Stacks\cmake-build-debug\CMakeFiles\stack_array_.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/stack_array_.dir/depend

