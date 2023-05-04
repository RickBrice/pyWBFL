#include "pch.h"
#include "PPPartialUniformLoad.h"

using namespace WBFL::Beams;
namespace py = pybind11;


#include "Trampoline.h"

void export_PPPartialUniformLoad_types(py::module_& m)
{
   py::class_<PPPartialUniformLoad, RoarkBeam, PyRoarkBeamInstance<PPPartialUniformLoad>>(m, "PPPartialUniformLoad")
      .def(py::init<Float64, Float64, Float64, Float64, Float64>())
      .def_property("La", &PPPartialUniformLoad::GetLa, &PPPartialUniformLoad::SetLa)
      .def_property("Lb", &PPPartialUniformLoad::GetLb, &PPPartialUniformLoad::SetLb)
      .def_property("w", &PPPartialUniformLoad::GetW, &PPPartialUniformLoad::SetW)
      ;
}