#include "pch.h"
#include "Primitives.h"

namespace py = pybind11;
using namespace WBFL::Geometry;

void export_Primitives_types(py::module_& m)
{

   // function points for overloaded methods
   Float64(Size2d:: * Size2d_GetDx)() const = &Size2d::Dx;
   Float64&(Size2d:: * Size2d_SetDx)() = &Size2d::Dx;
   Float64(Size2d:: * Size2d_GetDy)() const = &Size2d::Dy;
   Float64&(Size2d:: * Size2d_SetDy)() = &Size2d::Dy;
   void(Size2d:: * Size2d_SetDimensions)(Float64, Float64) = &Size2d::SetDimensions;
   void(Size2d:: * Size2d_SetDimensionsWithPoint)(const Point2d&) = &Size2d::SetDimensions;

   py::class_<Size2d>(m,"Size2d")
      .def(py::init<Float64, Float64>())
      .def(py::init<const Point2d&>())
      .def(py::init<const Size2d&>())
      .def_property("dx", Size2d_GetDx, Size2d_SetDx)
      .def_property("dy", Size2d_GetDy, Size2d_SetDy)
      .def("magnitude", &Size2d::Magnitude)
      .def("set_dimensions", Size2d_SetDimensions)
      .def("set_dimensions", Size2d_SetDimensionsWithPoint)
      .def("get_dimensions",&Size2d::GetDimensions)
      ;

   // function points for overloaded methods
   Float64(Point2d:: * Point2d_GetX)() const = &Point2d::X;
   Float64&(Point2d:: * Point2d_SetX)() = &Point2d::X;
   Float64(Point2d:: * Point2d_GetY)() const = &Point2d::Y;
   Float64&(Point2d:: * Point2d_SetY)() = &Point2d::Y;
   void (Point2d:: * Point2d_Move)(Float64, Float64) = &Point2d::Move;
   void (Point2d:: * Point2d_MoveWithPoint)(const Point2d&) = &Point2d::Move;
   Float64(Point2d:: * Point2d_Distance)(Float64, Float64) const = &Point2d::Distance;
   Float64(Point2d:: * Point2d_DistanceWithPoint)(const Point2d&) const = &Point2d::Distance;
   Point2d& (Point2d:: * Point2d_Offset)(Float64, Float64) = &Point2d::Offset;
   Point2d& (Point2d:: * Point2d_OffsetWithSize)(const Size2d&) = &Point2d::Offset;
   Point2d(Point2d:: * Point2d_OffsetBy)(Float64, Float64) const = &Point2d::OffsetBy;
   Point2d(Point2d:: * Point2d_OffsetByWithSize)(const Size2d&) const = &Point2d::OffsetBy;
   Point2d& (Point2d:: * Point2d_Rotate)(Float64, Float64, Float64) = &Point2d::Rotate;
   Point2d& (Point2d:: * Point2d_RotateWithPoint)(const Point2d&, Float64) = &Point2d::Rotate;
   Point2d(Point2d:: * Point2d_RotateBy)(Float64, Float64, Float64) const = &Point2d::RotateBy;
   Point2d(Point2d:: * Point2d_RotateByWithPoint)(const Point2d&, Float64) const = &Point2d::RotateBy;

   py::class_<Point2d>(m,"Point2d")
      .def( py::init<Float64, Float64>())
      .def( py::init<const Point2d&>())
      .def_property("x", Point2d_GetX, Point2d_SetX)
      .def_property("y", Point2d_GetY, Point2d_SetY)
      .def("magnitude", &Point2d::Magnitude)
      .def("scale", &Point2d::Scale)
      .def("move", Point2d_Move)
      .def("move", Point2d_MoveWithPoint)
      .def("distance", Point2d_Distance)
      .def("distance", Point2d_DistanceWithPoint)
      .def("offset", Point2d_Offset, py::return_value_policy::reference)
      .def("offset", Point2d_OffsetWithSize, py::return_value_policy::reference)
      .def("offset_by", Point2d_OffsetBy)
      .def("offset_by", Point2d_OffsetByWithSize)
      .def("rotate", Point2d_Rotate, py::return_value_policy::reference)
      .def("rotate", Point2d_RotateWithPoint, py::return_value_policy::reference)
      .def("rotate_by", Point2d_RotateBy)
      .def("rotate_by", Point2d_RotateByWithPoint)
      ;


   void(Rect2d:: * Rect2d_Set)(Float64, Float64, Float64, Float64) = &Rect2d::Set;
   void(Rect2d:: * Rect2d_SetWithPoints)(const Point2d&, const Point2d&) = &Rect2d::Set;
   void(Rect2d:: * Rect2d_SetWH1)(Float64, Float64, Float64, Float64) = &Rect2d::SetWH;
   void(Rect2d:: * Rect2d_SetWH2)(const Point2d&, const Size2d&) = &Rect2d::SetWH;
   Rect2d& (Rect2d:: * Rect2d_Inflate)(Float64, Float64) = &Rect2d::Inflate;
   Rect2d& (Rect2d:: * Rect2d_InflateWithSize)(const Size2d&) = &Rect2d::Inflate;
   Rect2d(Rect2d:: * Rect2d_InflateBy)(Float64, Float64) const = &Rect2d::InflateBy;
   Rect2d(Rect2d:: * Rect2d_InflateByWithSize)(const Size2d&) const = &Rect2d::InflateBy;
   Rect2d& (Rect2d:: * Rect2d_Offset)(Float64, Float64) = &Rect2d::Offset;
   Rect2d& (Rect2d:: * Rect2d_OffsetWithSize)(const Size2d&) = &Rect2d::Offset;
   Rect2d(Rect2d:: * Rect2d_OffsetBy)(Float64, Float64) const = &Rect2d::OffsetBy;
   Rect2d(Rect2d:: * Rect2d_OffsetByWithSize)(const Size2d&) const = &Rect2d::OffsetBy;
   Rect2d& (Rect2d:: * Rect2d_BoundPoint)(Float64, Float64) = &Rect2d::BoundPoint;
   Rect2d& (Rect2d:: * Rect2d_BoundPointWithPoint)(const Point2d&) = &Rect2d::BoundPoint;
   Rect2d(Rect2d:: * Rect2d_BoundPointBy)(Float64, Float64) const = &Rect2d::BoundPointBy;
   Rect2d(Rect2d:: * Rect2d_BoundPointByWithPoint)(const Point2d&) const = &Rect2d::BoundPointBy;
   Float64(Rect2d:: * Rect2d_GetLeft)() const = &Rect2d::Left;
   Float64&(Rect2d:: * Rect2d_SetLeft)() = &Rect2d::Left;
   Float64(Rect2d:: * Rect2d_GetRight)() const = &Rect2d::Right;
   Float64&(Rect2d:: * Rect2d_SetRight)() = &Rect2d::Right;
   Float64(Rect2d:: * Rect2d_GetTop)() const = &Rect2d::Top;
   Float64&(Rect2d:: * Rect2d_SetTop)() = &Rect2d::Top;
   Float64(Rect2d:: * Rect2d_GetBottom)() const = &Rect2d::Bottom;
   Float64&(Rect2d:: * Rect2d_SetBottom)() = &Rect2d::Bottom;
   bool(Rect2d:: * Rect2d_ContainsPoint)(const Point2d&) const = &Rect2d::Contains;
   bool(Rect2d:: * Rect2d_ContainsRect)(const Rect2d&) const = &Rect2d::Contains;

   py::class_<Rect2d> rect2d(m, "Rect2d");
   rect2d
      .def(py::init<Float64, Float64, Float64, Float64>())
      .def(py::init<const Point2d&, const Point2d&>())
      .def(py::init<const Point2d&, const Size2d&>())
      .def(py::init<const Rect2d&>())
      .def("area", &Rect2d::Area)
      .def("set", Rect2d_Set)
      .def("set", Rect2d_SetWithPoints)
      .def("set_empty", &Rect2d::SetEmpty)
      .def("set_null", &Rect2d::SetNull)
      .def("set_wh", Rect2d_SetWH1)
      .def("set_wh", Rect2d_SetWH2)
      .def("top_left", &Rect2d::TopLeft)
      .def("top_right", &Rect2d::TopRight)
      .def("bottom_left", &Rect2d::BottomLeft)
      .def("bottom_right", &Rect2d::BottomRight)
      .def("center", &Rect2d::Center)
      .def("top_center", &Rect2d::TopCenter)
      .def("bottom_center", &Rect2d::BottomCenter)
      .def("left_center", &Rect2d::LeftCenter)
      .def("right_center", &Rect2d::RightCenter)
      .def("size", &Rect2d::Size)
      .def("height", &Rect2d::Height)
      .def("width", &Rect2d::Width)
      .def("inflate", Rect2d_Inflate, py::return_value_policy::reference)
      .def("inflate", Rect2d_InflateWithSize, py::return_value_policy::reference)
      .def("inflate_by", Rect2d_InflateBy)
      .def("inflate_by", Rect2d_InflateByWithSize)
      .def("move_to", &Rect2d::MoveTo, py::return_value_policy::reference)
      .def("moved_to", &Rect2d::MovedTo)
      .def("normalize", &Rect2d::Normalize, py::return_value_policy::reference)
      .def("normalized", &Rect2d::Normalized)
      .def("offset", Rect2d_Offset, py::return_value_policy::reference)
      .def("offset", Rect2d_OffsetWithSize, py::return_value_policy::reference)
      .def("offset_by", Rect2d_OffsetBy)
      .def("offset_by", Rect2d_OffsetByWithSize)
      .def("union", &Rect2d::Union, py::return_value_policy::reference)
      .def("union_by", &Rect2d::UnionBy)
      .def("intersection", &Rect2d::Intersection, py::return_value_policy::reference)
      .def("intersection_by", &Rect2d::IntersectionBy)
      .def("bound_point", Rect2d_BoundPoint, py::return_value_policy::reference)
      .def("bound_point", Rect2d_BoundPointWithPoint, py::return_value_policy::reference)
      .def("bound_point_by", Rect2d_BoundPointBy)
      .def("bound_point_by", Rect2d_BoundPointByWithPoint)
      .def_property("left", Rect2d_GetLeft, Rect2d_SetLeft)
      .def_property("right", Rect2d_GetRight, Rect2d_SetRight)
      .def_property("top", Rect2d_GetTop, Rect2d_SetTop)
      .def_property("bottom", Rect2d_GetBottom, Rect2d_SetBottom)
      .def("is_normalized", &Rect2d::IsNormalized)
      .def("is_null", &Rect2d::IsNull)
      .def("contains", Rect2d_ContainsPoint)
      .def("contains", Rect2d_ContainsRect)
      .def("touches", &Rect2d::Touches)
      .def("get_position", &Rect2d::GetPosition)
      ;

   py::enum_<Rect2d::RelPosition>(rect2d,"Rect2d.RelPosition")
      .value("contains", Rect2d::RelPosition::Contains)
      .value("outside", Rect2d::RelPosition::Outside)
      .value("touches", Rect2d::RelPosition::Touches)
      .export_values()
      ;
}
