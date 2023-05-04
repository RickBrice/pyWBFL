#include "pch.h"
#include "Line2d.h"

using namespace WBFL::Geometry;

namespace py = pybind11;

void export_Line2d_types(py::module_& m)
{
   Line2d& (Line2d:: * NormalOffset)(Float64) = &Line2d::Offset;
   Line2d& (Line2d:: * Offset)(Float64, Float64) = &Line2d::Offset;
   Line2d& (Line2d:: * OffsetWithSize)(const Size2d&) = &Line2d::Offset;
   Line2d(Line2d:: * OffsetBy)(Float64, Float64) const = &Line2d::OffsetBy;
   Line2d(Line2d:: * OffsetByWithSize)(const Size2d&) const = &Line2d::OffsetBy;
   Line2d(Line2d:: * Parallel1)(Float64, Line2d::Side) const = &Line2d::Parallel;
   Line2d(Line2d:: * Parallel2)(const Point2d&) const = &Line2d::Parallel;

   py::class_<Line2d> line2d(m, "Line2d");
   line2d
      .def(py::init<const Point2d&, const Point2d&>())
      .def(py::init<Float64, const Vector2d&>())
      .def(py::init<const Point2d&, const Vector2d&>())
      .def("contains_point",&Line2d::ContainsPoint)
      .def("slope",&Line2d::GetSlope)
      .def("is_colinear",&Line2d::IsColinear)
      .def("offset",Offset, py::return_value_policy::reference)
      .def("offset", OffsetWithSize, py::return_value_policy::reference)
      .def("offset", NormalOffset, py::return_value_policy::reference)
      .def("offset_by", OffsetBy)
      .def("offset_by", OffsetByWithSize)
      .def("point_on_line_nearest",&Line2d::PointOnLineNearest)
      .def("distance_to_point",&Line2d::DistanceToPoint)
      .def("rotate",&Line2d::Rotate,py::return_value_policy::reference)
      .def("rotate_by",&Line2d::RotateBy)
      .def("parallel", Parallel1)
      .def("parallel", Parallel2)
      .def("normal",&Line2d::Normal)
      .def("get_side",&Line2d::GetSide)
      .def("reverse",&Line2d::Reverse)
      .def("set_implicit",&Line2d::SetImplicit)
      .def("get_implicit",&Line2d::GetImplicit)
      .def("set_explicit",&Line2d::SetExplicit)
      .def("get_explicit",&Line2d::GetExplicit)
      .def("through_points", &Line2d::ThroughPoints)
      ;

   py::enum_<Line2d::Side>(line2d, "Line2d.Side")
      .value("left", Line2d::Side::Left)
      .value("right", Line2d::Side::Right)
      .export_values()
      ;
}
