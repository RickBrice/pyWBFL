#include "pch.h"

using namespace WBFL::System;
Float64 GetLeft(const SectionValue& sv) { return sv.Left(); }
void SetLeft(SectionValue& sv, Float64 left) { sv.Left() = left; }
Float64 GetRight(const SectionValue& sv) { return sv.Right(); }
void SetRight(SectionValue& sv, Float64 right) { sv.Right() = right; }

BOOST_PYTHON_MODULE(System)
{
   using namespace boost::python;
   using namespace WBFL::System;

   class_<SectionValue>("SectionValue")
      .def(init<Float64>())
      .def(init<Float64,Float64>())
      .def(init<const SectionValue&>())
      .add_property("left", GetLeft, SetLeft)
      .add_property("right", GetRight, SetRight)
      .def("as_string",&SectionValue::AsString)
      ;
}
