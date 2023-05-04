#include "pch.h"
#include "PPIntermediateLoad.h"

using namespace WBFL::Beams;
namespace py = pybind11;


#include "Trampoline.h"

void export_PPIntermediateLoad_types(py::module_& m)
{
   py::class_<PPIntermediateLoad, RoarkBeam, PyRoarkBeamInstance<PPIntermediateLoad>>(m, "PPIntermediateLoad")
      .def(py::init<Float64, Float64, Float64, Float64>())
      .def_property("La", &PPIntermediateLoad::GetLa, &PPIntermediateLoad::SetLa)
      .def("Lb", &PPIntermediateLoad::GetLb)
      .def_property("p", &PPIntermediateLoad::GetW, &PPIntermediateLoad::SetW)
      ;
}