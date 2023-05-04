#include "pch.h"
#include "CompositeBeam.h"

using namespace WBFL::Beams;
namespace py = pybind11;


#include "Trampoline.h"

void export_CompositeBeam_types(py::module_& m)
{
   // need to define a pointer to a function for the version of AddBeam we want to export
   // the version that takes a unique_ptr by move operation isn't working
   void(CompositeBeam:: * AddBeam)(const RoarkBeam&) = &CompositeBeam::AddBeam;
   void(CompositeBeam:: * AddBeamShared)(std::shared_ptr<RoarkBeam>) = &CompositeBeam::AddBeam;

   py::class_<CompositeBeam, RoarkBeam, PyRoarkBeamInstance<CompositeBeam>>(m, "CompositeBeam")
      .def(py::init())
      .def("add_beam", AddBeam)
      .def("add_beam", AddBeamShared)
      .def("count", &CompositeBeam::GetBeamCount)
      .def("beam",&CompositeBeam::GetBeam, py::return_value_policy::reference)
      .def("clear",&CompositeBeam::RemoveAllBeams)
      ;
}