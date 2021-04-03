import pigpio
import time
import numpy as np
import sys

# define output pins
pi = pigpio.pi()
pins_out = [13,5]
# pivot_pinout = 13
# rot_pinout = 5
pi.set_mode(pins_out,pigpio.OUTPUT)

# get initial time
tick_i = pi.get_current_tick()

# get initial pulsewidths
this_pws = [pi.get_servo_pulsewidth()]

# set target pulsewidths
target_pws = [int(sys.argv[1]), int(sys.argv[2])]

# pi.set_servo_pulsewidth(pins_out,target_pws)

# loop to target pulsewidths
pw_diff = np.absolute(target_pws-this_pws) #check if this works as expected

# get final time
tick_f = pi.get_current_tick()

# print statements
print("Pivot pulsewidth changed from ",this_pws[0]," to ",target_pws[0])
print("Rotation pulsewidth changed from ",this_pws[1]," to ",target_pws[1])

# 1-second delay
time.sleep(1)