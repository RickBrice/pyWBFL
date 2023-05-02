#include "pch.h"
#include "Convert.h"

using namespace boost::python;
using namespace WBFL::Units;

void export_convert_types()
{
   def("convert", Convert<Mass>);
   def("convert", Convert<Length>);
   def("convert", Convert<Time>);
   def("convert", Convert<Temperature>);
   def("convert", Convert<Angle>);
   def("convert", Convert<Acceleration>);
   def("convert", Convert<MassPerLength>);
   def("convert", Convert<Length2>);
   def("convert", Convert<Length3>);
   def("convert", Convert<Length4>);
   def("convert", Convert<Pressure>);
   def("convert", Convert<UnitWeight>);
   def("convert", Convert<Density>);
   def("convert", Convert<Force>);
   def("convert", Convert<ForcePerLength>);
   def("convert", Convert<Moment>);
   def("convert", Convert<MomentPerAngle>);
   def("convert", Convert<SqrtPressure>);
   def("convert", Convert<PerLength>);
   def("convert", Convert<ForceLength2>);
   def("convert", Convert<Velocity>);
   def("convert", Convert<Area>);
   def("convert", Convert<Volume>);
   def("convert", Convert<Stress>);
   def("convert", Convert<AreaPerLength>);
}
