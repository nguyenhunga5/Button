/*
 * CapacitiveButton.h
 *
 * Created: 18/11/2014 19:34:16
 *  Author: Richard
 */ 


#ifndef CAPACITIVEBUTTON_H_
#define CAPACITIVEBUTTON_H_

#include "Button.h"
#include "CapacitiveSensor.h"

// Define button configuration callback
typedef void (*CapacitiveButtonConfigurationCallback)(CapacitiveSensor&);

class CapacitiveButton : public Button {
	
	private:
	CapacitiveSensor capSense = CapacitiveSensor(-1, -1);	// Called with pins set to -1 as there is not default constructor
	long _threshold = 1000;
	long _number_of_samples = 30;
	
	protected:
	boolean _update_button_state();
	
	public:
	CapacitiveButton(uint8_t, uint8_t);
	
	void configureButton(CapacitiveButtonConfigurationCallback);
	void setNumberOfSamples(uint8_t);
	void setThreshold(long);
};

#endif /* CAPACITIVEBUTTON_H_ */