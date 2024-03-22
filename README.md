# Fast Quasi-Harmonic Weights for Geometric Data Interpolation
Fork of https://github.com/wangyu9/qhw-code for Windows compatibility. OptimLib is replaced with [ensmallen](https://github.com/mlpack/ensmallen).

## Building
Install with vcpkg: `armadillo`, `intel-mkl`, `suitesparse`, `ensmallen`.

Then build with cmake:
```powershell
cmake -B build -DCMAKE_TOOLCHAIN_FILE="$ENV:VCPKG_ROOT\scripts\buildsystems\vcpkg.cmake"
cmake --build build
```