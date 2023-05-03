#include "pch.h"
#include <pybind11/operators.h>

using namespace WBFL::System;
namespace py = pybind11;

Float64 GetLeft(const SectionValue& sv) { return sv.Left(); }
void SetLeft(SectionValue& sv, Float64 left) { sv.Left() = left; }
Float64 GetRight(const SectionValue& sv) { return sv.Right(); }
void SetRight(SectionValue& sv, Float64 right) { sv.Right() = right; }

PYBIND11_MODULE(System,m)
{
   using namespace WBFL::System;

   py::class_<SectionValue>(m, "SectionValue")
      .def(py::init<Float64>())
      .def(py::init<Float64,Float64>())
      .def(py::init<const SectionValue&>())
      .def_property("left", GetLeft, SetLeft)
      .def_property("right", GetRight, SetRight)
      .def("as_string",&SectionValue::AsString)
      //.def(py::self = Float64()) // SectionValue& operator=(Float64 val);
      .def(py::self += py::self)
      .def(py::self -= py::self)
      .def(py::self *= py::self)
      .def(py::self /= py::self)
      //.def(-py::self) // SectionValue  operator-();
      .def(py::self += Float64())
      .def(py::self -= Float64())
      .def(py::self *= Float64())
      .def(py::self /= Float64())
      ;
}
