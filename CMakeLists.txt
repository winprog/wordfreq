project (wordfreq)
cmake_minimum_required (VERSION 2.8)

# enable projecct folder
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# global output path
set (EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set (LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# 3rdParty libraries
if (MSVC)
    add_subdirectory ("3rdParty/getopt")
endif (MSVC)

add_subdirectory (src)
