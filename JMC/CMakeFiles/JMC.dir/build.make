# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/patryk/Desktop/JMC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patryk/Desktop/JMC

# Include any dependencies generated for this target.
include CMakeFiles/JMC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JMC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JMC.dir/flags.make

CMakeFiles/JMC.dir/JMC.cc.o: CMakeFiles/JMC.dir/flags.make
CMakeFiles/JMC.dir/JMC.cc.o: JMC.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JMC.dir/JMC.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JMC.dir/JMC.cc.o -c /home/patryk/Desktop/JMC/JMC.cc

CMakeFiles/JMC.dir/JMC.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JMC.dir/JMC.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Desktop/JMC/JMC.cc > CMakeFiles/JMC.dir/JMC.cc.i

CMakeFiles/JMC.dir/JMC.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JMC.dir/JMC.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Desktop/JMC/JMC.cc -o CMakeFiles/JMC.dir/JMC.cc.s

CMakeFiles/JMC.dir/JMC.cc.o.requires:

.PHONY : CMakeFiles/JMC.dir/JMC.cc.o.requires

CMakeFiles/JMC.dir/JMC.cc.o.provides: CMakeFiles/JMC.dir/JMC.cc.o.requires
	$(MAKE) -f CMakeFiles/JMC.dir/build.make CMakeFiles/JMC.dir/JMC.cc.o.provides.build
.PHONY : CMakeFiles/JMC.dir/JMC.cc.o.provides

CMakeFiles/JMC.dir/JMC.cc.o.provides.build: CMakeFiles/JMC.dir/JMC.cc.o


CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o: CMakeFiles/JMC.dir/flags.make
CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o: src/JMCActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o -c /home/patryk/Desktop/JMC/src/JMCActionInitialization.cc

CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Desktop/JMC/src/JMCActionInitialization.cc > CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.i

CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Desktop/JMC/src/JMCActionInitialization.cc -o CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.s

CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.requires:

.PHONY : CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.requires

CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.provides: CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.requires
	$(MAKE) -f CMakeFiles/JMC.dir/build.make CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.provides.build
.PHONY : CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.provides

CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.provides.build: CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o


CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o: CMakeFiles/JMC.dir/flags.make
CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o: src/JMCDetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o -c /home/patryk/Desktop/JMC/src/JMCDetectorConstruction.cc

CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Desktop/JMC/src/JMCDetectorConstruction.cc > CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.i

CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Desktop/JMC/src/JMCDetectorConstruction.cc -o CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.s

CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.requires:

.PHONY : CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.requires

CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.provides: CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/JMC.dir/build.make CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.provides

CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.provides.build: CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o


CMakeFiles/JMC.dir/src/JMCEventAction.cc.o: CMakeFiles/JMC.dir/flags.make
CMakeFiles/JMC.dir/src/JMCEventAction.cc.o: src/JMCEventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/JMC.dir/src/JMCEventAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JMC.dir/src/JMCEventAction.cc.o -c /home/patryk/Desktop/JMC/src/JMCEventAction.cc

CMakeFiles/JMC.dir/src/JMCEventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JMC.dir/src/JMCEventAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Desktop/JMC/src/JMCEventAction.cc > CMakeFiles/JMC.dir/src/JMCEventAction.cc.i

CMakeFiles/JMC.dir/src/JMCEventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JMC.dir/src/JMCEventAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Desktop/JMC/src/JMCEventAction.cc -o CMakeFiles/JMC.dir/src/JMCEventAction.cc.s

CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.requires:

.PHONY : CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.requires

CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.provides: CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.requires
	$(MAKE) -f CMakeFiles/JMC.dir/build.make CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.provides.build
.PHONY : CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.provides

CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.provides.build: CMakeFiles/JMC.dir/src/JMCEventAction.cc.o


CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o: CMakeFiles/JMC.dir/flags.make
CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o: src/JMCPrimartGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o -c /home/patryk/Desktop/JMC/src/JMCPrimartGeneratorAction.cc

CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Desktop/JMC/src/JMCPrimartGeneratorAction.cc > CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.i

CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Desktop/JMC/src/JMCPrimartGeneratorAction.cc -o CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.s

CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.requires:

.PHONY : CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.requires

CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.provides: CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.requires
	$(MAKE) -f CMakeFiles/JMC.dir/build.make CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.provides.build
.PHONY : CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.provides

CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.provides.build: CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o


CMakeFiles/JMC.dir/src/JMCRunAction.cc.o: CMakeFiles/JMC.dir/flags.make
CMakeFiles/JMC.dir/src/JMCRunAction.cc.o: src/JMCRunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/JMC.dir/src/JMCRunAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JMC.dir/src/JMCRunAction.cc.o -c /home/patryk/Desktop/JMC/src/JMCRunAction.cc

CMakeFiles/JMC.dir/src/JMCRunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JMC.dir/src/JMCRunAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Desktop/JMC/src/JMCRunAction.cc > CMakeFiles/JMC.dir/src/JMCRunAction.cc.i

CMakeFiles/JMC.dir/src/JMCRunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JMC.dir/src/JMCRunAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Desktop/JMC/src/JMCRunAction.cc -o CMakeFiles/JMC.dir/src/JMCRunAction.cc.s

CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.requires:

.PHONY : CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.requires

CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.provides: CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.requires
	$(MAKE) -f CMakeFiles/JMC.dir/build.make CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.provides.build
.PHONY : CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.provides

CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.provides.build: CMakeFiles/JMC.dir/src/JMCRunAction.cc.o


CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o: CMakeFiles/JMC.dir/flags.make
CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o: src/JMCSteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o -c /home/patryk/Desktop/JMC/src/JMCSteppingAction.cc

CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Desktop/JMC/src/JMCSteppingAction.cc > CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.i

CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Desktop/JMC/src/JMCSteppingAction.cc -o CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.s

CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.requires:

.PHONY : CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.requires

CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.provides: CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/JMC.dir/build.make CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.provides.build
.PHONY : CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.provides

CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.provides.build: CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o


# Object files for target JMC
JMC_OBJECTS = \
"CMakeFiles/JMC.dir/JMC.cc.o" \
"CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o" \
"CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o" \
"CMakeFiles/JMC.dir/src/JMCEventAction.cc.o" \
"CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o" \
"CMakeFiles/JMC.dir/src/JMCRunAction.cc.o" \
"CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o"

# External object files for target JMC
JMC_EXTERNAL_OBJECTS =

JMC: CMakeFiles/JMC.dir/JMC.cc.o
JMC: CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o
JMC: CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o
JMC: CMakeFiles/JMC.dir/src/JMCEventAction.cc.o
JMC: CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o
JMC: CMakeFiles/JMC.dir/src/JMCRunAction.cc.o
JMC: CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o
JMC: CMakeFiles/JMC.dir/build.make
JMC: /home/patryk/geant4/lib/libG4Tree.so
JMC: /home/patryk/geant4/lib/libG4GMocren.so
JMC: /home/patryk/geant4/lib/libG4visHepRep.so
JMC: /home/patryk/geant4/lib/libG4RayTracer.so
JMC: /home/patryk/geant4/lib/libG4VRML.so
JMC: /home/patryk/geant4/lib/libG4OpenGL.so
JMC: /home/patryk/geant4/lib/libG4gl2ps.so
JMC: /home/patryk/geant4/lib/libG4interfaces.so
JMC: /home/patryk/geant4/lib/libG4persistency.so
JMC: /home/patryk/geant4/lib/libG4analysis.so
JMC: /home/patryk/geant4/lib/libG4error_propagation.so
JMC: /home/patryk/geant4/lib/libG4readout.so
JMC: /home/patryk/geant4/lib/libG4physicslists.so
JMC: /home/patryk/geant4/lib/libG4parmodels.so
JMC: /home/patryk/geant4/lib/libG4FR.so
JMC: /home/patryk/geant4/lib/libG4vis_management.so
JMC: /home/patryk/geant4/lib/libG4modeling.so
JMC: /usr/lib/x86_64-linux-gnu/libGLU.so
JMC: /usr/lib/x86_64-linux-gnu/libGL.so
JMC: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
JMC: /usr/lib/x86_64-linux-gnu/libQtGui.so
JMC: /usr/lib/x86_64-linux-gnu/libQtCore.so
JMC: /usr/local/lib/libxerces-c.so
JMC: /home/patryk/geant4/lib/libG4run.so
JMC: /home/patryk/geant4/lib/libG4event.so
JMC: /home/patryk/geant4/lib/libG4tracking.so
JMC: /home/patryk/geant4/lib/libG4processes.so
JMC: /home/patryk/geant4/lib/libG4zlib.so
JMC: /usr/lib/x86_64-linux-gnu/libexpat.so
JMC: /home/patryk/geant4/lib/libG4digits_hits.so
JMC: /home/patryk/geant4/lib/libG4track.so
JMC: /home/patryk/geant4/lib/libG4particles.so
JMC: /home/patryk/geant4/lib/libG4geometry.so
JMC: /home/patryk/geant4/lib/libG4materials.so
JMC: /home/patryk/geant4/lib/libG4graphics_reps.so
JMC: /home/patryk/geant4/lib/libG4intercoms.so
JMC: /home/patryk/geant4/lib/libG4global.so
JMC: /home/patryk/geant4/lib/libG4clhep.so
JMC: CMakeFiles/JMC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/patryk/Desktop/JMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable JMC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JMC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JMC.dir/build: JMC

.PHONY : CMakeFiles/JMC.dir/build

CMakeFiles/JMC.dir/requires: CMakeFiles/JMC.dir/JMC.cc.o.requires
CMakeFiles/JMC.dir/requires: CMakeFiles/JMC.dir/src/JMCActionInitialization.cc.o.requires
CMakeFiles/JMC.dir/requires: CMakeFiles/JMC.dir/src/JMCDetectorConstruction.cc.o.requires
CMakeFiles/JMC.dir/requires: CMakeFiles/JMC.dir/src/JMCEventAction.cc.o.requires
CMakeFiles/JMC.dir/requires: CMakeFiles/JMC.dir/src/JMCPrimartGeneratorAction.cc.o.requires
CMakeFiles/JMC.dir/requires: CMakeFiles/JMC.dir/src/JMCRunAction.cc.o.requires
CMakeFiles/JMC.dir/requires: CMakeFiles/JMC.dir/src/JMCSteppingAction.cc.o.requires

.PHONY : CMakeFiles/JMC.dir/requires

CMakeFiles/JMC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JMC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JMC.dir/clean

CMakeFiles/JMC.dir/depend:
	cd /home/patryk/Desktop/JMC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patryk/Desktop/JMC /home/patryk/Desktop/JMC /home/patryk/Desktop/JMC /home/patryk/Desktop/JMC /home/patryk/Desktop/JMC/CMakeFiles/JMC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JMC.dir/depend

