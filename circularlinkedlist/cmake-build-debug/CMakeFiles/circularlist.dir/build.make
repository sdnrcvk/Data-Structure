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
CMAKE_SOURCE_DIR = D:\CLionProjects\circularlinkedlist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\circularlinkedlist\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/circularlist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/circularlist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/circularlist.dir/flags.make

CMakeFiles/circularlist.dir/main.c.obj: CMakeFiles/circularlist.dir/flags.make
CMakeFiles/circularlist.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\circularlinkedlist\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/circularlist.dir/main.c.obj"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\circularlist.dir\main.c.obj   -c D:\CLionProjects\circularlinkedlist\main.c

CMakeFiles/circularlist.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/circularlist.dir/main.c.i"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\circularlinkedlist\main.c > CMakeFiles\circularlist.dir\main.c.i

CMakeFiles/circularlist.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/circularlist.dir/main.c.s"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\circularlinkedlist\main.c -o CMakeFiles\circularlist.dir\main.c.s

# Object files for target circularlist
circularlist_OBJECTS = \
"CMakeFiles/circularlist.dir/main.c.obj"

# External object files for target circularlist
circularlist_EXTERNAL_OBJECTS =

circularlist.exe: CMakeFiles/circularlist.dir/main.c.obj
circularlist.exe: CMakeFiles/circularlist.dir/build.make
circularlist.exe: CMakeFiles/circularlist.dir/linklibs.rsp
circularlist.exe: CMakeFiles/circularlist.dir/objects1.rsp
circularlist.exe: CMakeFiles/circularlist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\circularlinkedlist\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable circularlist.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\circularlist.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/circularlist.dir/build: circularlist.exe

.PHONY : CMakeFiles/circularlist.dir/build

CMakeFiles/circularlist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\circularlist.dir\cmake_clean.cmake
.PHONY : CMakeFiles/circularlist.dir/clean

CMakeFiles/circularlist.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\circularlinkedlist D:\CLionProjects\circularlinkedlist D:\CLionProjects\circularlinkedlist\cmake-build-debug D:\CLionProjects\circularlinkedlist\cmake-build-debug D:\CLionProjects\circularlinkedlist\cmake-build-debug\CMakeFiles\circularlist.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/circularlist.dir/depend
