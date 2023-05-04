#include "pch.h"
#include "Primitives3d.h"

namespace py = pybind11;
using namespace WBFL::Geometry;

void export_Primitives3d_types(py::module_& m)
{

   // function points for overloaded methods
   Float64(Size3d:: * Size3d_GetDx)() const = &Size3d::Dx;
   Float64& (Size3d:: * Size3d_SetDx)() = &Size3d::Dx;
   Float64(Size3d:: * Size3d_GetDy)() const = &Size3d::Dy;
   Float64& (Size3d:: * Size3d_SetDy)() = &Size3d::Dy;
   Float64(Size3d:: * Size3d_GetDz)() const = &Size3d::Dz;
   Float64& (Size3d:: * Size3d_SetDz)() = &Size3d::Dz;
   void(Size3d:: * Size3d_SetDimensions)(Float64, Float64,Float64) = &Size3d::SetDimensions;
   void(Size3d:: * Size3d_SetDimensionsWithPoint)(const Point3d&) = &Size3d::SetDimensions;

   py::class_<Size3d>(m, "Size3d")
      .def(py::init<Float64, Float64,Float64>())
      .def(py::init<const Point3d&>())
      .def(py::init<const Size3d&>())
      .def_property("dx", Size3d_GetDx, Size3d_SetDx)
      .def_property("dy", Size3d_GetDy, Size3d_SetDy)
      .def_property("dz", Size3d_GetDz, Size3d_SetDz)
      .def("magnitude", &Size3d::Magnitude)
      .def("set_dimensions", Size3d_SetDimensions)
      .def("set_dimensions", Size3d_SetDimensionsWithPoint)
      .def("get_dimensions", &Size3d::GetDimensions)
      ;

   // function points for overloaded methods
   Float64(Point3d:: * Point3d_GetX)() const = &Point3d::X;
   Float64& (Point3d:: * Point3d_SetX)() = &Point3d::X;
   Float64(Point3d:: * Point3d_GetY)() const = &Point3d::Y;
   Float64& (Point3d:: * Point3d_SetY)() = &Point3d::Y;
   Float64(Point3d:: * Point3d_GetZ)() const = &Point3d::Z;
   Float64& (Point3d:: * Point3d_SetZ)() = &Point3d::Z;
   void (Point3d:: * Point3d_Move)(Float64, Float64,Float64) = &Point3d::Move;
   void (Point3d:: * Point3d_MoveWithPoint)(const Point3d&) = &Point3d::Move;
   Float64(Point3d:: * Point3d_Distance)(Float64, Float64,Float64) const = &Point3d::Distance;
   Float64(Point3d:: * Point3d_DistanceWithPoint)(const Point3d&) const = &Point3d::Distance;
   Point3d& (Point3d:: * Point3d_Offset)(Float64, Float64,Float64) = &Point3d::Offset;
   Point3d& (Point3d:: * Point3d_OffsetWithSize)(const Size3d&) = &Point3d::Offset;
   Point3d(Point3d:: * Point3d_OffsetBy)(Float64, Float64, Float64) const = &Point3d::OffsetBy;
   Point3d(Point3d:: * Point3d_OffsetByWithSize)(const Size3d&) const = &Point3d::OffsetBy;

   py::class_<Point3d>(m, "Point3d")
      .def(py::init<Float64, Float64,Float64>())
      .def(py::init<const Point3d&>())
      .def_property("x", Point3d_GetX, Point3d_SetX)
      .def_property("y", Point3d_GetY, Point3d_SetY)
      .def_property("z", Point3d_GetZ, Point3d_SetZ)
      .def("magnitude", &Point3d::Magnitude)
      .def("scale", &Point3d::Scale)
      .def("move", Point3d_Move)
      .def("move", Point3d_MoveWithPoint)
      .def("distance", Point3d_Distance)
      .def("distance", Point3d_DistanceWithPoint)
      .def("offset", Point3d_Offset, py::return_value_policy::reference)
      .def("offset", Point3d_OffsetWithSize, py::return_value_policy::reference)
      .def("offset_by", Point3d_OffsetBy)
      .def("offset_by", Point3d_OffsetByWithSize)
      ;
}
