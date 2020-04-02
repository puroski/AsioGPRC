
if(NOT "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-gitinfo.txt" IS_NEWER_THAN "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone  "https://github.com/taocpp/json.git" "taojson"
    WORKING_DIRECTORY "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/taocpp/json.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout master --
  WORKING_DIRECTORY "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  submodule update --recursive --init 
  WORKING_DIRECTORY "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-gitinfo.txt"
    "/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/nomenas/Projects/AsioGPRC/cmake-build-debug/taojson-prefix/src/taojson-stamp/taojson-gitclone-lastrun.txt'")
endif()

