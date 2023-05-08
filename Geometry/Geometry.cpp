#include "pch.h"
#include "Primitives.h"
#include "Primitives3d.h"
#include "Line2d.h"
#include "LineSegment2d.h"
#include "LineSegment3d.h"
#include "Vector2d.h"
#include "Vector3d.h"
#include "Arc.h"
#include "Circle2d.h"
#include "Plane3d.h"

namespace py = pybind11;

PYBIND11_MODULE(Geometry,m)
{
   export_Primitives_types(m);
   export_Primitives3d_types(m);
   export_Line2d_types(m);
   export_LineSegment2d_types(m);
   export_LineSegment3d_types(m);
   export_Vector2d_types(m);
   export_Vector3d_types(m);
   
   export_Arc_types(m);
   export_Circle2d_types(m);
   export_Plane3d_types(m);
}
