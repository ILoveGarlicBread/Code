#!/usr/bin/env pybricks-micropython

from pybricks.ev3devices import Motor, ColorSensor
from pybricks.parameters import Port, Direction
from pybricks.robotics import DriveBase

def follow_line_motors_PID():
    left_motor  = Motor(Port.B, Direction.COUNTERCLOCKWISE)
    right_motor = Motor(Port.C, Direction.CLOCKWISE)
    left_sensor     = ColorSensor(Port.S1)
    right_sensor    = ColorSensor(Port.S2)
    

    BLACK = 3 
    WHITE = 62 
    threshold   = (BLACK + WHITE) / 2 
    DRIVE_SPEED = 500
    P_GAIN      = 5
    D_GAIN      = 5
    derivative_right  = 0 
    derivative_left   = 0
    last_error_left  = 0
    last_error_right = 0

    while True:
        error_left = left_sensor.reflection() - threshold
        error_right= right_sensor.reflection() - threshold
        derivative_left = error_left - last_error_left
        derivative_right = error_right - last_error_right

        turn_rate_lm  = P_GAIN  * error_left +D_GAIN * derivative_left
        turn_rate_rm  = P_GAIN  * error_right + D_GAIN * derivative_right
        left_motor.run(DRIVE_SPEED + turn_rate_lm)
        right_motor.run(DRIVE_SPEED + turn_rate_rm)
        last_error_left = error_left
        last_error_right = error_right

follow_line_motors_PID()
