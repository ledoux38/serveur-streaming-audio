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
CMAKE_SOURCE_DIR = "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation"

# Include any dependencies generated for this target.
include CMakeFiles/CLIENT_SERVEUR_UDP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLIENT_SERVEUR_UDP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o: ../src/encodeur_audio/encodeur_audio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/encodeur_audio/encodeur_audio.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/encodeur_audio/encodeur_audio.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/encodeur_audio/encodeur_audio.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o


CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o: ../src/audiostream/audiostream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/audiostream/audiostream.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/audiostream/audiostream.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/audiostream/audiostream.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o


CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/main.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/main.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/main.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o


CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o: ../src/socket_client/client_udp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/socket_client/client_udp.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/socket_client/client_udp.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/socket_client/client_udp.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o


CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o: ../src/decodeur_audio/decodeur_audio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/decodeur_audio/decodeur_audio.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/decodeur_audio/decodeur_audio.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/decodeur_audio/decodeur_audio.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o


CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o: ../src/utils/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/utils/utils.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/utils/utils.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/utils/utils.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o


CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o: ../src/analyse_audio/analyse_audio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/analyse_audio/analyse_audio.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/analyse_audio/analyse_audio.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/analyse_audio/analyse_audio.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o


CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o: CMakeFiles/CLIENT_SERVEUR_UDP.dir/flags.make
CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o: ../src/socket_serveur/serveur_udp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o -c "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/socket_serveur/serveur_udp.cpp"

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/socket_serveur/serveur_udp.cpp" > CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.i

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/src/socket_serveur/serveur_udp.cpp" -o CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.s

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.requires:

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.provides: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.provides.build
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.provides

CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.provides.build: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o


# Object files for target CLIENT_SERVEUR_UDP
CLIENT_SERVEUR_UDP_OBJECTS = \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o" \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o" \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o" \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o" \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o" \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o" \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o" \
"CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o"

# External object files for target CLIENT_SERVEUR_UDP
CLIENT_SERVEUR_UDP_EXTERNAL_OBJECTS =

CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/build.make
CLIENT_SERVEUR_UDP: /usr/lib/x86_64-linux-gnu/libsfml-network.so
CLIENT_SERVEUR_UDP: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
CLIENT_SERVEUR_UDP: /usr/lib/x86_64-linux-gnu/libsfml-system.so
CLIENT_SERVEUR_UDP: CMakeFiles/CLIENT_SERVEUR_UDP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable CLIENT_SERVEUR_UDP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLIENT_SERVEUR_UDP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLIENT_SERVEUR_UDP.dir/build: CLIENT_SERVEUR_UDP

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/build

CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/encodeur_audio/encodeur_audio.cpp.o.requires
CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/audiostream/audiostream.cpp.o.requires
CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/main.cpp.o.requires
CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_client/client_udp.cpp.o.requires
CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/decodeur_audio/decodeur_audio.cpp.o.requires
CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/utils/utils.cpp.o.requires
CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/analyse_audio/analyse_audio.cpp.o.requires
CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires: CMakeFiles/CLIENT_SERVEUR_UDP.dir/src/socket_serveur/serveur_udp.cpp.o.requires

.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/requires

CMakeFiles/CLIENT_SERVEUR_UDP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CLIENT_SERVEUR_UDP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/clean

CMakeFiles/CLIENT_SERVEUR_UDP.dir/depend:
	cd "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio" "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio" "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation" "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation" "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/version stable/serveur-streaming-audio/compilation/CMakeFiles/CLIENT_SERVEUR_UDP.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CLIENT_SERVEUR_UDP.dir/depend

