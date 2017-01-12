if (MSVC)
    include_directories (${GETOPT_INCLUDE_DIR})
endif (MSVC)

add_executable (wordfreq wordfreq.cpp)
set_target_properties(wordfreq PROPERTIES FOLDER "wordfreq executables")

if (MSVC)
    target_link_libraries (wordfreq getopt)
endif (MSVC)
