
import pigpio
import time
import numpy as np
import sys

# define output pin
pi = pigpio.pi()
pi.set_mode(18,pigpio.OUTPUT)

pin_out = 13 # not 18 for some reason

# get initial time
time_i = time.perf_counter()

# set target duty cycle
dc_range = pi.get_PWM_range(pin_out)
duty_cycle = .5

pi.set_PWM_dutycycle(pin_out,dc_range*duty_cycle)

# get final time
time_f = time.perf_counter()
print("\nTime elapsed: ",time_f-time_i," s")

# 1-second delay
time.sleep(1)