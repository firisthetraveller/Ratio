find_package (Doxygen)

message(VERBOSE "Doxigen settings :")
message(VERBOSE "VectorD_SOURCE_DIR :  " ${Ratio_SOURCE_DIR})
message(VERBOSE "VectorD_BINARY_DIR :  " ${Ratio_BINARY_DIR})
message(VERBOSE "DOXYGEN_EXECUTABLE :  " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (Doxyfile-html.cmake Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} Doxyfile-html)
endif (DOXYGEN_FOUND)
