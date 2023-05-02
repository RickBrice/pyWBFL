#include "pch.h"


BOOST_PYTHON_MODULE(Beams)
{
   using namespace boost::python;
   using namespace WBFL::Beams;

   struct RoarkBeamWrap : RoarkBeam, wrapper<RoarkBeam>
   {
      //std::unique_ptr<RoarkBeam> CreateClone() const override { return this->get_override("clone")(); }
      std::pair<Float64, Float64> GetReactions() const override { return this->get_override("reactions")(); }
      std::pair<Float64, Float64> GetMoments() const override { return this->get_override("moments")(); }
      std::pair<Float64, Float64> GetRotations() const override { return this->get_override("rotations")(); }
      std::pair<Float64, Float64> GetDeflections() const override { return this->get_override("deflections")(); }
      WBFL::System::SectionValue ComputeShear(Float64 x) const override { return this->get_override("shear")(x); }
      WBFL::System::SectionValue ComputeMoment(Float64 x) const override { return this->get_override("moment")(x); }
      //Float64 ComputeRotation(Float64 x) const override { return call<Float64>(this->get_override("rotation").ptr(),x); }
      Float64 ComputeRotation(Float64 x) const override { return this->get_override("rotation")(x); }
      Float64 ComputeDeflection(Float64 x) const override { return this->get_override("deflection")(x); }
   };

   class_<RoarkBeamWrap, boost::noncopyable>("Beam",no_init)
      .add_property("L",&RoarkBeam::GetL,&RoarkBeam::SetL)
      .add_property("EI", &RoarkBeam::GetEI, &RoarkBeam::SetEI)
      //.def("clone",pure_virtual(&RoarkBeam::CreateClone))
      .def("reactions",pure_virtual(&RoarkBeam::GetReactions))
      .def("moments", pure_virtual(&RoarkBeam::GetMoments))
      .def("rotations", pure_virtual(&RoarkBeam::GetRotations))
      .def("deflections", pure_virtual(&RoarkBeam::GetDeflections))
      .def("shear",pure_virtual(&RoarkBeam::ComputeShear))
      .def("moment", pure_virtual(&RoarkBeam::ComputeMoment))
      .def("rotation", pure_virtual(&RoarkBeam::ComputeRotation))
      .def("deflection",pure_virtual(&RoarkBeam::ComputeDeflection))
      ;

   class_<PPPartialUniformLoad, bases<RoarkBeamWrap>, boost::noncopyable>("PPPartialUniformLoad", no_init)
      .def(init<Float64,Float64,Float64,Float64,Float64>())
      .add_property("La", &PPPartialUniformLoad::GetLa, &PPPartialUniformLoad::SetLa)
      .add_property("Lb", &PPPartialUniformLoad::GetLb, &PPPartialUniformLoad::SetLb)
      .add_property("w", &PPPartialUniformLoad::GetW, &PPPartialUniformLoad::SetW)
      ;
}
