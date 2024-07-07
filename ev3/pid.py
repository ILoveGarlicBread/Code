#!/usr/bin/env pybricks-micropython

from pybricks.ev3devices import Motor, ColorSensor
from pybricks.parameters import Port, Direction
from pybricks.tools import wait
from pybricks.robotics import DriveBase

# Initialize the motors.
left_motor = Motor(Port.B, Direction.COUNTERCLOCKWISE)
right_motor = Motor(Port.C)

# Initialize the color sensor.
left_sensor = ColorSensor(Port.S2)
right_sensor = ColorSensor(Port.S3)

# Calculate the light threshold. Choose values based on your measurements.
BLACK = 9
WHITE = 85
threshold = (BLACK + WHITE) / 2


def PID_for_degree(degree):
    DRIVE_SPEED = 400

    PROPORTIONAL_GAIN = 5
    DERIVATIVE_GAIN = 2

    left_derivative = 0
    right_derivative = 0

    last_left_error = 0
    last_right_error = 0

    right_motor.reset_angle(0)
    while True:
        left_error = left_sensor.reflection() - threshold
        right_error = right_sensor.reflection() - threshold
        left_derivative = left_error - last_left_error
        right_derivative = right_error - last_right_error

        left_turn_rate = (
            PROPORTIONAL_GAIN * left_error + DERIVATIVE_GAIN * left_derivative
        )
        right_turn_rate = (
            PROPORTIONAL_GAIN * right_error + DERIVATIVE_GAIN * right_derivative
        )

        left_motor.run(DRIVE_SPEED + left_turn_rate)
        right_motor.run(DRIVE_SPEED + right_turn_rate)
        last_left_error = left_error
        last_right_error = right_error
        if right_motor.angle() >= degree:
            break


PID_for_degree(1000)
