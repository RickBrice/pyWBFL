#pragma once

#define ENABLE_CREATE_CLONE // there is a problem compiling the override methods with std::unique_ptr return type

// this file defines "trampoline" classes with inheriting and overriding virtual class member functions
template <class RoarkBeamBase = RoarkBeam>
class PyRoarkBeamBase : public RoarkBeamBase
{
public:
   using RoarkBeamBase::RoarkBeamBase; // Inherit constructors

   using Result = std::pair<Float64, Float64>;
#if defined ENABLE_CREATE_CLONE
   std::shared_ptr<WBFL::Beams::RoarkBeam> CreateClone() const override { PYBIND11_OVERRIDE_PURE(std::shared_ptr<WBFL::Beams::RoarkBeam>, RoarkBeamBase, CreateClone, /*no parameters*/); }
#endif
   std::pair<Float64, Float64> GetReactions() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeamBase, GetReactions, /*no parameters*/); }
   std::pair<Float64, Float64> GetMoments() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeamBase, GetMoments, /*no parameters*/); }
   std::pair<Float64, Float64> GetRotations() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeamBase, GetRotations, /*no parameters*/); }
   std::pair<Float64, Float64> GetDeflections() const override { PYBIND11_OVERRIDE_PURE(Result, RoarkBeamBase, GetDeflections, /*no parameters*/); }
   WBFL::System::SectionValue ComputeShear(Float64 x) const override { PYBIND11_OVERRIDE_PURE(WBFL::System::SectionValue, RoarkBeamBase, ComputeShear, x); }
   WBFL::System::SectionValue ComputeMoment(Float64 x) const override { PYBIND11_OVERRIDE_PURE(WBFL::System::SectionValue, RoarkBeamBase, ComputeMoment, x); }
   Float64 ComputeRotation(Float64 x) const override { PYBIND11_OVERRIDE_PURE(Float64, RoarkBeamBase, ComputeRotation, x); }
   Float64 ComputeDeflection(Float64 x) const override { PYBIND11_OVERRIDE_PURE(Float64, RoarkBeamBase, ComputeDeflection, x); }
};

template <class RoarkBeamInstance>
class PyRoarkBeamInstance : public PyRoarkBeamBase<RoarkBeamInstance>
{
public:
   using PyRoarkBeamBase<RoarkBeamInstance>::PyRoarkBeamBase; // Inherit constructors

   using Result = std::pair<Float64, Float64>;
#if defined ENABLE_CREATE_CLONE
   std::shared_ptr<WBFL::Beams::RoarkBeam> CreateClone() const override { PYBIND11_OVERRIDE(std::shared_ptr<RoarkBeam>, RoarkBeamInstance, CreateClone, /*no parameters*/); }
#endif
   std::pair<Float64, Float64> GetReactions() const override { PYBIND11_OVERRIDE(Result, RoarkBeamInstance, GetReactions, /*no parameters*/); }
   std::pair<Float64, Float64> GetMoments() const override { PYBIND11_OVERRIDE(Result, RoarkBeamInstance, GetMoments, /*no parameters*/); }
   std::pair<Float64, Float64> GetRotations() const override { PYBIND11_OVERRIDE(Result, RoarkBeamInstance, GetRotations, /*no parameters*/); }
   std::pair<Float64, Float64> GetDeflections() const override { PYBIND11_OVERRIDE(Result, RoarkBeamInstance, GetDeflections, /*no parameters*/); }
   WBFL::System::SectionValue ComputeShear(Float64 x) const override { PYBIND11_OVERRIDE(WBFL::System::SectionValue, RoarkBeamInstance, ComputeShear, x); }
   WBFL::System::SectionValue ComputeMoment(Float64 x) const override { PYBIND11_OVERRIDE(WBFL::System::SectionValue, RoarkBeamInstance, ComputeMoment, x); }
   Float64 ComputeRotation(Float64 x) const override { PYBIND11_OVERRIDE(Float64, RoarkBeamInstance, ComputeRotation, x); }
   Float64 ComputeDeflection(Float64 x) const override { PYBIND11_OVERRIDE(Float64, RoarkBeamInstance, ComputeDeflection, x); }
};