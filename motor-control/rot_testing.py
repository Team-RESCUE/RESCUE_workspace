import pigpio
import time
import numpy as np

# define output pin
pi = pigpio.pi()
pi.set_mode(13,pigpio.OUTPUT)

# get initial time
