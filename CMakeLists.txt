cmake_minimum_required(VERSION 3.0)
project(libstringext VERSION 1.1.0)

execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set (ROOT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")

file(GLOB STRINGEXT_SRC
  "${ROOT_SOURCE_DIR}/*.c"
)

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

#Includes
file(GLOB INCLUDE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

set(CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
if (HAVE_C11)
  set(CMAKE_C_STANDARD 11)
else()
  set(CMAKE_C_STANDARD 99)
endif(HAVE_C11)
set(CMAKE_BUILD_TYPE DEBUG)

add_definitions("-DGIT_COMMIT=${GIT_COMMIT_HASH}")

add_library(stringext_shared SHARED ${STRINGEXT_SRC})
set_target_properties(stringext_shared PROPERTIES OUTPUT_NAME stringext)
set_target_properties(stringext_shared PROPERTIES VERSION 0.1.0)
add_library(stringext_static STATIC ${STRINGEXT_SRC})
set_target_properties(stringext_static PROPERTIES OUTPUT_NAME stringext)

#Tests
if (WITH_TEST)

endif (WITH_TEST)

#Install rules
install(TARGETS stringext_shared CONFIGURATIONS Release LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include)
install(TARGETS stringext_static CONFIGURATIONS Release ARCHIVE DESTINATION lib)
install(FILES ${INCLUDE_FILES} DESTINATION include/)
