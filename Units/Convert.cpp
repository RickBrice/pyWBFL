#include "pch.h"
#include "Convert.h"

using namespace WBFL::Units;
namespace py = pybind11;

void export_convert_types(py::module_& m)
{
   m.def("convert", Convert<Mass>);
   m.def("convert", Convert<Length>);
   m.def("convert", Convert<Time>);
   m.def("convert", Convert<Temperature>);
   m.def("convert", Convert<Angle>);
   m.def("convert", Convert<Acceleration>);
   m.def("convert", Convert<MassPerLength>);
   m.def("convert", Convert<Length2>);
   m.def("convert", Convert<Length3>);
   m.def("convert", Convert<Length4>);
   m.def("convert", Convert<Pressure>);
   m.def("convert", Convert<UnitWeight>);
   m.def("convert", Convert<Density>);
   m.def("convert", Convert<Force>);
   m.def("convert", Convert<ForcePerLength>);
   m.def("convert", Convert<Moment>);
   m.def("convert", Convert<MomentPerAngle>);
   m.def("convert", Convert<SqrtPressure>);
   m.def("convert", Convert<PerLength>);
   m.def("convert", Convert<ForceLength2>);
   m.def("convert", Convert<Velocity>);
   m.def("convert", Convert<Area>);
   m.def("convert", Convert<Volume>);
   m.def("convert", Convert<Stress>);
   m.def("convert", Convert<AreaPerLength>);
}
