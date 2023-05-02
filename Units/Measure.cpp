#include "pch.h"
#include "Measure.h"

using namespace boost::python;
using namespace WBFL::Units;

void export_measure_types()
{
   class_<Measure,boost::noncopyable>("Measure",no_init)
      .def_readonly("Kilogram",&Measure::Kilogram)
      .def_readonly("Gram", &Measure::Gram)
      .def_readonly("MetricTon", &Measure::MetricTon)
      .def_readonly("Slug", &Measure::Slug)
      .def_readonly("PoundMass", &Measure::PoundMass)
      .def_readonly("KSlug", &Measure::KSlug)
      .def_readonly("_12Slug", &Measure::_12Slug)
      .def_readonly("_12KSlug", &Measure::_12KSlug)

      .def_readonly("KgPerMeter", &Measure::KgPerMeter)
      .def_readonly("LbmPerFeet", &Measure::LbmPerFeet)
      .def_readonly("SlugPerFeet", &Measure::SlugPerFeet)
      .def_readonly("LbfPerFeet", &Measure::LbfPerFeet)

      .def_readonly("Meter",&Measure::Meter)
      .def_readonly("Millimeter", &Measure::Millimeter)
      .def_readonly("Centimeter", &Measure::Centimeter)
      .def_readonly("Kilometer", &Measure::Kilometer)
      .def_readonly("Feet", &Measure::Feet)
      .def_readonly("USSurveyFoot", &Measure::USSurveyFoot)
      .def_readonly("Inch", &Measure::Inch)
      .def_readonly("Mile", &Measure::Mile)
      .def_readonly("Yard", &Measure::Yard)
      .def_readonly("USSurveyYard", &Measure::USSurveyYard)

      .def_readonly("Meter2", &Measure::Meter2)
      .def_readonly("Millimeter2", &Measure::Millimeter2)
      .def_readonly("Centimeter2", &Measure::Centimeter2)
      .def_readonly("Kilometer2", &Measure::Kilometer2)
      .def_readonly("Feet2", &Measure::Feet2)
      .def_readonly("Inch2", &Measure::Inch2)
      .def_readonly("Mile2", &Measure::Mile2)
      .def_readonly("Yard2", &Measure::Yard2)

      .def_readonly("Meter3", &Measure::Meter3)
      .def_readonly("Millimeter3", &Measure::Millimeter3)
      .def_readonly("Centimeter3", &Measure::Centimeter3)
      .def_readonly("Kilometer3", &Measure::Kilometer3)
      .def_readonly("Feet3", &Measure::Feet3)
      .def_readonly("Inch3", &Measure::Inch3)
      .def_readonly("Mile3", &Measure::Mile3)
      .def_readonly("Yard3", &Measure::Yard3)

      .def_readonly("Meter4", &Measure::Meter4)
      .def_readonly("Millimeter4", &Measure::Millimeter4)
      .def_readonly("Centimeter4", &Measure::Centimeter4)
      .def_readonly("Kilometer4", &Measure::Kilometer4)
      .def_readonly("Feet4", &Measure::Feet4)
      .def_readonly("Inch4", &Measure::Inch4)
      .def_readonly("Mile4", &Measure::Mile4)
      .def_readonly("Yard4", &Measure::Yard4)

      .def_readonly("Meter2PerMeter", &Measure::Meter2PerMeter)
      .def_readonly("Millimeter2PerMillimeter", &Measure::Millimeter2PerMillimeter)
      .def_readonly("Millimeter2PerMeter", &Measure::Millimeter2PerMeter)
      .def_readonly("Feet2PerFoot", &Measure::Feet2PerFoot)
      .def_readonly("Inch2PerInch", &Measure::Inch2PerInch)
      .def_readonly("Inch2PerFoot", &Measure::Inch2PerFoot)

      .def_readonly("PerMeter", &Measure::PerMeter)
      .def_readonly("PerMillimeter", &Measure::PerMillimeter)
      .def_readonly("PerInch", &Measure::PerInch)
      .def_readonly("PerFeet", &Measure::PerFeet)

      .def_readonly("Second", &Measure::Second)
      .def_readonly("Minute", &Measure::Minute)
      .def_readonly("Hour", &Measure::Hour)
      .def_readonly("Day", &Measure::Day)

      .def_readonly("Celsius", &Measure::Celsius)
      .def_readonly("Fahrenheit", &Measure::Fahrenheit)

      .def_readonly("Radian", &Measure::Radian)
      .def_readonly("Degree", &Measure::Degree)

      .def_readonly("Pa", &Measure::Pa)
      .def_readonly("kPa", &Measure::kPa)
      .def_readonly("MPa", &Measure::MPa)
      .def_readonly("PSI", &Measure::PSI)
      .def_readonly("PSF", &Measure::PSF)
      .def_readonly("KSI", &Measure::KSI)
      .def_readonly("KSF", &Measure::KSF)

      .def_readonly("NewtonPerMeter3", &Measure::NewtonPerMeter3)
      .def_readonly("PCI", &Measure::PCI)
      .def_readonly("PCF", &Measure::PCF)

      .def_readonly("KgPerMeter3", &Measure::KgPerMeter3)
      .def_readonly("LbmPerFeet3", &Measure::LbmPerFeet3)
      .def_readonly("SlugPerFeet3", &Measure::SlugPerFeet3)
      .def_readonly("LbfPerFeet3", &Measure::LbfPerFeet3)
      .def_readonly("KipPerFeet3", &Measure::KipPerFeet3)

      .def_readonly("Newton", &Measure::Newton)
      .def_readonly("Kilonewton", &Measure::Kilonewton)
      .def_readonly("Pound", &Measure::Pound)
      .def_readonly("Kip", &Measure::Kip)
      .def_readonly("Ton", &Measure::Ton)

      .def_readonly("NewtonPerMeter", &Measure::NewtonPerMeter)
      .def_readonly("KilonewtonPerMeter", &Measure::KilonewtonPerMeter)
      .def_readonly("NewtonPerMillimeter", &Measure::NewtonPerMillimeter)
      .def_readonly("LbfPerFoot", &Measure::LbfPerFoot)
      .def_readonly("LbfPerInch", &Measure::LbfPerInch)
      .def_readonly("KipPerFoot", &Measure::KipPerFoot)
      .def_readonly("KipPerInch", &Measure::KipPerInch)

      .def_readonly("NewtonMeter", &Measure::NewtonMeter)
      .def_readonly("KilonewtonMeter", &Measure::KilonewtonMeter)
      .def_readonly("NewtonMillimeter", &Measure::NewtonMillimeter)
      .def_readonly("InchLbf", &Measure::InchLbf)
      .def_readonly("KipFeet", &Measure::KipFeet)
      .def_readonly("KipInch", &Measure::KipInch)

      .def_readonly("NewtonMeterPerRadian", &Measure::NewtonMeterPerRadian)
      .def_readonly("KiloNewtonMeterPerRadian", &Measure::KiloNewtonMeterPerRadian)
      .def_readonly("KipInchPerRadian", &Measure::KipInchPerRadian)
      .def_readonly("KipFeetPerRadian", &Measure::KipFeetPerRadian)

      .def_readonly("SqrtPa", &Measure::SqrtPa)
      .def_readonly("SqrtMPa", &Measure::SqrtMPa)
      .def_readonly("SqrtKSI", &Measure::SqrtKSI)

      .def_readonly("MeterPerSec2", &Measure::MeterPerSec2)
      .def_readonly("FeetPerSec2",&Measure::FeetPerSec2)

      .def_readonly("KipInch2", &Measure::KipInch2)
      .def_readonly("KipFoot2", &Measure::KipFoot2)
      .def_readonly("LbfInch2", &Measure::LbfInch2)
      .def_readonly("LbfFoot2", &Measure::LbfFoot2)
      .def_readonly("NewtonMeter2", &Measure::NewtonMeter2)
      .def_readonly("NewtonMillimeter2", &Measure::NewtonMillimeter2)
      .def_readonly("KilonewtonMeter2", &Measure::KilonewtonMeter2)

      .def_readonly("KilometerPerHour", &Measure::KilometerPerHour)
      .def_readonly("MeterPerSecond", &Measure::MeterPerSecond)
      .def_readonly("MilePerHour", &Measure::MilePerHour)
      .def_readonly("FeetPerSecond", &Measure::FeetPerSecond)
   ;
}