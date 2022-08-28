#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include "VideoDisplay.hpp"


namespace py = pybind11;

void init_VideoDisplay(py::module & m){
    py::class_<VideoPlayer>(m, "VideoPlayer")
        .def(py::init<>());

}