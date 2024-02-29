#!/usr/bin/env pybricks-micropython
from pybricks.hubs import EV3Brick
from pybricks.ev3devices import Motor
from pybricks.parameters import Port

# Create your objects here

# Initialize the EV3 Brick.
ev3 = EV3Brick()

# Initialize a motor at port B.
test_motor = Motor(Port.A)

# Write your program here


# Run the motor up to 500 degrees per second. To a target angle of 90 degrees.
while True:
    test_motor.run(500)
    test_motor.stop()
    