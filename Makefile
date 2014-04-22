all: main

main: main.o CSensor.o CMotor.o CDoorLatch.o
	g++ main.o CSensor.o CMotor.o CDoorLatch.o -o main

main.o: main.cpp
	g++ -c main.cpp

CSensor.o: CSensor.cpp
	g++ -c CSensor.cpp

CMotor.o: CMotor.cpp
	g++ -c CMotor.cpp

CDoorLatch.o: CDoorLatch.cpp
	g++ -c CDoorLatch.cpp

clean:
	rm -rf *o main
