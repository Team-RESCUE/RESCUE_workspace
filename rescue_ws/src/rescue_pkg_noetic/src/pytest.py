import time
import sys


def print(sleep_time):
	print("Python script accessed\n")

	time.sleep(sleep_time) 

	print("I just took a nice ",sleep_time,"-second power nap\n")
	return sleep_time*3