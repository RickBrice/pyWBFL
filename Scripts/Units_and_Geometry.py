import WBFLGeometry
import Units
a = 10.0
b = 20.0
rect = WBFLGeometry.Rect2d(0,0,a,b)
area = rect.area()
area2 = Units.convert(area,Units.Measure.Feet2,Units.Measure.Meter2)

