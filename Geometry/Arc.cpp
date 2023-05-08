#include "pch.h"
#include "Arc.h"

using namespace WBFL::Geometry;

namespace py = pybind11;

void export_Arc_types(py::module_& m)
{
   Point2d& (Arc:: * GetStart)() = &Arc::GetStart;
   Point2d& (Arc:: * GetCenter)() = &Arc::GetCenter;
   Point2d& (Arc:: * GetEnd)() = &Arc::GetEnd;

   py::class_<WBFL::Geometry::Arc>(m, "Arc")
      .def_property("start_point", GetStart, &Arc::SetStart)
      .def_property("center_point", GetCenter, &Arc::SetCenter)
      .def_property("end_point", GetEnd, &Arc::SetEnd)
      .def("reverse", &Arc::Reverse)
      .def("radius", &Arc::GetRadius)
      .def("length", &Arc::GetLength)
      .def("distance", &Arc::Distance)
      .def("is_point_on_arc",&Arc::IsPointOnArc)
      .def("central_angle",&Arc::GetCentralAngle)
      .def("divide",&Arc::Divide)
      ;
}