#include "pch.h"
#include "Primitives.h"

using namespace boost::python;
using namespace WBFL::Geometry;

void export_primitives_types()
{

   // function points for overloaded methods
   Float64(Size2d:: * Size2d_GetDx)() const = &Size2d::Dx;
   void(Size2d:: * Size2d_SetDx)(Float64) = &Size2d::Dx;
   Float64(Size2d:: * Size2d_GetDy)() const = &Size2d::Dy;
   void(Size2d:: * Size2d_SetDy)(Float64) = &Size2d::Dy;
   void(Size2d:: * Size2d_SetDimensions)(Float64, Float64) = &Size2d::SetDimensions;
   void(Size2d:: * Size2d_SetDimensionsWithPoint)(const Point2d&) = &Size2d::SetDimensions;

   class_<Size2d>("Size2d")
      .def(init<Float64, Float64>())
      .def(init<const Point2d&>())
      .def(init<const Size2d&>())
      .add_property("dx", Size2d_GetDx, Size2d_SetDx)
      .add_property("dy", Size2d_GetDy, Size2d_SetDy)
      .def("magnitude", &Size2d::Magnitude)
      .def("set_dimensions", Size2d_SetDimensions)
      .def("set_dimensions", Size2d_SetDimensionsWithPoint)
      ;

   // function points for overloaded methods
   Float64(Point2d:: * Point2d_GetX)() const = &Point2d::X;
   void (Point2d:: * Point2d_SetX)(Float64) = &Point2d::X;
   Float64(Point2d:: * Point2d_GetY)() const = &Point2d::Y;
   void (Point2d:: * Point2d_SetY)(Float64) = &Point2d::Y;
   void (Point2d:: * Point2d_Move1)(Float64, Float64) = &Point2d::Move;
   void (Point2d:: * Point2d_Move2)(const Point2d&) = &Point2d::Move;
   Float64(Point2d:: * Point2d_Distance1)(Float64, Float64) const = &Point2d::Distance;
   Float64(Point2d:: * Point2d_Distance2)(const Point2d&) const = &Point2d::Distance;
   Point2d& (Point2d:: * Point2d_Offset)(Float64, Float64) = &Point2d::Offset;
   Point2d& (Point2d:: * Point2d_OffsetWithSize)(const Size2d&) = &Point2d::Offset;
   Point2d(Point2d:: * Point2d_OffsetBy)(Float64, Float64) const = &Point2d::OffsetBy;
   Point2d(Point2d:: * Point2d_OffsetByWithSize)(const Size2d&) const = &Point2d::OffsetBy;
   Point2d& (Point2d:: * Point2d_Rotate)(Float64, Float64, Float64) = &Point2d::Rotate;
   Point2d& (Point2d:: * Point2d_RotateWithPoint)(const Point2d&, Float64) = &Point2d::Rotate;
   Point2d(Point2d:: * Point2d_RotateBy)(Float64, Float64, Float64) const = &Point2d::RotateBy;
   Point2d(Point2d:: * Point2d_RotateByWithPoint)(const Point2d&, Float64) const = &Point2d::RotateBy;

   class_<Point2d>("Point2d")
      .def(init<Float64, Float64>())
      .def(init<const Point2d&>())
      .add_property("x", Point2d_GetX, Point2d_SetX)
      .add_property("y", Point2d_GetY, Point2d_SetY)
      .def("magnitude", &Point2d::Magnitude)
      .def("scale", &Point2d::Scale)
      .def("move", Point2d_Move1)
      .def("move", Point2d_Move2)
      .def("distance", Point2d_Distance1)
      .def("distance", Point2d_Distance2)
      .def("offset", Point2d_Offset, return_internal_reference<>())
      .def("offset", Point2d_OffsetWithSize, return_internal_reference<>())
      .def("offset_by", Point2d_OffsetBy)
      .def("offset_by", Point2d_OffsetByWithSize)
      .def("rotate", Point2d_Rotate, return_internal_reference<>())
      .def("rotate", Point2d_RotateWithPoint, return_internal_reference<>())
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
   void (Rect2d:: * Rect2d_SetLeft)(Float64) = &Rect2d::Left;
   Float64(Rect2d:: * Rect2d_GetRight)() const = &Rect2d::Right;
   void (Rect2d:: * Rect2d_SetRight)(Float64) = &Rect2d::Right;
   Float64(Rect2d:: * Rect2d_GetTop)() const = &Rect2d::Top;
   void (Rect2d:: * Rect2d_SetTop)(Float64) = &Rect2d::Top;
   Float64(Rect2d:: * Rect2d_GetBottom)() const = &Rect2d::Bottom;
   void (Rect2d:: * Rect2d_SetBottom)(Float64) = &Rect2d::Bottom;
   bool(Rect2d:: * Rect2d_ContainsPoint)(const Point2d&) const = &Rect2d::Contains;
   bool(Rect2d:: * Rect2d_ContainsRect)(const Rect2d&) const = &Rect2d::Contains;

   enum_<Rect2d::RelPosition>("RelPosition")
      .value("contains", Rect2d::RelPosition::Contains)
      .value("outside", Rect2d::RelPosition::Outside)
      .value("touches", Rect2d::RelPosition::Touches)
      ;

   class_<Rect2d>("Rect2d")
      .def(init<Float64, Float64, Float64, Float64>())
      .def(init<const Point2d&, const Point2d&>())
      .def(init<const Point2d&, const Size2d&>())
      .def(init<const Rect2d&>())
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
      .def("inflate", Rect2d_Inflate, return_internal_reference<>())
      .def("inflate", Rect2d_InflateWithSize, return_internal_reference<>())
      .def("inflate_by", Rect2d_InflateBy)
      .def("inflate_by", Rect2d_InflateByWithSize)
      .def("move_to", &Rect2d::MoveTo, return_internal_reference<>())
      .def("moved_to", &Rect2d::MovedTo)
      .def("normalize", &Rect2d::Normalize, return_internal_reference<>())
      .def("normalized", &Rect2d::Normalized)
      .def("offset", Rect2d_Offset, return_internal_reference<>())
      .def("offset", Rect2d_OffsetWithSize, return_internal_reference<>())
      .def("offset_by", Rect2d_OffsetBy)
      .def("offset_by", Rect2d_OffsetByWithSize)
      .def("union", &Rect2d::Union, return_internal_reference<>())
      .def("union_by", &Rect2d::UnionBy)
      .def("intersection", &Rect2d::Intersection, return_internal_reference<>())
      .def("intersection_by", &Rect2d::IntersectionBy)
      .def("bound_point", Rect2d_BoundPoint, return_internal_reference<>())
      .def("bound_point", Rect2d_BoundPointWithPoint, return_internal_reference<>())
      .def("bound_point_by", Rect2d_BoundPointBy)
      .def("bound_point_by", Rect2d_BoundPointByWithPoint)
      .add_property("left", Rect2d_GetLeft, Rect2d_SetLeft)
      .add_property("right", Rect2d_GetRight, Rect2d_SetRight)
      .add_property("top", Rect2d_GetTop, Rect2d_SetTop)
      .add_property("bottom", Rect2d_GetBottom, Rect2d_SetBottom)
      .def("is_normalized", &Rect2d::IsNormalized)
      .def("is_null", &Rect2d::IsNull)
      .def("contains", Rect2d_ContainsPoint)
      .def("contains", Rect2d_ContainsRect)
      .def("touches", &Rect2d::Touches)
      .def("get_position", &Rect2d::GetPosition)
      ;
}
