#include "pch.h"
#include "Physical.h"

using namespace WBFL::Units;
namespace py = pybind11;

void export_physical_types(py::module_& m)
{
   py::class_<Mass>(m, "Mass");
   py::class_<Length>(m, "Length");
   py::class_<Time>(m, "Time");
   py::class_<Temperature>(m, "Temperature");
   py::class_<Angle>(m, "Angle");
   py::class_<Acceleration>(m, "Acceleration");
   py::class_<MassPerLength>(m, "MassPerLength");
   py::class_<Length2>(m, "Length2");
   py::class_<Length3>(m, "Length3");
   py::class_<Length4>(m, "Length4");
   py::class_<Pressure>(m, "Pressure");
   py::class_<UnitWeight>(m, "UnitWeight");
   py::class_<Density>(m, "Density");
   py::class_<Force>(m, "Force");
   py::class_<ForcePerLength>(m, "ForcePerLength");
   py::class_<Moment>(m, "Moment");
   py::class_<MomentPerAngle>(m, "MomentPerAngle");
   py::class_<SqrtPressure>(m, "SqrtPressure");
   py::class_<PerLength>(m, "PerLength");
   py::class_<ForceLength2>(m, "ForceLength2");
   py::class_<Velocity>(m, "Velocity");
   //py::class_<Area>(m, "Area");
   //py::class_<Volume>(m, "Volume");
   //py::class_<AreaPerLength>(m, "AreaPerLength");
}