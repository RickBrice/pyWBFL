#include "pch.h"
#include "Plane3d.h"

using namespace WBFL::Geometry;

namespace py = pybind11;

void export_Plane3d_types(py::module_& m)
{
   void(Plane3d:: * Init)(const Point3d&, const Vector3d&) = &Plane3d::Init;
   void(Plane3d:: * InitWithCoefficients)(Float64, Float64, Float64, Float64) = &Plane3d::Init;
   py::class_<Plane3d>(m, "Plane3d")
      .def("init", Init)
      .def("init", InitWithCoefficients)
      .def("get_constants", &Plane3d::GetConstants)
      .def("through_altitude", &Plane3d::ThroughAltitude)
      .def("through_line", &Plane3d::ThroughLine)
      .def("through_points", &Plane3d::ThroughPoints)
      .def("xy", &Plane3d::XY)
      .def("xz", &Plane3d::XZ)
      .def("yz",&Plane3d::YZ)
      .def("get_x",&Plane3d::GetX)
      .def("get_y", &Plane3d::GetY)
      .def("get_z", &Plane3d::GetZ)
      .def("intersect_with_line_segment",&Plane3d::LineSegmentIntersect)
      .def("shortest_distance",&Plane3d::ShortestDistance)
      .def("nearest_point_on_plane",&Plane3d::PointOnPlaneNearest)
      .def("normal",&Plane3d::NormalVector)
      ;
}