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

#[[# add myCode
message(STATUS "myCode cmake part ..." )
add_subdirectory(myCode)

# add google test
message(STATUS "google test cmake part ..." )
add_subdirectory(googletest)

# add myTest
message(STATUS "myTest cmake part ..." )
add_subdirectory(myTest)]]
