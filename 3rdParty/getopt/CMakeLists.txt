include_directories (include)
file(GLOB_RECURSE HDR_LIST *.h *.hpp)
source_group("Header Files" FILES ${HDR_LIST})
# aux_source_directory (src SRC_LIST)
set (LIB_SRC_LIST src/getopt.c)
add_definitions (-D_GETOPT_API)
add_library(getopt ${LIB_SRC_LIST} ${HDR_LIST})

set_target_properties(getopt PROPERTIES FOLDER "wordfreq 3rd Libraries")

set (GETOPT_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE STRING "getopt for windows" FORCE)
