cmake_minimum_required(VERSION 3.28)
project(PcanLibExample)

set(CMAKE_CXX_STANDARD 17)

# Add the PcanLib include directory
include_directories(${PROJECT_SOURCE_DIR}/PcanLib/Include)

# Add the PcanLib library directory for 64-bit and 32-bit
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64-bit
    link_directories(${PROJECT_SOURCE_DIR}/PcanLib/x64/VC_LIB)
else ()
    # 32-bit
    link_directories(${PROJECT_SOURCE_DIR}/PcanLib/x86/VC_LIB)
endif ()

# Add the executable
add_executable(PcanLibExample main.cpp)

# Link the PcanLib library
target_link_libraries(PcanLibExample PCANBasic)