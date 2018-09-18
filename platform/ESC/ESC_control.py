import os
import time
os.system('sudo pigpiod')
time.sleep(2)
import pigpio

class ESC_control:

   	def __init__(self, PWM_pin):
        	self.esc_pin = PWM_pin
        	self.pi = pigpio.pi()

        	self.pi.set_servo_pulsewidth(self.esc_pin, 2000)
        	time.sleep(1)
        	self.pi.set_servo_pulsewidth(self.esc_pin, 1000)
        	time.sleep(1)

	def motor_stop(self):
		self.pi.set_servo_pulsewidth(self.esc_pin, 1000)

    	def motor_speed(self, millsec):
		self.pi.set_servo_pulsewidth(self.esc_pin, millsec)

    	def end(self):
		self.pi.stop()
		os.system('sudo killall pigpiod')
