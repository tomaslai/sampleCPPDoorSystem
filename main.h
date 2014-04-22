enum State { STATE_START, STATE_CALIBRATE_SENSOR, STATE_READ_DATA, STATE_MOVE_MOTOR, STATE_END};
void MoveToNextState();
bool IsDoorOpen();
void Action();
