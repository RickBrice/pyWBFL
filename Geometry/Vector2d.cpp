#include "pch.h"
#include "Vector2d.h"

using namespace boost::python;
using namespace WBFL::Geometry;

void export_Vector2d_types()
{
   Vector2d& (Vector2d:: * SetSize)(Float64, Float64) = &Vector2d::SetSize;
   Vector2d& (Vector2d:: * SetSizeWithSize)(const Size2d&) = &Vector2d::SetSize;
   Vector2d& (Vector2d:: * Offset)(Float64, Float64) = &Vector2d::Offset;
   Vector2d& (Vector2d:: * OffsetWithSize)(const Size2d&) = &Vector2d::Offset;
   Vector2d (Vector2d:: * OffsetBy)(Float64, Float64) const = &Vector2d::OffsetBy;
   Vector2d (Vector2d:: * OffsetByWithSize)(const Size2d&) const = &Vector2d::OffsetBy;
   Float64(Vector2d:: * GetX)() const = &Vector2d::X;
   void(Vector2d:: * SetX)(Float64) = &Vector2d::X;
   Float64(Vector2d:: * GetY)() const = &Vector2d::Y;
   void(Vector2d:: * SetY)(Float64) = &Vector2d::Y;

   enum_<Vector2d::Side>("Side")
      .value("left", Vector2d::Side::Left)
      .value("right", Vector2d::Side::Right)
      ;

   class_<Vector2d>("Vector2d")
      .def(init<const Point2d&, const Point2d&>())
      .def(init<Float64, Float64>())
      .def(init<const Size2d&>())
      .def("angle_between", &Vector2d::AngleBetween)
      .def("projection", &Vector2d::Projection)
      .def("dot", &Vector2d::Dot)
      .def("is_zero", &Vector2d::IsZero)
      .def("get_direction", &Vector2d::GetDirection)
      .def("get_size", &Vector2d::GetSize)
      .def("get_magnitude",&Vector2d::GetMagnitude)
      .def("get_relmagnitude",&Vector2d::GetRelMagnitude)
      .def("reflect",&Vector2d::Reflect,return_internal_reference<>())
      .def("normalize",&Vector2d::Normalize,return_internal_reference<>())
      .def("normalize_by",&Vector2d::NormalizeBy)
      .def("normal",&Vector2d::Normal) // update this for left/right and default value
      .def("scale",&Vector2d::Scale,return_internal_reference<>())
      .def("scale_by",&Vector2d::ScaleBy)
      .def("increment",&Vector2d::Increment,return_internal_reference<>())
      .def("increment_by",&Vector2d::IncrementBy)
      .def("decrement",&Vector2d::Decrement,return_internal_reference<>())
      .def("decrement_by",&Vector2d::DecrementBy)
      .def("set_direction",&Vector2d::SetDirection,return_internal_reference<>())
      .def("set_direction_by",&Vector2d::SetDirectionBy)
      .def("set_size", SetSize, return_internal_reference<>())
      .def("set_size", SetSizeWithSize, return_internal_reference<>())
      .def("offset", Offset, return_internal_reference<>())
      .def("offset", OffsetWithSize, return_internal_reference<>())
      .def("offset_by", OffsetBy)
      .def("offset_by", OffsetByWithSize)
      .def("set_magnitude",&Vector2d::SetMagnitude,return_internal_reference<>())
      .def("set_magnitude_by", &Vector2d::SetMagnitudeBy)
      .def("set_rotate", &Vector2d::Rotate, return_internal_reference<>())
      .def("set_rotate_by", &Vector2d::RotateBy)
      .add_property("x",GetX,SetX)
      .add_property("y",GetY,SetY)
      ;
}
