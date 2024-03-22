cmake_minimum_required(VERSION 3.20)

project(QHW
    VERSION 1.0
    DESCRIPTION "Quasi Harmonic Weights"
    LANGUAGES CXX)

# MSBuild suppress all warnings
if(MSVC)
    add_compile_options(/W0)
endif()

# Find OpenMP
find_package(OpenMP)
# Find and configure SuiteSparse
find_package(suitesparse CONFIG REQUIRED)
# Find and configure Armadillo
find_package(Armadillo CONFIG REQUIRED)
add_library(Armadillo::Armadillo ALIAS armadillo)
# Find and configure MKL
set(MKL_LINK "dynamic")
add_definitions(-DDO_NOT_USE_MKL)
find_package(MKL CONFIG REQUIRED)
# Find and configure eigen
find_package(Eigen3 CONFIG REQUIRED)
add_definitions(-DUSE_EIGEN)

add_subdirectory(external/ensmallen)

include_directories(qhw)

add_executable(qhw
    qhw/qhw.cpp 
    qhw/alap.cpp 
    qhw/helper.cpp 
    qhw/cholmod_l.cpp 
    qhw/matrix.cpp 
    qhw/cholmod_plus.cpp 
    qhw/mesh.cpp 
    qhw/matrix_dense.cpp 
    qhw/matrixIO.cpp
)
target_link_libraries(qhw PRIVATE
    SuiteSparse::cholmod
    armadillo
    MKL::mkl_intel_ilp64
    MKL::mkl_intel_thread
    MKL::mkl_core
    OpenMP::OpenMP_CXX
    Eigen3::Eigen
    ensmallen
)
target_compile_features(qhw PRIVATE cxx_std_17)
