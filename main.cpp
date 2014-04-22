#include "main.h"
#include "CSensor.h"
#include "CMotor.h"
#include "CDoorLatch.h"
#include <iostream>
using namespace std;

//Sensor Data:
int data[] = { 100, 101, 105, 110, 210, 100, 102, 110, 150, 100 };
CMotor motor;
CSensor sensor;
State currentState;
CDoorLatch doorLatch;

int main()
{
	//reset motor
	motor.ResetMotor();
	//initialize state
	currentState = STATE_START;

	while (currentState != STATE_END){
		//move to next state
		MoveToNextState();
		//take currentstate into action
		Action();
	}
	return 0;
}

//Move to next State
void MoveToNextState() {
	switch (currentState) {
	case STATE_START:
		if (!IsDoorOpen()){
			currentState = STATE_CALIBRATE_SENSOR;
		}
		break;
	case STATE_CALIBRATE_SENSOR:
		currentState = STATE_READ_DATA;
		break;
	case STATE_READ_DATA:
		currentState = STATE_MOVE_MOTOR;
		break;
	case STATE_MOVE_MOTOR:
		currentState = STATE_END;
		break;
	case STATE_END:
		currentState = STATE_START;
		break;
	}
}

// Check if door is open
bool IsDoorOpen() {
	return !doorLatch.IsDoorClosed();
}

//take currentstate into action
void Action(){
	switch (currentState) {
	case STATE_CALIBRATE_SENSOR:
		sensor.Calibrate();
		break;
	case STATE_READ_DATA:
		int arraySize;
		arraySize = sizeof(data) / sizeof(data[0]);
		sensor.ReadData(data, arraySize);
		break;
	case STATE_MOVE_MOTOR:
		motor.MoveMotor((int) sensor.lastAverageValue);
		break;
	default:
		// do nothing
		break;
	}
}