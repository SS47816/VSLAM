cmake_minimum_required(VERSION 3.10)
project(hello)
IF(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
ENDIF()

set(INCLUDE_DIR include/)
set(SRC_DIR src/)

include_directories(${INCLUDE_DIR})
add_library(libhello SHARED ${SRC_DIR}/hello.cpp)

add_executable(sayhello ${SRC_DIR}/useHello.cpp)
target_link_libraries(sayhello libhello)

set(CMAKE_INSTALL_DIR /usr/local)
install(FILES ${INCLUDE_DIR}/hello.h DESTINATION ${CMAKE_INSTALL_DIR}/include)
install(TARGETS libhello LIBRARY DESTINATION ${CMAKE_INSTALL_DIR}/lib)