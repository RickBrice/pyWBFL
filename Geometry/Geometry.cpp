#include "pch.h"
#include "Primitives.h"
#include "LineSegment2d.h"
#include "Vector2d.h"

namespace py = pybind11;

PYBIND11_MODULE(Geometry,m)
{
   export_primitives_types(m);
   export_LineSegment2d_types(m);
   export_Vector2d_types(m);
}
