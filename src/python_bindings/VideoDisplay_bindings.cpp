#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <QtWidgets>
#include "VideoDisplay.hpp"
#include <iostream>


namespace py = pybind11;


void init_VideoDisplay(py::module & m){
    py::class_< VideoPlayer, std::unique_ptr<VideoPlayer, py::nodelete> >(m, "VideoPlayer")
        .def(py::init<>())
        .def("set_video", &VideoPlayer::set_video);
}