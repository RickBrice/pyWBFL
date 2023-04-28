#include "pch.h"
#include "Primitives.h"
#include "LineSegment2d.h"
#include "Vector2d.h"


BOOST_PYTHON_MODULE(WBFLGeometry)
{
   using namespace boost::python;
   export_primitives_types();
   export_LineSegment2d_types();
   export_Vector2d_types();
}
