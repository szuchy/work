# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /media/patryk/AE984EB8984E7F391/RADEM_lip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/patryk/AE984EB8984E7F391/RADEM_lip

# Include any dependencies generated for this target.
include CMakeFiles/g4NGRM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/g4NGRM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/g4NGRM.dir/flags.make

CMakeFiles/g4NGRM.dir/g4NGRM.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/g4NGRM.cc.o: g4NGRM.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/g4NGRM.dir/g4NGRM.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/g4NGRM.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/g4NGRM.cc

CMakeFiles/g4NGRM.dir/g4NGRM.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/g4NGRM.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/g4NGRM.cc > CMakeFiles/g4NGRM.dir/g4NGRM.cc.i

CMakeFiles/g4NGRM.dir/g4NGRM.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/g4NGRM.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/g4NGRM.cc -o CMakeFiles/g4NGRM.dir/g4NGRM.cc.s

CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.requires

CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.provides: CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.provides

CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.provides.build: CMakeFiles/g4NGRM.dir/g4NGRM.cc.o


CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o: src/AnalysisManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/AnalysisManager.cc

CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/AnalysisManager.cc > CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.i

CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/AnalysisManager.cc -o CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.s

CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.requires

CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.provides: CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.provides

CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o


CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o: src/AnalysisMessenger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/AnalysisMessenger.cc

CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/AnalysisMessenger.cc > CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.i

CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/AnalysisMessenger.cc -o CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.s

CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.requires

CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.provides: CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.provides

CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o


CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o: src/DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/DetectorConstruction.cc

CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/DetectorConstruction.cc > CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.i

CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/DetectorConstruction.cc -o CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.s

CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.requires

CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.provides: CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.provides

CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o


CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o: src/DetectorMessenger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/DetectorMessenger.cc

CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/DetectorMessenger.cc > CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.i

CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/DetectorMessenger.cc -o CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.s

CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.requires

CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.provides: CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.provides

CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o


CMakeFiles/g4NGRM.dir/src/EventAction.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/EventAction.cc.o: src/EventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/g4NGRM.dir/src/EventAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/EventAction.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/EventAction.cc

CMakeFiles/g4NGRM.dir/src/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/EventAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/EventAction.cc > CMakeFiles/g4NGRM.dir/src/EventAction.cc.i

CMakeFiles/g4NGRM.dir/src/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/EventAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/EventAction.cc -o CMakeFiles/g4NGRM.dir/src/EventAction.cc.s

CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.requires

CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.provides: CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.provides

CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/EventAction.cc.o


CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o: src/PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/PrimaryGeneratorAction.cc

CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/PrimaryGeneratorAction.cc > CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.i

CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/PrimaryGeneratorAction.cc -o CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.s

CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.requires

CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.provides: CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.provides

CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o


CMakeFiles/g4NGRM.dir/src/RunAction.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/RunAction.cc.o: src/RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/g4NGRM.dir/src/RunAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/RunAction.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/RunAction.cc

CMakeFiles/g4NGRM.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/RunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/RunAction.cc > CMakeFiles/g4NGRM.dir/src/RunAction.cc.i

CMakeFiles/g4NGRM.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/RunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/RunAction.cc -o CMakeFiles/g4NGRM.dir/src/RunAction.cc.s

CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.requires

CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.provides: CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.provides

CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/RunAction.cc.o


CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o: src/SpaceDetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/SpaceDetectorConstruction.cc

CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/SpaceDetectorConstruction.cc > CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.i

CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/SpaceDetectorConstruction.cc -o CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.s

CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.requires

CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.provides: CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.provides

CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o


CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o: src/SteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/SteppingAction.cc

CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/SteppingAction.cc > CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.i

CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/SteppingAction.cc -o CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.s

CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.requires

CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.provides: CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.provides

CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.provides.build: CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o


CMakeFiles/g4NGRM.dir/src/t2sim.C.o: CMakeFiles/g4NGRM.dir/flags.make
CMakeFiles/g4NGRM.dir/src/t2sim.C.o: src/t2sim.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/g4NGRM.dir/src/t2sim.C.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g4NGRM.dir/src/t2sim.C.o -c /media/patryk/AE984EB8984E7F391/RADEM_lip/src/t2sim.C

CMakeFiles/g4NGRM.dir/src/t2sim.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g4NGRM.dir/src/t2sim.C.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/patryk/AE984EB8984E7F391/RADEM_lip/src/t2sim.C > CMakeFiles/g4NGRM.dir/src/t2sim.C.i

CMakeFiles/g4NGRM.dir/src/t2sim.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g4NGRM.dir/src/t2sim.C.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/patryk/AE984EB8984E7F391/RADEM_lip/src/t2sim.C -o CMakeFiles/g4NGRM.dir/src/t2sim.C.s

CMakeFiles/g4NGRM.dir/src/t2sim.C.o.requires:

.PHONY : CMakeFiles/g4NGRM.dir/src/t2sim.C.o.requires

CMakeFiles/g4NGRM.dir/src/t2sim.C.o.provides: CMakeFiles/g4NGRM.dir/src/t2sim.C.o.requires
	$(MAKE) -f CMakeFiles/g4NGRM.dir/build.make CMakeFiles/g4NGRM.dir/src/t2sim.C.o.provides.build
