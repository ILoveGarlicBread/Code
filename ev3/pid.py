#!/usr/bin/env pybricks-micropython

from pybricks.ev3devices import Motor, ColorSensor
from pybricks.parameters import Port, Direction
from pybricks.tools import wait
from pybricks.robotics import DriveBase

# Initialize the motors.
left_motor = Motor(Port.B,Direction.COUNTERCLOCKWISE)
right_motor = Motor(Port.C)

# Initialize the color sensor.
left_sensor = ColorSensor(Port.S2)
right_sensor = ColorSensor(Port.S3)

# Calculate the light threshold. Choose values based on your measurements.
BLACK = 9
WHITE = 85
threshold = (BLACK + WHITE) / 2

# Set the drive speed at # millimeters per second.
DRIVE_SPEED = 500

PROPORTIONAL_GAIN = 5

while True:
    left_error = left_sensor.reflection() - threshold
    right_error = right_sensor.reflection() - threshold

    left_turn_rate = PROPORTIONAL_GAIN *left_error
    right_turn_rate = PROPORTIONAL_GAIN *right_error

    left_motor.run(DRIVE_SPEED + left_turn_rate)
    right_motor.run(DRIVE_SPEED + right_turn_rate)


