#include <pybind11/pybind11.h>
namespace py = pybind11;

void init_VideoDisplay(py::module &);


PYBIND11_MODULE(play_video_py, m) {
    init_VideoDisplay(m);
}
