#include "pch.h"
#include "Physical.h"

using namespace boost::python;
using namespace WBFL::Units;

void export_physical_types()
{
   class_<Mass, boost::noncopyable>("Mass", no_init);
   class_<Length, boost::noncopyable>("Length", no_init);
   class_<Time, boost::noncopyable>("Time", no_init);
   class_<Temperature, boost::noncopyable>("Temperature", no_init);
   class_<Angle, boost::noncopyable>("Angle",no_init);
   class_<Acceleration, boost::noncopyable>("Acceleration",no_init);
   class_<MassPerLength, boost::noncopyable>("MassPerLength",no_init);
   class_<Length2, boost::noncopyable>("Length2",no_init);
   class_<Length3, boost::noncopyable>("Length3",no_init);
   class_<Length4, boost::noncopyable>("Length4",no_init);
   class_<Pressure, boost::noncopyable>("Pressure",no_init);
   class_<UnitWeight, boost::noncopyable>("UnitWeight",no_init);
   class_<Density, boost::noncopyable>("Density",no_init);
   class_<Force, boost::noncopyable>("Force",no_init);
   class_<ForcePerLength, boost::noncopyable>("ForcePerLength",no_init);
   class_<Moment, boost::noncopyable>("Moment",no_init);
   class_<MomentPerAngle, boost::noncopyable>("MomentPerAngle",no_init);
   class_<SqrtPressure, boost::noncopyable>("SqrtPressure",no_init);
   class_<PerLength, boost::noncopyable>("PerLength",no_init);
   class_<ForceLength2, boost::noncopyable>("ForceLength2",no_init);
   class_<Velocity, boost::noncopyable>("Velocity", no_init);
   class_<Area, boost::noncopyable>("Area", no_init);
   class_<Volume, boost::noncopyable>("Volume", no_init);
   class_<AreaPerLength, boost::noncopyable>("AreaPerLength", no_init);
}