# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "E:\Programme\cLion\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Programme\cLion\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/uebungen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uebungen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uebungen.dir/flags.make

CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.obj: CMakeFiles/uebungen.dir/flags.make
CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.obj: ../Uebungen/uebung1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\uebungen.dir\Uebungen\uebung1.cpp.obj -c "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\Uebungen\uebung1.cpp"

CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\Uebungen\uebung1.cpp" > CMakeFiles\uebungen.dir\Uebungen\uebung1.cpp.i

CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\Uebungen\uebung1.cpp" -o CMakeFiles\uebungen.dir\Uebungen\uebung1.cpp.s

# Object files for target uebungen
uebungen_OBJECTS = \
"CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.obj"

# External object files for target uebungen
uebungen_EXTERNAL_OBJECTS =

uebungen.exe: CMakeFiles/uebungen.dir/Uebungen/uebung1.cpp.obj
uebungen.exe: CMakeFiles/uebungen.dir/build.make
uebungen.exe: CMakeFiles/uebungen.dir/linklibs.rsp
uebungen.exe: CMakeFiles/uebungen.dir/objects1.rsp
uebungen.exe: CMakeFiles/uebungen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable uebungen.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\uebungen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uebungen.dir/build: uebungen.exe

.PHONY : CMakeFiles/uebungen.dir/build

CMakeFiles/uebungen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\uebungen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/uebungen.dir/clean

CMakeFiles/uebungen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion" "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion" "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\cmake-build-debug" "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\cmake-build-debug" "E:\OneDrive\OneDrive - Hochschule Furtwangen\Studium\Semester 6\OOP\CLion\cmake-build-debug\CMakeFiles\Uebungen.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/uebungen.dir/depend
