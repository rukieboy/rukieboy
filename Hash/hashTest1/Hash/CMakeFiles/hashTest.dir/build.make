# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /hdf/TEST/Hash/hashTest1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /hdf/TEST/Hash/hashTest1

# Include any dependencies generated for this target.
include Hash/CMakeFiles/hashTest.dir/depend.make

# Include the progress variables for this target.
include Hash/CMakeFiles/hashTest.dir/progress.make

# Include the compile flags for this target's objects.
include Hash/CMakeFiles/hashTest.dir/flags.make

Hash/CMakeFiles/hashTest.dir/Hash.c.o: Hash/CMakeFiles/hashTest.dir/flags.make
Hash/CMakeFiles/hashTest.dir/Hash.c.o: Hash/Hash.c
	$(CMAKE_COMMAND) -E cmake_progress_report /hdf/TEST/Hash/hashTest1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object Hash/CMakeFiles/hashTest.dir/Hash.c.o"
	cd /hdf/TEST/Hash/hashTest1/Hash && /usr/lib/ccache/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hashTest.dir/Hash.c.o   -c /hdf/TEST/Hash/hashTest1/Hash/Hash.c

Hash/CMakeFiles/hashTest.dir/Hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hashTest.dir/Hash.c.i"
	cd /hdf/TEST/Hash/hashTest1/Hash && /usr/lib/ccache/cc  $(C_DEFINES) $(C_FLAGS) -E /hdf/TEST/Hash/hashTest1/Hash/Hash.c > CMakeFiles/hashTest.dir/Hash.c.i

Hash/CMakeFiles/hashTest.dir/Hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hashTest.dir/Hash.c.s"
	cd /hdf/TEST/Hash/hashTest1/Hash && /usr/lib/ccache/cc  $(C_DEFINES) $(C_FLAGS) -S /hdf/TEST/Hash/hashTest1/Hash/Hash.c -o CMakeFiles/hashTest.dir/Hash.c.s

Hash/CMakeFiles/hashTest.dir/Hash.c.o.requires:
.PHONY : Hash/CMakeFiles/hashTest.dir/Hash.c.o.requires

Hash/CMakeFiles/hashTest.dir/Hash.c.o.provides: Hash/CMakeFiles/hashTest.dir/Hash.c.o.requires
	$(MAKE) -f Hash/CMakeFiles/hashTest.dir/build.make Hash/CMakeFiles/hashTest.dir/Hash.c.o.provides.build
.PHONY : Hash/CMakeFiles/hashTest.dir/Hash.c.o.provides

Hash/CMakeFiles/hashTest.dir/Hash.c.o.provides.build: Hash/CMakeFiles/hashTest.dir/Hash.c.o

# Object files for target hashTest
hashTest_OBJECTS = \
"CMakeFiles/hashTest.dir/Hash.c.o"

# External object files for target hashTest
hashTest_EXTERNAL_OBJECTS =

bin/hashTest: Hash/CMakeFiles/hashTest.dir/Hash.c.o
bin/hashTest: Hash/CMakeFiles/hashTest.dir/build.make
bin/hashTest: Hash/CMakeFiles/hashTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/hashTest"
	cd /hdf/TEST/Hash/hashTest1/Hash && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hashTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Hash/CMakeFiles/hashTest.dir/build: bin/hashTest
.PHONY : Hash/CMakeFiles/hashTest.dir/build

Hash/CMakeFiles/hashTest.dir/requires: Hash/CMakeFiles/hashTest.dir/Hash.c.o.requires
.PHONY : Hash/CMakeFiles/hashTest.dir/requires

Hash/CMakeFiles/hashTest.dir/clean:
	cd /hdf/TEST/Hash/hashTest1/Hash && $(CMAKE_COMMAND) -P CMakeFiles/hashTest.dir/cmake_clean.cmake
.PHONY : Hash/CMakeFiles/hashTest.dir/clean

Hash/CMakeFiles/hashTest.dir/depend:
	cd /hdf/TEST/Hash/hashTest1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /hdf/TEST/Hash/hashTest1 /hdf/TEST/Hash/hashTest1/Hash /hdf/TEST/Hash/hashTest1 /hdf/TEST/Hash/hashTest1/Hash /hdf/TEST/Hash/hashTest1/Hash/CMakeFiles/hashTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Hash/CMakeFiles/hashTest.dir/depend

