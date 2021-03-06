#include "Atmega168Utils.h"

#include <avr/io.h>

namespace Atmega168 {
// TODO: Check that these are correct. They were copied from Atmega328p code

void setTimer0Prescaler(TimerPrescalerValue value) {
  switch (value) {
  case PSV_1:
    TCCR0B |= BV(CS00);
    break;
  case PSV_8:
    TCCR0B |= BV(CS01);
    break;
  case PSV_64:
    TCCR0B |= BV(CS01) | BV(CS00);
    break;
  case PSV_256:
    TCCR0B |= BV(CS02);
    break;
  case PSV_1024:
    TCCR0B |= BV(CS02) | BV(CS00);
    break;
  }
}

void setTimer1Prescaler(TimerPrescalerValue value) {
  switch (value) {
  case PSV_1:
    TCCR1B |= BV(CS10);
    break;
  case PSV_8:
    TCCR1B |= BV(CS11);
    break;
  case PSV_64:
    TCCR1B |= BV(CS11) | BV(CS10);
    break;
  case PSV_256:
    TCCR1B |= BV(CS12);
    break;
  case PSV_1024:
    TCCR1B |= BV(CS12) | BV(CS10);
    break;
  }
}

void setTimer2Prescaler(TimerPrescalerValue value) {
  switch (value) {
  case PSV_1:
    TCCR2B |= BV(CS20);
    break;
  case PSV_8:
    TCCR2B |= BV(CS21);
    break;
  case PSV_32:
    TCCR2B |= BV(CS21) | BV(CS20);
    break;
  case PSV_64:
    TCCR2B |= BV(CS22);
    break;
  case PSV_128:
    TCCR2B |= BV(CS22) | BV(CS20);
    break;
  case PSV_256:
    TCCR2B |= BV(CS22) | BV(CS21);
    break;
  case PSV_1024:
    TCCR2B |= BV(CS22) | BV(CS21) | BV(CS20);
    break;
  }
}

void setVoltageReference(VoltageReference reference) {
  switch(reference) {
  case VREF_AREF:
    // The default, nothing to do
    break;
  case VREF_VCC:
    ADMUX |= BV(REFS0);
    break;
  case VREF_INTERNAL_1_1V:
    ADMUX |= BV(REFS1) | BV(REFS0);
    break;
  }
}

void leftAdjustAdcResults(bool leftAdjust) {
  if(leftAdjust) {
    ADMUX |= BV(ADLAR);
  } else {
    ADMUX &= ~BV(ADLAR);
  }
}

void setAdcPrescalerValue(AdcPrescalerValue value) {
  switch(value) {
  case ADC_PSV_2:
    // The default, nothing to do
    break;
  case ADC_PSV_4:
    ADCSRA |= BV(ADPS1);
    break;
  case ADC_PSV_8:
    ADCSRA |= BV(ADPS1) | BV(ADPS0);
    break;
  case ADC_PSV_16:
    ADCSRA |= BV(ADPS2);
    break;
  case ADC_PSV_32:
    ADCSRA |= BV(ADPS2) | BV(ADPS0);
    break;
  case ADC_PSV_64:
    ADCSRA |= BV(ADPS2) | BV(ADPS1);
    break;
  case ADC_PSV_128:
    ADCSRA |= BV(ADPS2) | BV(ADPS1) | BV(ADPS0);
    break;
  }
}

} // namespace