#include "pch.h"
#include "Circle2d.h"

using namespace WBFL::Geometry;

namespace py = pybind11;

void export_Circle2d_types(py::module_& m)
{
   Float64& (Circle2d:: * GetRadius)() = &Circle2d::GetRadius;
   Point2d& (Circle2d:: * GetCenter)() = &Circle2d::GetCenter;

   py::class_<Circle2d>(m, "Circle2d")
      .def_property("radius", GetRadius, &Circle2d::SetRadius)
      .def_property("center_point", GetCenter, &Circle2d::SetCenter)
      .def("perimeter", &Circle2d::GetPerimeter)
      .def("is_point_on_perimeter", &Circle2d::IsPointOnPerimeter)
      ;
}