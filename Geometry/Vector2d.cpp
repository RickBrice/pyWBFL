#include "pch.h"
#include "Vector2d.h"

using namespace WBFL::Geometry;
namespace py = pybind11;

void export_Vector2d_types(py::module_& m)
{
   Vector2d& (Vector2d:: * SetSize)(Float64, Float64) = &Vector2d::SetSize;
   Vector2d& (Vector2d:: * SetSizeWithSize)(const Size2d&) = &Vector2d::SetSize;
   Vector2d& (Vector2d:: * Offset)(Float64, Float64) = &Vector2d::Offset;
   Vector2d& (Vector2d:: * OffsetWithSize)(const Size2d&) = &Vector2d::Offset;
   Vector2d (Vector2d:: * OffsetBy)(Float64, Float64) const = &Vector2d::OffsetBy;
   Vector2d (Vector2d:: * OffsetByWithSize)(const Size2d&) const = &Vector2d::OffsetBy;
   Float64(Vector2d:: * GetX)() const = &Vector2d::X;
   Float64&(Vector2d:: * SetX)() = &Vector2d::X;
   Float64(Vector2d:: * GetY)() const = &Vector2d::Y;
   Float64&(Vector2d:: * SetY)() = &Vector2d::Y;

   py::class_<Vector2d> vector2d(m, "Vector2d");
   vector2d
      .def(py::init<const Point2d&, const Point2d&>())
      .def(py::init<Float64, Float64>())
      .def(py::init<const Size2d&>())
      .def("angle_between", &Vector2d::AngleBetween)
      .def("projection", &Vector2d::Projection)
      .def("dot", &Vector2d::Dot)
      .def("is_zero", &Vector2d::IsZero)
      .def("get_direction", &Vector2d::GetDirection)
      .def("get_size", &Vector2d::GetSize)
      .def("get_magnitude",&Vector2d::GetMagnitude)
      .def("get_relmagnitude",&Vector2d::GetRelMagnitude)
      .def("reflect",&Vector2d::Reflect,py::return_value_policy::reference)
      .def("normalize",&Vector2d::Normalize,py::return_value_policy::reference)
      .def("normalize_by",&Vector2d::NormalizeBy)
      .def("normal",&Vector2d::Normal) // update this for left/right and default value
      .def("scale",&Vector2d::Scale,py::return_value_policy::reference)
      .def("scale_by",&Vector2d::ScaleBy)
      .def("increment",&Vector2d::Increment,py::return_value_policy::reference)
      .def("increment_by",&Vector2d::IncrementBy)
      .def("decrement",&Vector2d::Decrement,py::return_value_policy::reference)
      .def("decrement_by",&Vector2d::DecrementBy)
      .def("set_direction",&Vector2d::SetDirection,py::return_value_policy::reference)
      .def("set_direction_by",&Vector2d::SetDirectionBy)
      .def("set_size", SetSize, py::return_value_policy::reference)
      .def("set_size", SetSizeWithSize, py::return_value_policy::reference)
      .def("offset", Offset, py::return_value_policy::reference)
      .def("offset", OffsetWithSize, py::return_value_policy::reference)
      .def("offset_by", OffsetBy)
      .def("offset_by", OffsetByWithSize)
      .def("set_magnitude",&Vector2d::SetMagnitude,py::return_value_policy::reference)
      .def("set_magnitude_by", &Vector2d::SetMagnitudeBy)
      .def("rotate", &Vector2d::Rotate, py::return_value_policy::reference)
      .def("rotate_by", &Vector2d::RotateBy)
      .def_property("x",GetX,SetX)
      .def_property("y",GetY,SetY)
      ;


   py::enum_<Vector2d::Side>(vector2d,"Vector2d.Side")
      .value("left", Vector2d::Side::Left)
      .value("right", Vector2d::Side::Right)
      .export_values()
      ;
}
