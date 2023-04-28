#include "pch.h"
#include "LineSegment2d.h"

#pragma warning (disable : 4267)
#include <boost\python\suite\indexing\vector_indexing_suite.hpp>

using namespace boost::python;
using namespace WBFL::Geometry;

void export_LineSegment2d_types()
{
   LineSegment2d& (LineSegment2d:: * NormalOffset)(Float64) = &LineSegment2d::Offset;
   LineSegment2d (LineSegment2d:: * NormalOffsetBy)(Float64) const = &LineSegment2d::OffsetBy;
   LineSegment2d& (LineSegment2d:: * Offset)(Float64, Float64) = &LineSegment2d::Offset;
   LineSegment2d& (LineSegment2d:: * OffsetWithSize)(const Size2d&) = &LineSegment2d::Offset;
   LineSegment2d (LineSegment2d:: * OffsetBy)(Float64, Float64) const = &LineSegment2d::OffsetBy;
   LineSegment2d (LineSegment2d:: * OffsetByWithSize)(const Size2d&) const = &LineSegment2d::OffsetBy;

   class_<std::vector<Point2d>>("Points")
      .def(vector_indexing_suite<std::vector<Point2d>>())
      ;

   class_<LineSegment2d>("LineSegment2d")
      .def(init<const Point2d&,const Point2d&>())
      .def(init<const Point2d&, const Size2d&>())
      .def(init<Float64,Float64,Float64,Float64>())
      .def("through_points",&LineSegment2d::ThroughPoints)
      .def("contains_point",&LineSegment2d::ContainsPoint)
      .def("length",&LineSegment2d::Length)
      .def("set_start_point",&LineSegment2d::GetStartPoint, return_internal_reference<>())
      .def("get_start_point", &LineSegment2d::SetStartPoint)
      .def("set_end_point",&LineSegment2d::GetEndPoint, return_internal_reference<>())
      .def("get_end_point", &LineSegment2d::SetEndPoint)
      .def("mid_point",&LineSegment2d::GetMidPoint)
      .def("offset",NormalOffset,return_internal_reference<>())
      .def("offset", Offset, return_internal_reference<>())
      .def("offset", OffsetWithSize, return_internal_reference<>())
      .def("offset_by",NormalOffsetBy)
      .def("offset_by", OffsetBy)
      .def("offset_by", OffsetByWithSize)
      .def("rotate",&LineSegment2d::Rotate,return_internal_reference<>())
      .def("rotate_by",&LineSegment2d::RotateBy)
      .def("divide",&LineSegment2d::Divide)
      ;
}
