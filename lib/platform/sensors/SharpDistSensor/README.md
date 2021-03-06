# SharpDistSensor

A library for the Arduino IDE that helps interface with Sharp analog distance sensors.  

By Julien de la Bruère-Terreault (drgfreeman@tuta.io) and licensed under MIT. The original source can be found here: <https://github.com/DrGFreeman/SharpDistSensor>

Version 1.5.1 (modified)  

Modified by Margreve Mike:

- Added model `GP2Y0A21SK0f_5V_DS` (range 10 - 80 cm) based on polynomials given in this [Blog](http://embeddedlaboratory.blogspot.com/2016/12/distance-measurement-using-sharp-ir.html).
- Added mode `FIT_POLY_VOLT` which does the same than `FIT_POLY` but applied to a voltage (and not the 10-bit analog value from the sensor). Polynomial fit coefficients shall be given accordingly. When `FIT_POLY_VOLT` is chosen, before computing the distance the 10-bit analog value from the sensor is converted to a voltage between 0 and 5V.
- Changed `_valMin` and `_valMax` variables type to `float`. This variables are used to define an upper and lower bound for the analog (or voltage) reading from the sensor.
- Polynomial fit function computes a `float` result.
- Changed initial seed for the Median Filter to 0.

## Summary

The analog value from the sensor is converted to distance using either a
polynomial fit function up to fifth order or a power fit function.

By default, this library is set to use polynomial coefficients calibrated for the Sharp GP2Y0A60SZLF Analog Distance Sensor 10-150cm 5V, over a range of 50-1500 mm (analog values 30-875). The returned distance is in millimeters (mm) units.  

The library also allows the use of pre-defined calibrations for different sensor models as well as custom defined polynomial or power fit functions. Examples are provided showing how to use pre-defined calibrations or how to define custom fit functions.

The distance output is filtered using real-time median filtering (sliding window of ajustable size). The MedianFilter class from the following library is used: <https://github.com/daPhoosa/MedianFilter>.

## Examples

Five example sketches are provided with the library:

- _SharpDistSensorBasic.ino_  
This example shows how to use the library with the default calibration function for the Sharp GP2Y0A60SZLF 5V sensor.

- _SharpDistSensorByModel.ino_  
This example shows how to use the library by selecting a pre-defined sensor
model calibration.

- _SharpDistSensorCustomPoly.ino_  
This example shows how to use the library with a custom, user defined polynomial calibration function.

- _SharpDistSensorCustomPower.ino_  
This example shows how to use the library with a custom, user defined power calibration function.

- _SharpDistSensorArray.ino_  
This example shows how to use the library with an array of multiple sensors.

## Library Reference

- `SharpDistSensor(const byte pin, const byte size = 1)`  
Constructor: `pin` is the analog pin to which the sensor is connected, `size` is the size of the median filter window and should be an odd positive integer (default = 1 = no filtering).  

- `uint16_t getDist()`  
Returns the measured distance. Distance units are in millimeters (mm) if using the library default settings or pre-defined sensor models. If using custom calibration, units depend on the calibration used.  

- `void setModel(const byte model)`
Sets the calibration based on pre-defined sensor model fit functions. Note that the model argument must be preceded by the SharpDistSensor namespace, i.e.: `setModel(SharpDistSensor::Model_Name)`

- `void setPolyFitCoeffs(const byte nbCoeffs, const float\* coeffs, const uint16_t valMin, const uint16_t valMax)`  
Sets the polynomial fit function coefficients *C0* to *C5* in the relation:
_Distance = C0 + C1 x A + C2 x A^2 + ... + C5 x A^5_
where *A* is the analog value read from the sensor. At least one coefficient must be provided and up to six maximum (5th order polynomial). `nbCoeffs` is the number of coefficients passed and `coeffs` a vector containing the coefficients (C0 to C5). `valMin` and `valMax` define the range of analog values for which the polynomial fit is valid. Analog values outside this range will be set to the respective min or max values.  

- `void setPowerFitCoeffs(const float C, const float P, const uint16_t valMin, const uint16_t valMax)`  
Sets the power fit function coefficients _C_ and _P_ in the relation:  
_Distance = C x A^P_
where _A_ is the analog value read from the sensor. `valMin` and `valMax` define the range of analog values for which the power fit is valid. Analog values outside this range will be set to the respective min or max values.  

- `void setValMinMax(const float valMin, const float valMax)`  
Sets the range of analog values for which the polynomial or power fit is valid (`valMin` and `valMax`). Analog values outside this range will be set to the respective min or max values.

## Pre-defined sensor models

- `GP2Y0A21SK0f_5V_DS`: GP2Y0A21SK0f Analog Distance Sensor 10-80cm), 5V, polynomial fit.
- `GP2Y0A60SZLF_5V`: GP2Y0A60SZLF Analog Distance Sensor 10-150cm, 5V, polynomial fit.
- `GP2Y0A41SK0F_5V_DS`: GP2Y0A41SK0F Analog Distance Sensor 4-30cm, 5V (data sheet), polynomial fit.
- `GP2Y0A51SK0F_5V_DS`: GP2Y0A51SK0F Analog Distance Sensor 2-15cm, 5V (data sheet), power fit.
- `GP2Y0A710K0F_5V_DS`: GP2Y0A710K0F Analog Distance Sensor 100-500cm, 5V (data sheet), polynomial fit.

