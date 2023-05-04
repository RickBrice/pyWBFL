#include "pch.h"
#include "RoarkBeam.h"
#include "PPIntermediateCouple.h"
#include "PPIntermediateLoad.h"
#include "PPPartialUniformLoad.h"
#include "CompositeBeam.h"

using namespace WBFL::Beams;
namespace py = pybind11;


PYBIND11_MODULE(Beams,m)
{
   export_RoarkBeam_types(m);
   export_PPIntermediateCouple_types(m);
   export_PPIntermediateLoad_types(m);
   export_PPPartialUniformLoad_types(m);
   export_CompositeBeam_types(m);
}
