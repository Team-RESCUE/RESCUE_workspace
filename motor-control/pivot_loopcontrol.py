# NOTICE: this is currently configured for testing (no GPIO outputs)
		# for testing, uncomment pigpio lines (anything with pigpio or pi)

# import pigpio
import time
import numpy as np
import sys

# define output pin
# pi = pigpio.pi()
# pi.set_mode(18,pigpio.OUTPUT)


# get initial time
time_i = time.perf_counter()

# set target pulsewidth
target_pw = int(sys.argv[1])
print("Target pulsewidth: ",target_pw)
# this_pw = pi.get_servo_pulsewidth(13)
this_pw = 1000

# loop to target pulsewidth, a little Zeno's paradox action
# (I'd call this process by its proper name if I knew it)

pw_diff = np.absolute(this_pw-target_pw)

print(this_pw)
while pw_diff > 20:

	# pi.set_servo_pulsewidth(13,this_pw + pw_diff/2)
	# this_pw = pi.get_servo_pulsewidth(13)

	this_pw = this_pw + pw_diff/2
	print(this_pw)
	pw_diff = np.absolute(this_pw-target_pw)

# pi.set_servo_pulsewidth(13,target_pw)
print(target_pw)