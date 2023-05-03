#include "pch.h"

using namespace WBFL::Beams;
namespace py = pybind11;

PYBIND11_MODULE(Beams,m)
{
   class PyRoarkBeam : public RoarkBeam
   {
      using RoarkBeam::RoarkBeam; // Inherit constructors

      using Result = std::pair<Float64, Float64>;
      std::unique_ptr<RoarkBeam> CreateClone() const override { PYBIND11_OVERRIDE_PURE(std::unique_ptr<RoarkBeam>, RoarkBeam, CreateClone, /*no parameters*/); }
      std::pair<Float64, Float64> GetReactions() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeam, GetReactions, /*no parameters*/); }
      std::pair<Float64, Float64> GetMoments() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeam, GetMoments, /*no parameters*/); }
      std::pair<Float64, Float64> GetRotations() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeam, GetRotations, /*no parameters*/); }
      std::pair<Float64, Float64> GetDeflections() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeam, GetDeflections, /*no parameters*/); }
      WBFL::System::SectionValue ComputeShear(Float64 x) const override { PYBIND11_OVERRIDE_PURE(WBFL::System::SectionValue, RoarkBeam, ComputeShear, x); }
      WBFL::System::SectionValue ComputeMoment(Float64 x) const override { PYBIND11_OVERRIDE_PURE(WBFL::System::SectionValue, RoarkBeam, ComputeMoment, x); }
      Float64 ComputeRotation(Float64 x) const override { PYBIND11_OVERRIDE_PURE(Float64, RoarkBeam, ComputeRotation, x); }
      Float64 ComputeDeflection(Float64 x) const override { PYBIND11_OVERRIDE_PURE(Float64, RoarkBeam, ComputeDeflection, x); }
   };

   py::class_<RoarkBeam,PyRoarkBeam>(m,"Beam")
      .def_property("L",&RoarkBeam::GetL,&RoarkBeam::SetL)
      .def_property("EI", &RoarkBeam::GetEI, &RoarkBeam::SetEI)
      .def("clone",&RoarkBeam::CreateClone)
      .def("reactions",&RoarkBeam::GetReactions)
      .def("moments", &RoarkBeam::GetMoments)
      .def("rotations", &RoarkBeam::GetRotations)
      .def("deflections", &RoarkBeam::GetDeflections)
      .def("shear",&RoarkBeam::ComputeShear)
      .def("moment", &RoarkBeam::ComputeMoment)
      .def("rotation", &RoarkBeam::ComputeRotation)
      .def("deflection", &RoarkBeam::ComputeDeflection)
      ;

   class PyPPPartialUniformLoad : public PPPartialUniformLoad
   {
      using PPPartialUniformLoad::PPPartialUniformLoad; // Inherit constructors

      using Result = std::pair<Float64, Float64>;
      std::unique_ptr<RoarkBeam> CreateClone() const override { PYBIND11_OVERRIDE(std::unique_ptr<RoarkBeam>, RoarkBeam, CreateClone, /*no parameters*/); }
      std::pair<Float64, Float64> GetReactions() const override { PYBIND11_OVERRIDE(Result, PPPartialUniformLoad, GetReactions, /*no parameters*/); }
      std::pair<Float64, Float64> GetMoments() const override { PYBIND11_OVERRIDE(Result, PPPartialUniformLoad, GetMoments, /*no parameters*/); }
      std::pair<Float64, Float64> GetRotations() const override { PYBIND11_OVERRIDE(Result, PPPartialUniformLoad, GetRotations, /*no parameters*/); }
      std::pair<Float64, Float64> GetDeflections() const override { PYBIND11_OVERRIDE(Result, PPPartialUniformLoad, GetDeflections, /*no parameters*/); }
      WBFL::System::SectionValue ComputeShear(Float64 x) const override { PYBIND11_OVERRIDE(WBFL::System::SectionValue, PPPartialUniformLoad, ComputeShear, x); }
      WBFL::System::SectionValue ComputeMoment(Float64 x) const override { PYBIND11_OVERRIDE(WBFL::System::SectionValue, PPPartialUniformLoad, ComputeMoment, x); }
      Float64 ComputeRotation(Float64 x) const override { PYBIND11_OVERRIDE(Float64, PPPartialUniformLoad, ComputeRotation, x); }
      Float64 ComputeDeflection(Float64 x) const override { PYBIND11_OVERRIDE(Float64, PPPartialUniformLoad, ComputeDeflection, x); }
   };

   py::class_<PPPartialUniformLoad, RoarkBeam, PyPPPartialUniformLoad>(m, "PPPartialUniformLoad")
      .def(py::init<Float64,Float64,Float64,Float64,Float64>())
      .def_property("La", &PPPartialUniformLoad::GetLa, &PPPartialUniformLoad::SetLa)
      .def_property("Lb", &PPPartialUniformLoad::GetLb, &PPPartialUniformLoad::SetLb)
      .def_property("w", &PPPartialUniformLoad::GetW, &PPPartialUniformLoad::SetW)
      ;
}
