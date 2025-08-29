cmake_minimum_required(VERSION 3.21)
project(ssp LANGUAGES C CXX)

# Set C standard
if("c_std_23" IN_LIST CMAKE_C_COMPILE_FEATURES)
  set(CMAKE_C_STANDARD 23)
elseif("c_std_17" IN_LIST CMAKE_C_COMPILE_FEATURES)
  set(CMAKE_C_STANDARD 17)
endif()
message(STATUS "CMAKE_C_STANDARD is '${CMAKE_C_STANDARD}'.")
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(ssp STATIC
  gets_chk.c
  memcpy_chk.c
  memmove_chk.c
  mempcpy_chk.c
  memset_chk.c
  stack_chk_fail.c
  stack_chk_guard.c
  stpcpy_chk.c
  strcat_chk.c
  strcpy_chk.c
  strncat_chk.c
  strncpy_chk.c
  ssp.h
)
if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
  set_target_properties(ssp PROPERTIES OUTPUT_NAME "libssp.a")
endif()

install(TARGETS ssp
  ARCHIVE DESTINATION lib
)

install(FILES
  ssp.h
  DESTINATION include
)
