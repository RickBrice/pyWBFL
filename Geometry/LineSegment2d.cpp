#include "pch.h"
#include "LineSegment2d.h"
#include "pybind11/stl.h"

using namespace WBFL::Geometry;

namespace py = pybind11;

void export_LineSegment2d_types(py::module_& m)
{
   LineSegment2d& (LineSegment2d:: * NormalOffset)(Float64) = &LineSegment2d::Offset;
   LineSegment2d (LineSegment2d:: * NormalOffsetBy)(Float64) const = &LineSegment2d::OffsetBy;
   LineSegment2d& (LineSegment2d:: * Offset)(Float64, Float64) = &LineSegment2d::Offset;
   LineSegment2d& (LineSegment2d:: * OffsetWithSize)(const Size2d&) = &LineSegment2d::Offset;
   LineSegment2d (LineSegment2d:: * OffsetBy)(Float64, Float64) const = &LineSegment2d::OffsetBy;
   LineSegment2d (LineSegment2d:: * OffsetByWithSize)(const Size2d&) const = &LineSegment2d::OffsetBy;

   py::class_<LineSegment2d>(m,"LineSegment2d")
      .def(py::init<const Point2d&,const Point2d&>())
      .def(py::init<const Point2d&, const Size2d&>())
      .def(py::init<Float64,Float64,Float64,Float64>())
      .def("through_points",&LineSegment2d::ThroughPoints)
      .def("contains_point",&LineSegment2d::ContainsPoint)
      .def("length",&LineSegment2d::Length)
      .def("set_start_point",&LineSegment2d::GetStartPoint, py::return_value_policy::reference)
      .def("get_start_point", &LineSegment2d::SetStartPoint)
      .def("set_end_point",&LineSegment2d::GetEndPoint, py::return_value_policy::reference)
      .def("get_end_point", &LineSegment2d::SetEndPoint)
      .def("mid_point",&LineSegment2d::GetMidPoint)
      .def("offset",NormalOffset,py::return_value_policy::reference)
      .def("offset", Offset, py::return_value_policy::reference)
      .def("offset", OffsetWithSize, py::return_value_policy::reference)
      .def("offset_by",NormalOffsetBy)
      .def("offset_by", OffsetBy)
      .def("offset_by", OffsetByWithSize)
      .def("rotate",&LineSegment2d::Rotate,py::return_value_policy::reference)
      .def("rotate_by",&LineSegment2d::RotateBy)
      .def("divide",&LineSegment2d::Divide)
      ;
}
