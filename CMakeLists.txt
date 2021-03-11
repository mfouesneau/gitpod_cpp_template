# CMAKE options and configuration
cmake_minimum_required(VERSION 3.0.0)
project(cpp-template VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build)

# generate the executables in the root directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# side load cmake scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# with xtensor we need some math libraries
find_package(BLAS REQUIRED)
message( STATUS "BLAS found: ${blas_libraries}" )
find_package(LAPACK REQUIRED)
message( STATUS "LAPACK found: ${lapack_libraries}" )

# add conan
# ---------
# target_link_libraries(example ${CONAN_LIBS})
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# add local includes
# ------------------
include_directories("./include")

# Define executables
# ------------------

add_executable(main main.cpp)

# Link the executables to external libraries
target_link_libraries(main
	${blas_libraries} ${lapack_libraries} ${CONAN_LIBS})

# Where to install the targets --
install(TARGETS main 
        CONFIGURATIONS runtime
        RUNTIME DESTINATION bin
        )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
