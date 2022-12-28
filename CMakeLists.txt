cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(ProjetMathCpp)

# add libRational
message(STATUS "libRational cmake part ..." )
add_subdirectory(libRational INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/libRational/include) # important : other projects call by this cmake will know this include directory

#add rationalSamples
message(STATUS "rationalSamples cmake part ..." )
add_subdirectory(rationalSamples)

# remplacer les parties suivantes par la partie commentée quand on a fini avec les tests

# add google test
message(STATUS "google test cmake part ..." )
add_subdirectory(googletest)

# add myTest
message(STATUS "myUnitTests cmake part ..." )
add_subdirectory(myUnitTests)

#[[
#add myUnitTests
find_package(GTest OPTIONAL_COMPONENTS)
if(GTEST_FOUND)
	message(STATUS "myUnitTests cmake part ..." )
	add_subdirectory(myUnitTests)
elseif()
	message(WARNING "google test not found, skipping myTest ..." )
endif()]]