### Polynomial / Power fit coefficients

Model | Units | C0/C | C1/P | C2 | C3 | C4 | C5
------|-------|----|----|----|----|----|----
**GP2Y0A60SZLF_5V** | mm | 1734 | -9.005 | 2.032E-2 | -2.251E-5 | 1.167E-8 | -2.037E-12
**GP2Y0A41SK0F_5V_DS** | mm | 761.9 | -8.13336 | 4.18857E-2 | -1.11338E-4 | 1.46237E-7 | -7.49656E-11
**GP2Y0A51SK0F_5V_DS** | mm | 4.03576E+4 | -1.26093 | | | |
**GP2Y0A710K0F_5V_DS** | mm | 178506 | -1607.72 | 5.5239 | -8.47601E-3 | 4.87819E-6 |

For the **GP2Y0A21SK0f_5V_DS**:
Coefficients (with 95% confidence bounds):

- C4 =    8.075 (3.718, 12.43)  
- C3 =   -68.44 (-99.23, -37.65)  
- C2 =    210.4 (136.7, 284.1)  
- C1 =   -285.2 (-353.5, -216.9)  
- C0 =    161.3 (141.4, 181.2)  

Generated from Matlab, see this [Blog](http://embeddedlaboratory.blogspot.com/2016/12/distance-measurement-using-sharp-ir.html).

### Analog values range

Model | valMin | valMax
------|--------|--------
**GP2Y0A60SZLF_5V** | 30 | 875
**GP2Y0A41SK0F_5V_DS** | 61 | 614
**GP2Y0A51SK0F_5V_DS** | 70 | 500
**GP2Y0A710K0F_5V_DS** | 284 | 507

**Important Note:** The analog voltage returned by the sensor is largely dependent of the reflected object size and reflectivity. The distance returned by these pre-defined calibration functions can therefore vary significantly from the real distance depending on the object detected. Where accuracy is required by the application, it is recommended to perform calibration with the object to be detected and use custom calibration fit functions instead.

This library has been designed so that it is easy to add sensor models. Contributions are therefore welcome. Adding models to the library can be done by either submitting a pull request or providing me the proposed fit function and associated calibration data by email so I can add it myself. Thank you for contributing!

## Version history

- 1.5.1 (2020-04-20): Modified by Margreve Mike (see above)
- 1.5.0 (2018-10-22): Added GP2Y0A41SK0F_5V_DS model.
- 1.4.2 (2018-09-23): Improved comments in SharpDistSensorArray example.
- 1.4.1 (2018-08-07): Updated MedianFilter to latest version from [daPhoosa/MedianFilter](https://github.com/daPhoosa/MedianFilter).
- 1.4.0 (2018-05-21): Added GP2Y0A51SK0F_5V_DS model.
- 1.3.0 (2018-05-20): Added SharpDistSensorArray example.
- 1.2.0 (2017-05-10): Added GP2Y0A710K0F_5V_DS model.
- 1.1.1 (2017-05-01): Clarified comments and fixed typos in examples, improved README.
- 1.1.0 (2017-04-05): Added support of power fit functions.
- 1.0.0 (2017-03-29): Initial major release for Arduino Library Manager (no change rel. to 0.3.2)
- 0.3.2 (2017-03-29): Modified models enum and related type in setModel method arguments.
- 0.3.1 (2017-03-28): Improved README and fixed comments in SharpDistSensorByModel example.
- 0.3.0 (2017-03-24): Added method to set calibration based on pre-defined sensor models.
