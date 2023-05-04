#include "pch.h"
#include "Vector3d.h"

using namespace WBFL::Geometry;
namespace py = pybind11;

void export_Vector3d_types(py::module_& m)
{
   Vector3d& (Vector3d:: * SetSize)(Float64, Float64, Float64) = &Vector3d::SetSize;
   Vector3d& (Vector3d:: * SetSizeWithSize)(const Size3d&) = &Vector3d::SetSize;
   Vector3d& (Vector3d:: * Offset)(Float64, Float64, Float64) = &Vector3d::Offset;
   Vector3d& (Vector3d:: * OffsetWithSize)(const Size3d&) = &Vector3d::Offset;
   Vector3d(Vector3d:: * OffsetBy)(Float64, Float64,Float64) const = &Vector3d::OffsetBy;
   Vector3d(Vector3d:: * OffsetByWithSize)(const Size3d&) const = &Vector3d::OffsetBy;
   Float64(Vector3d:: * GetX)() const = &Vector3d::X;
   Float64&(Vector3d:: * SetX)() = &Vector3d::X;
   Float64(Vector3d:: * GetY)() const = &Vector3d::Y;
   Float64&(Vector3d:: * SetY)() = &Vector3d::Y;
   Float64(Vector3d:: * GetZ)() const = &Vector3d::Z;
   Float64& (Vector3d:: * SetZ)() = &Vector3d::Z;

   py::class_<Vector3d> Vector3d(m, "Vector3d");
   Vector3d
      .def(py::init<const Point3d&, const Point3d&>())
      .def(py::init<Float64, Float64,Float64>())
      .def(py::init<const Size3d&>())
      .def("angle_between", &Vector3d::AngleBetween)
      .def("projection", &Vector3d::Projection)
      .def("dot", &Vector3d::Dot)
      .def("cross", &Vector3d::Cross)
      .def("is_zero", &Vector3d::IsZero)
      .def("get_size", &Vector3d::GetSize)
      .def("get_magnitude", &Vector3d::GetMagnitude)
      .def("get_relmagnitude", &Vector3d::GetRelMagnitude)
      .def("reflect", &Vector3d::Reflect, py::return_value_policy::reference)
      .def("normalize", &Vector3d::Normalize, py::return_value_policy::reference)
      .def("normalize_by", &Vector3d::NormalizeBy)
      .def("scale", &Vector3d::Scale, py::return_value_policy::reference)
      .def("scale_by", &Vector3d::ScaleBy)
      .def("increment", &Vector3d::Increment, py::return_value_policy::reference)
      .def("increment_by", &Vector3d::IncrementBy)
      .def("decrement", &Vector3d::Decrement, py::return_value_policy::reference)
      .def("decrement_by", &Vector3d::DecrementBy)
      .def("set_size", SetSize, py::return_value_policy::reference)
      .def("set_size", SetSizeWithSize, py::return_value_policy::reference)
      .def("offset", Offset, py::return_value_policy::reference)
      .def("offset", OffsetWithSize, py::return_value_policy::reference)
      .def("offset_by", OffsetBy)
      .def("offset_by", OffsetByWithSize)
      .def("set_magnitude", &Vector3d::SetMagnitude, py::return_value_policy::reference)
      .def("set_magnitude_by", &Vector3d::SetMagnitudeBy)
      .def_property("x", GetX, SetX)
      .def_property("y", GetY, SetY)
      .def_property("z", GetZ, SetZ)
      ;
}
