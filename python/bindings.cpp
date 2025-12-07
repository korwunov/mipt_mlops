#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "gauss_jordan.hpp"

namespace py = pybind11;

PYBIND11_MODULE(gauss_jordan_ext, m) {
    m.doc() = "pybind11 gauss jordan";
    m.def("gauss_jordan", &gje::gauss_jordan, "Solve AX = B using Gauss-Jordan impl", py::arg("A"), py::arg("B"));
}