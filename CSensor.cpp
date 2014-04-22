#include "CSensor.h"
#include <iostream>
using namespace std;
bool CSensor::Calibrate(){
	cout << "sensor is calibrated\n";
	return true;
}

void CSensor::ReadData(int data[], int size){
	int sum = 0;
	for (int i=0 ; i < size ; i++){
		sum = sum + data[i];
	}
	lastAverageValue = (double) sum / size;
}