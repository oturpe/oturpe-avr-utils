// Helpers for working with Atmega168p.
//
// Obsoleted by more generic Atmega8Utils.h

// Cleaner setting of bits
#define BV(x) (1<<x)

namespace Atmega168 {

// TODO: Check that these are correct. They were copied from Atmega328p code

/// Possible prescaler values for timers.
enum TimerPrescalerValue {
  PSV_1,
  PSV_8,
  PSV_32,
  PSV_64,
  PSV_128,
  PSV_256,
  PSV_1024,
};

/// Sets timer 0 prescaler to requested value.
///
/// This function assumes that Clock Select bits have not been touched yet. Note
/// that timer 0 does not support all Timer0PrescalerValue values. If illegal
/// value is entered, prescaler is not set to any value.
///
/// \param value
///   Requested prescaler value
void setTimer0Prescaler(TimerPrescalerValue value);

/// Sets timer 1 prescaler to requested value.
///
/// This function assumes that Clock Select bits have not been touched yet. Note
/// that timer 1 does not support all Timer0PrescalerValue values. If illegal
/// value is entered, prescaler is not set to any value.
///
/// \param value
///   Requested prescaler value
void setTimer1Prescaler(TimerPrescalerValue value);

/// Sets timer 2 prescaler to requested value.
///
/// This function assumes that Clock Select bits have not been touched yet.
///
/// \param value
///   Requested prescaler value
void setTimer2Prescaler(TimerPrescalerValue value);

// Possible voltage references
enum VoltageReference {
  // Aref pin
  VREF_AREF,
  // Vcc with external capacitor
  VREF_VCC,
  // Internal 1.1 V with external capacitor
  VREF_INTERNAL_1_1V
};

// Sets analog voltage reference to requested type.
//
// This function assumes that Reference Selection bits have not been touched
// yet.
//
// \param reference
//    Requested voltage reference
void setVoltageReference(VoltageReference reference);

// Possible analog-to-digital converter prescaler values
enum AdcPrescalerValue {
  ADC_PSV_2,
  ADC_PSV_4,
  ADC_PSV_8,
  ADC_PSV_16,
  ADC_PSV_32,
  ADC_PSV_64,
  ADC_PSV_128
};

/// \brief
///    Sets adjustment of adc results to right (default) or left.
///
/// \param leftAdjust
///    If results are left adjusted.
void leftAdjustAdcResults(bool leftAdjust);

// Sets analog-to-digital converter prescaler value.
//
// This function assumes that ADV Prescaler Selection bits have not been touched
// yet.
//
// \param value
//    Requested prescaler value
void setAdcPrescalerValue(AdcPrescalerValue value);

} // namespace
