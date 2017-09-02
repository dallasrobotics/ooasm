cmake_minimum_required(VERSION 3.8)

project(ooasm)

include(CheckCXXSourceCompiles)

set(CMAKE_CXX_STANDARD 11)

set(OOASM_XTL_DIR "" CACHE PATH "Path to xtl repo")

set(CMAKE_REQUIRED_INCLUDES ${OOASM_XTL_DIR}/include)

CHECK_CXX_SOURCE_COMPILES(
  "
  #include <xtd/xtd.hpp>
  int main(){return 0;}
  "
  XTL_COMPILES
)

if(NOT OOASM_XTL_DIR OR NOT XTL_COMPILES)
  message(FATAL_ERROR "OOASM_XTL_DIR not properly set")
endif()

include_directories(${OOASM_XTL_DIR}/include)

set(SOURCE_FILES src/ooasm.cpp src/ooasm.hpp src/cli.hpp)

add_executable(ooasm ${SOURCE_FILES})
