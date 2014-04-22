#include "CMotor.h"
#include <iostream>
using namespace std;

void CMotor::ResetMotor()
{
	cout << "moves motor to the starting position\n";
}

void CMotor::MoveMotor(int distance)
{
	cout << "move motor to distance " << distance << " \n";
}
