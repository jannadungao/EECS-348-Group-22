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
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build

# Utility rule file for calculator_qmlimportscan.

# Include any custom commands dependencies for this target.
include CMakeFiles/calculator_qmlimportscan.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/calculator_qmlimportscan.dir/progress.make

CMakeFiles/calculator_qmlimportscan: .qt/qml_imports/calculator_build.cmake

.qt/qml_imports/calculator_build.cmake: C:/Qt/6.8.0/mingw_64/bin/qmlimportscanner.exe
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running qmlimportscanner for calculator"
	cd /d C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator && call C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\.qt\bin\qt_setup_tool_path.bat C:/Qt/6.8.0/mingw_64/bin/qmlimportscanner.exe @C:/Users/Essaw/DT/Desktop/KU_Classes/Fall_2024/group_project348/build/.qt/qml_imports/calculator_build.rsp

calculator_qmlimportscan: .qt/qml_imports/calculator_build.cmake
calculator_qmlimportscan: CMakeFiles/calculator_qmlimportscan
calculator_qmlimportscan: CMakeFiles/calculator_qmlimportscan.dir/build.make
.PHONY : calculator_qmlimportscan

# Rule to build all files generated by this target.
CMakeFiles/calculator_qmlimportscan.dir/build: calculator_qmlimportscan
.PHONY : CMakeFiles/calculator_qmlimportscan.dir/build

CMakeFiles/calculator_qmlimportscan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\calculator_qmlimportscan.dir\cmake_clean.cmake
.PHONY : CMakeFiles/calculator_qmlimportscan.dir/clean

CMakeFiles/calculator_qmlimportscan.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\CMakeFiles\calculator_qmlimportscan.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calculator_qmlimportscan.dir/depend
