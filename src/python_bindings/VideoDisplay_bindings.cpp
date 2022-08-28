#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <QtWidgets>
#include "VideoDisplay.hpp"


namespace py = pybind11;

void init_VideoDisplay(py::module & m){
    py::class_<QWidget>(m, "QWidget");
    py::class_<VideoPlayer, QWidget>(m, "VideoPlayer")
        .def(py::init<>())
        .def("set_video", &VideoPlayer::set_video);

}