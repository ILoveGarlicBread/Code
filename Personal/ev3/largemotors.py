#!/usr/bin/env pybricks-micropython

from pybricks.hubs import EV3Brick
from pybricks.ev3devices import Motor
from pybricks.parameters import Port 
from pybricks.robotics import DriveBase

ev3 = EV3Brick()
left_motor  = Motor(Port.B)
right_motor = Motor(Port.C)

robot = DriveBase(left_motor, right_motor, 55.5, 104)

robot.turn(90)
