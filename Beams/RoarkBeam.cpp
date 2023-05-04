#include "pch.h"
#include "RoarkBeam.h"

using namespace WBFL::Beams;
namespace py = pybind11;


#include "Trampoline.h"

void export_RoarkBeam_types(py::module_& m)
{
   py::class_<RoarkBeam, PyRoarkBeamBase<>>(m, "Beam")
      .def_property("L", &RoarkBeam::GetL, &RoarkBeam::SetL)
      .def_property("EI", &RoarkBeam::GetEI, &RoarkBeam::SetEI)
#if defined ENABLE_CREATE_CLONE
      .def("clone", &RoarkBeam::CreateClone)
#endif
      .def("reactions", &RoarkBeam::GetReactions)
      .def("moments", &RoarkBeam::GetMoments)
      .def("rotations", &RoarkBeam::GetRotations)
      .def("deflections", &RoarkBeam::GetDeflections)
      .def("shear", &RoarkBeam::ComputeShear)
      .def("moment", &RoarkBeam::ComputeMoment)
      .def("rotation", &RoarkBeam::ComputeRotation)
      .def("deflection", &RoarkBeam::ComputeDeflection)
      ;
}
