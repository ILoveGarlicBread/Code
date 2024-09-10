#!/usr/bin/env pybricks-micropython

import threading
from pybricks.ev3devices import Motor, ColorSensor
from pybricks.parameters import Port, Direction
from pybricks.tools import wait
from pybricks.robotics import DriveBase

#########################################################################
################################SET UP##################################
#########################################################################

# Initialize the motors.
left_motor = Motor(Port.C, Direction.COUNTERCLOCKWISE)
left_motor.reset_angle(0)
right_motor = Motor(Port.B)
right_motor.reset_angle(0)
arm_motor = Motor(Port.A)
robot = DriveBase(left_motor, right_motor, 55.5, 20)

# Initialize the color sensor.
left_sensor = ColorSensor(Port.S2)
right_sensor = ColorSensor(Port.S3)

########################################################################
###############################FUNCTIONS################################
########################################################################

BLACK = 9
WHITE = 85
threshold = (BLACK + WHITE) / 2


def PID_for_degree(speed, degree):
    DRIVE_SPEED = speed

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
            left_motor.stop()
            right_motor.stop()
            break

def run_distance(speed, milimeters):
    robot.settings(straight_speed= speed)
    robot.straight(milimeters)
    robot.stop()

def rotate(degree):
    robot.turn(degree)
    robot.stop()

########################################################################
#################################RUN####################################
########################################################################
robot.settings(turn_rate = 500)
arm_motor.run_angle(900,800)
PID_for_degree(400, 660)
rotate(580)
PID_for_degree(400, 2780)
rotate(580)
PID_for_degree(400, 350)
rotate(580)
PID_for_degree(400, 800)
run_distance(70, 50)
rotate(-570)
run_distance(70, 60)
arm_motor.run_angle(700,-800)
run_distance(70, -60)
#rotate(-590)
#PID_for_degree(400, 850)
#rotate(-580)
#PID_for_degree(400, 350)
#rotate(-580)
