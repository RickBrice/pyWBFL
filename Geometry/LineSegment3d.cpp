#include "pch.h"
#include "LineSegment3d.h"

using namespace WBFL::Geometry;

namespace py = pybind11;

void export_LineSegment3d_types(py::module_& m)
{
   LineSegment3d& (LineSegment3d:: * Offset)(Float64, Float64,Float64) = &LineSegment3d::Offset;
   LineSegment3d& (LineSegment3d:: * OffsetWithSize)(const Size3d&) = &LineSegment3d::Offset;
   LineSegment3d(LineSegment3d:: * OffsetBy)(Float64, Float64,Float64) const = &LineSegment3d::OffsetBy;
   LineSegment3d(LineSegment3d:: * OffsetByWithSize)(const Size3d&) const = &LineSegment3d::OffsetBy;

   py::class_<LineSegment3d>(m, "LineSegment3d")
      .def(py::init<const Point3d&, const Point3d&>())
      .def(py::init<const Point3d&, const Size3d&>())
      .def(py::init<Float64, Float64, Float64, Float64, Float64, Float64>())
      .def("through_points", &LineSegment3d::ThroughPoints)
      .def("length", &LineSegment3d::Length)
      .def("set_start_point", &LineSegment3d::GetStartPoint, py::return_value_policy::reference)
      .def("get_start_point", &LineSegment3d::SetStartPoint)
      .def("set_end_point", &LineSegment3d::GetEndPoint, py::return_value_policy::reference)
      .def("get_end_point", &LineSegment3d::SetEndPoint)
      .def("mid_point", &LineSegment3d::GetMidPoint)
      .def("offset", Offset, py::return_value_policy::reference)
      .def("offset", OffsetWithSize, py::return_value_policy::reference)
      .def("offset_by", OffsetBy)
      .def("offset_by", OffsetByWithSize)
      .def("divide", &LineSegment3d::Divide)
      .def("distance_to_point",&LineSegment3d::DistanceToPoint)
      ;
}
