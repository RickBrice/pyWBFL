#include "pch.h"
#include "PPIntermediateCouple.h"

using namespace WBFL::Beams;
namespace py = pybind11;


#include "Trampoline.h"

void export_PPIntermediateCouple_types(py::module_& m)
{
   py::class_<PPIntermediateCouple, RoarkBeam, PyRoarkBeamInstance<PPIntermediateCouple>>(m, "PPIntermediateCouple")
      .def(py::init<Float64, Float64, Float64, Float64>())
      .def_property("La", &PPIntermediateCouple::GetLa, &PPIntermediateCouple::SetLa)
      //.def("Lb", &PPIntermediateCouple::GetLb)
      .def_property("Mo", &PPIntermediateCouple::GetMo, &PPIntermediateCouple::SetMo)
      ;
}