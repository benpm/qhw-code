# Find OpenMP
find_package(OpenMP)
# Find and configure SuiteSparse
find_package(suitesparse CONFIG REQUIRED)
# Find and configure Armadillo
find_package(Armadillo CONFIG REQUIRED)
# Find and configure MKL
set(MKL_LINK "dynamic")
find_package(MKL CONFIG REQUIRED)
# Find and configure eigen
find_package(Eigen3 CONFIG REQUIRED)
add_definitions(-DUSE_EIGEN)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(qhw
    qhw.cpp 
    alap.cpp 
    helper.cpp 
    mkl_for_cholmod.cpp 
    cholmod_l.cpp 
    matrix.cpp 
    cholmod_plus.cpp 
    mesh.cpp 
    matrix_dense.cpp 
    matrixIO.cpp
)
target_link_libraries(qhw PRIVATE
    SuiteSparse::amd
    SuiteSparse::btf
    SuiteSparse::klu
    SuiteSparse::ldl
    SuiteSparse::umfpack
    SuiteSparse::cholmod
    armadillo
    MKL::MKL
    OpenMP::OpenMP_CXX
    Eigen3::Eigen
    ensmallen
)
target_compile_features(qhw PRIVATE cxx_std_17)
