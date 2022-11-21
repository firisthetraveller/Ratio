cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(myProject)

# add myCode
message(STATUS "Ratio cmake part ..." )
add_subdirectory(libRatio)
message(STATUS "Ratio cmake part: OK" )

# add myTest
find_package(GTest OPTIONAL_COMPONENTS)
if(GTEST_FOUND)
	message(STATUS "unitTest cmake part ..." )
	add_subdirectory(unitTest)
	message(STATUS "unitTest cmake part: OK" )
elseif()
	message(WARNING "google test not found, skipping unitTest ..." )
endif()