.PHONY : CMakeFiles/g4NGRM.dir/src/t2sim.C.o.provides

CMakeFiles/g4NGRM.dir/src/t2sim.C.o.provides.build: CMakeFiles/g4NGRM.dir/src/t2sim.C.o


# Object files for target g4NGRM
g4NGRM_OBJECTS = \
"CMakeFiles/g4NGRM.dir/g4NGRM.cc.o" \
"CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o" \
"CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o" \
"CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o" \
"CMakeFiles/g4NGRM.dir/src/EventAction.cc.o" \
"CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/g4NGRM.dir/src/RunAction.cc.o" \
"CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o" \
"CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o" \
"CMakeFiles/g4NGRM.dir/src/t2sim.C.o"

# External object files for target g4NGRM
g4NGRM_EXTERNAL_OBJECTS =

g4NGRM: CMakeFiles/g4NGRM.dir/g4NGRM.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/EventAction.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/RunAction.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o
g4NGRM: CMakeFiles/g4NGRM.dir/src/t2sim.C.o
g4NGRM: CMakeFiles/g4NGRM.dir/build.make
g4NGRM: /home/patryk/geant4/lib/libG4Tree.so
g4NGRM: /home/patryk/geant4/lib/libG4GMocren.so
g4NGRM: /home/patryk/geant4/lib/libG4visHepRep.so
g4NGRM: /home/patryk/geant4/lib/libG4RayTracer.so
g4NGRM: /home/patryk/geant4/lib/libG4VRML.so
g4NGRM: /home/patryk/geant4/lib/libG4OpenGL.so
g4NGRM: /home/patryk/geant4/lib/libG4gl2ps.so
g4NGRM: /home/patryk/geant4/lib/libG4interfaces.so
g4NGRM: /home/patryk/geant4/lib/libG4persistency.so
g4NGRM: /home/patryk/geant4/lib/libG4analysis.so
g4NGRM: /home/patryk/geant4/lib/libG4error_propagation.so
g4NGRM: /home/patryk/geant4/lib/libG4readout.so
g4NGRM: /home/patryk/geant4/lib/libG4physicslists.so
g4NGRM: /home/patryk/geant4/lib/libG4parmodels.so
g4NGRM: /home/patryk/geant4/lib/libG4FR.so
g4NGRM: /home/patryk/geant4/lib/libG4vis_management.so
g4NGRM: /home/patryk/geant4/lib/libG4modeling.so
g4NGRM: /usr/lib/x86_64-linux-gnu/libGLU.so
g4NGRM: /usr/lib/x86_64-linux-gnu/libGL.so
g4NGRM: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
g4NGRM: /usr/lib/x86_64-linux-gnu/libQtGui.so
g4NGRM: /usr/lib/x86_64-linux-gnu/libQtCore.so
g4NGRM: /usr/local/lib/libxerces-c.so
g4NGRM: /home/patryk/geant4/lib/libG4run.so
g4NGRM: /home/patryk/geant4/lib/libG4event.so
g4NGRM: /home/patryk/geant4/lib/libG4tracking.so
g4NGRM: /home/patryk/geant4/lib/libG4processes.so
g4NGRM: /home/patryk/geant4/lib/libG4zlib.so
g4NGRM: /usr/lib/x86_64-linux-gnu/libexpat.so
g4NGRM: /home/patryk/geant4/lib/libG4digits_hits.so
g4NGRM: /home/patryk/geant4/lib/libG4track.so
g4NGRM: /home/patryk/geant4/lib/libG4particles.so
g4NGRM: /home/patryk/geant4/lib/libG4geometry.so
g4NGRM: /home/patryk/geant4/lib/libG4materials.so
g4NGRM: /home/patryk/geant4/lib/libG4graphics_reps.so
g4NGRM: /home/patryk/geant4/lib/libG4intercoms.so
g4NGRM: /home/patryk/geant4/lib/libG4global.so
g4NGRM: /home/patryk/geant4/lib/libG4clhep.so
g4NGRM: CMakeFiles/g4NGRM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable g4NGRM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/g4NGRM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/g4NGRM.dir/build: g4NGRM

.PHONY : CMakeFiles/g4NGRM.dir/build

CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/g4NGRM.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/AnalysisManager.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/AnalysisMessenger.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/DetectorConstruction.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/DetectorMessenger.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/EventAction.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/PrimaryGeneratorAction.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/RunAction.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/SpaceDetectorConstruction.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/SteppingAction.cc.o.requires
CMakeFiles/g4NGRM.dir/requires: CMakeFiles/g4NGRM.dir/src/t2sim.C.o.requires

.PHONY : CMakeFiles/g4NGRM.dir/requires

CMakeFiles/g4NGRM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/g4NGRM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/g4NGRM.dir/clean

CMakeFiles/g4NGRM.dir/depend:
	cd /media/patryk/AE984EB8984E7F391/RADEM_lip && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/patryk/AE984EB8984E7F391/RADEM_lip /media/patryk/AE984EB8984E7F391/RADEM_lip /media/patryk/AE984EB8984E7F391/RADEM_lip /media/patryk/AE984EB8984E7F391/RADEM_lip /media/patryk/AE984EB8984E7F391/RADEM_lip/CMakeFiles/g4NGRM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/g4NGRM.dir/depend

