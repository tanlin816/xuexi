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
CMAKE_SOURCE_DIR = /home/tanlin/Imageprocessing/cmake/IntensityResolution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tanlin/Imageprocessing/cmake/IntensityResolution

# Include any dependencies generated for this target.
include CMakeFiles/example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example.dir/flags.make

CMakeFiles/example.dir/main.cpp.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tanlin/Imageprocessing/cmake/IntensityResolution/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/main.cpp.o -c /home/tanlin/Imageprocessing/cmake/IntensityResolution/main.cpp

CMakeFiles/example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tanlin/Imageprocessing/cmake/IntensityResolution/main.cpp > CMakeFiles/example.dir/main.cpp.i

CMakeFiles/example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tanlin/Imageprocessing/cmake/IntensityResolution/main.cpp -o CMakeFiles/example.dir/main.cpp.s

CMakeFiles/example.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/example.dir/main.cpp.o.requires

CMakeFiles/example.dir/main.cpp.o.provides: CMakeFiles/example.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/example.dir/build.make CMakeFiles/example.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/example.dir/main.cpp.o.provides

CMakeFiles/example.dir/main.cpp.o.provides.build: CMakeFiles/example.dir/main.cpp.o


# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/main.cpp.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

example: CMakeFiles/example.dir/main.cpp.o
example: CMakeFiles/example.dir/build.make
example: /usr/local/lib/libopencv_viz.so.3.1.0
example: /usr/local/lib/libopencv_videostab.so.3.1.0
example: /usr/local/lib/libopencv_superres.so.3.1.0
example: /usr/local/lib/libopencv_stitching.so.3.1.0
example: /usr/local/lib/libopencv_shape.so.3.1.0
example: /usr/local/lib/libopencv_photo.so.3.1.0
example: /usr/local/lib/libopencv_objdetect.so.3.1.0
example: /usr/local/lib/libopencv_calib3d.so.3.1.0
example: /usr/local/lib/libopencv_features2d.so.3.1.0
example: /usr/local/lib/libopencv_ml.so.3.1.0
example: /usr/local/lib/libopencv_highgui.so.3.1.0
example: /usr/local/lib/libopencv_videoio.so.3.1.0
example: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
example: /usr/local/lib/libopencv_flann.so.3.1.0
example: /usr/local/lib/libopencv_video.so.3.1.0
example: /usr/local/lib/libopencv_imgproc.so.3.1.0
example: /usr/local/lib/libopencv_core.so.3.1.0
example: CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tanlin/Imageprocessing/cmake/IntensityResolution/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example.dir/build: example

.PHONY : CMakeFiles/example.dir/build

CMakeFiles/example.dir/requires: CMakeFiles/example.dir/main.cpp.o.requires

.PHONY : CMakeFiles/example.dir/requires

CMakeFiles/example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example.dir/clean

CMakeFiles/example.dir/depend:
	cd /home/tanlin/Imageprocessing/cmake/IntensityResolution && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tanlin/Imageprocessing/cmake/IntensityResolution /home/tanlin/Imageprocessing/cmake/IntensityResolution /home/tanlin/Imageprocessing/cmake/IntensityResolution /home/tanlin/Imageprocessing/cmake/IntensityResolution /home/tanlin/Imageprocessing/cmake/IntensityResolution/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example.dir/depend

