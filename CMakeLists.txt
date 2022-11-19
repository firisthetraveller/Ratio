cmake_minimum_required(VERSION 3.13)

# add myTest
find_package(GTest OPTIONAL_COMPONENTS)
if(GTEST_FOUND)
	message(STATUS "unitTest cmake part ..." )
	add_subdirectory(unitTest)
elseif()
	message(WARNING "google test not found, skipping unitTest ..." )
endif()
