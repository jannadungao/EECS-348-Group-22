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

# Include any dependencies generated for this target.
include CMakeFiles/calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculator.dir/flags.make

CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj: CMakeFiles/calculator.dir/includes_CXX.rsp
CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj: calculator_autogen/mocs_compilation.cpp
CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\calculator.dir\calculator_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\calculator.dir\calculator_autogen\mocs_compilation.cpp.obj -c C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\calculator_autogen\mocs_compilation.cpp

CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\calculator_autogen\mocs_compilation.cpp > CMakeFiles\calculator.dir\calculator_autogen\mocs_compilation.cpp.i

CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\calculator_autogen\mocs_compilation.cpp -o CMakeFiles\calculator.dir\calculator_autogen\mocs_compilation.cpp.s

CMakeFiles/calculator.dir/main.cpp.obj: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/main.cpp.obj: CMakeFiles/calculator.dir/includes_CXX.rsp
CMakeFiles/calculator.dir/main.cpp.obj: C:/Users/Essaw/DT/Desktop/KU_Classes/Fall_2024/group_project348/calculator/main.cpp
CMakeFiles/calculator.dir/main.cpp.obj: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/calculator.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/main.cpp.obj -MF CMakeFiles\calculator.dir\main.cpp.obj.d -o CMakeFiles\calculator.dir\main.cpp.obj -c C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator\main.cpp

CMakeFiles/calculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator\main.cpp > CMakeFiles\calculator.dir\main.cpp.i

CMakeFiles/calculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator\main.cpp -o CMakeFiles\calculator.dir\main.cpp.s

CMakeFiles/calculator.dir/calculator.cpp.obj: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/calculator.cpp.obj: CMakeFiles/calculator.dir/includes_CXX.rsp
CMakeFiles/calculator.dir/calculator.cpp.obj: C:/Users/Essaw/DT/Desktop/KU_Classes/Fall_2024/group_project348/calculator/calculator.cpp
CMakeFiles/calculator.dir/calculator.cpp.obj: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/calculator.dir/calculator.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/calculator.cpp.obj -MF CMakeFiles\calculator.dir\calculator.cpp.obj.d -o CMakeFiles\calculator.dir\calculator.cpp.obj -c C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator\calculator.cpp

CMakeFiles/calculator.dir/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator.dir/calculator.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator\calculator.cpp > CMakeFiles\calculator.dir\calculator.cpp.i

CMakeFiles/calculator.dir/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/calculator.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator\calculator.cpp -o CMakeFiles\calculator.dir\calculator.cpp.s

# Object files for target calculator
calculator_OBJECTS = \
"CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/calculator.dir/main.cpp.obj" \
"CMakeFiles/calculator.dir/calculator.cpp.obj"

# External object files for target calculator
calculator_EXTERNAL_OBJECTS =

calculator.exe: CMakeFiles/calculator.dir/calculator_autogen/mocs_compilation.cpp.obj
calculator.exe: CMakeFiles/calculator.dir/main.cpp.obj
calculator.exe: CMakeFiles/calculator.dir/calculator.cpp.obj
calculator.exe: CMakeFiles/calculator.dir/build.make
calculator.exe: C:/Qt/6.8.0/mingw_64/lib/libQt6Widgets.a
calculator.exe: C:/Qt/6.8.0/mingw_64/lib/libQt6Qml.a
calculator.exe: C:/Qt/6.8.0/mingw_64/lib/libQt6Gui.a
calculator.exe: C:/Qt/6.8.0/mingw_64/lib/libQt6Network.a
calculator.exe: C:/Qt/6.8.0/mingw_64/lib/libQt6Core.a
calculator.exe: C:/Qt/6.8.0/mingw_64/lib/libQt6EntryPoint.a
calculator.exe: CMakeFiles/calculator.dir/linklibs.rsp
calculator.exe: CMakeFiles/calculator.dir/objects1.rsp
calculator.exe: CMakeFiles/calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable calculator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\calculator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculator.dir/build: calculator.exe
.PHONY : CMakeFiles/calculator.dir/build

CMakeFiles/calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\calculator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/calculator.dir/clean

CMakeFiles/calculator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\calculator C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build C:\Users\Essaw\DT\Desktop\KU_Classes\Fall_2024\group_project348\build\CMakeFiles\calculator.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calculator.dir/depend

