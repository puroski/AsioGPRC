# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nomenas/Projects/AsioGPRC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nomenas/Projects/AsioGPRC/cmake-build-debug

# Utility rule file for taojson.

# Include the progress variables for this target.
include CMakeFiles/taojson.dir/progress.make

CMakeFiles/taojson: CMakeFiles/taojson-complete


CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-install
CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-mkdir
CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-download
CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-update
CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-patch
CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-configure
CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-build
CMakeFiles/taojson-complete: taojson-prefix/src/taojson-stamp/taojson-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'taojson'"
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles
	/snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles/taojson-complete
	/snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-done

taojson-prefix/src/taojson-stamp/taojson-install: taojson-prefix/src/taojson-stamp/taojson-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'taojson'"
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-build && $(MAKE) install
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-build && /snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-install

taojson-prefix/src/taojson-stamp/taojson-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'taojson'"
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-build
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/tmp
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src
	/snap/clion/107/bin/cmake/linux/bin/cmake -E make_directory /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp
	/snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-mkdir

taojson-prefix/src/taojson-stamp/taojson-download: taojson-prefix/src/taojson-stamp/taojson-gitinfo.txt
taojson-prefix/src/taojson-stamp/taojson-download: taojson-prefix/src/taojson-stamp/taojson-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'taojson'"
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src && /snap/clion/107/bin/cmake/linux/bin/cmake -P /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/tmp/taojson-gitclone.cmake
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src && /snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-download

taojson-prefix/src/taojson-stamp/taojson-update: taojson-prefix/src/taojson-stamp/taojson-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'taojson'"
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson && /snap/clion/107/bin/cmake/linux/bin/cmake -P /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/tmp/taojson-gitupdate.cmake

taojson-prefix/src/taojson-stamp/taojson-patch: taojson-prefix/src/taojson-stamp/taojson-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'taojson'"
	/snap/clion/107/bin/cmake/linux/bin/cmake -E echo_append
	/snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-patch

taojson-prefix/src/taojson-stamp/taojson-configure: taojson-prefix/tmp/taojson-cfgcmd.txt
taojson-prefix/src/taojson-stamp/taojson-configure: taojson-prefix/src/taojson-stamp/taojson-update
taojson-prefix/src/taojson-stamp/taojson-configure: taojson-prefix/src/taojson-stamp/taojson-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'taojson'"
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-build && /snap/clion/107/bin/cmake/linux/bin/cmake -DTAOCPP_JSON_BUILD_EXAMPLES=OFF -DTAOCPP_JSON_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/external "-GCodeBlocks - Unix Makefiles" /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-build && /snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-configure

taojson-prefix/src/taojson-stamp/taojson-build: taojson-prefix/src/taojson-stamp/taojson-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'taojson'"
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-build && $(MAKE)
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-build && /snap/clion/107/bin/cmake/linux/bin/cmake -E touch /home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-build

taojson: CMakeFiles/taojson
taojson: CMakeFiles/taojson-complete
taojson: taojson-prefix/src/taojson-stamp/taojson-install
taojson: taojson-prefix/src/taojson-stamp/taojson-mkdir
taojson: taojson-prefix/src/taojson-stamp/taojson-download
taojson: taojson-prefix/src/taojson-stamp/taojson-update
taojson: taojson-prefix/src/taojson-stamp/taojson-patch
taojson: taojson-prefix/src/taojson-stamp/taojson-configure
taojson: taojson-prefix/src/taojson-stamp/taojson-build
taojson: CMakeFiles/taojson.dir/build.make

.PHONY : taojson

# Rule to build all files generated by this target.
CMakeFiles/taojson.dir/build: taojson

.PHONY : CMakeFiles/taojson.dir/build

CMakeFiles/taojson.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/taojson.dir/cmake_clean.cmake
.PHONY : CMakeFiles/taojson.dir/clean

CMakeFiles/taojson.dir/depend:
	cd /home/nomenas/Projects/AsioGPRC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nomenas/Projects/AsioGPRC /home/nomenas/Projects/AsioGPRC /home/nomenas/Projects/AsioGPRC/cmake-build-debug /home/nomenas/Projects/AsioGPRC/cmake-build-debug /home/nomenas/Projects/AsioGPRC/cmake-build-debug/CMakeFiles/taojson.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/taojson.dir/depend

