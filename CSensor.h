class CSensor
{
public:
	double lastAverageValue;
	bool Calibrate(); // calibrates the sensor
	void ReadData(int data[],int size); // Reads the data from the sensor
};
