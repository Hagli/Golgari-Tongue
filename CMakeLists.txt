cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Golgari-Tongue VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add parser library
add_library(parser "${PROJECT_SOURCE_DIR}/bin/lib/impl/lexer.cpp" "${PROJECT_SOURCE_DIR}/bin/lib/impl/parser.cpp")

# add the executable
add_executable(Golgari-Tongue "${PROJECT_SOURCE_DIR}/bin/src/impl/driver.cpp")

target_link_libraries(Golgari-Tongue parser)

target_include_directories(Golgari-Tongue PUBLIC
                        "${PROJECT_BINARY_DIR}"
                           )