import RPi.GPIO as GPIO
import time

# Still in test phase, haven't had a chance to acutally connect to arm yet

servoPINBase = 17					# Change to open servo pin
servoPINUpDown = 18       # Change to pin for up and down movement
servoPINClamp = 19        # Change to pin for the clamping

GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPIN, GPIO.OUT)

p = GPIO.PWM(servoPINBase, 50) 		# GPIO 17 for PWM with 50Hz
p.start(2.5)                      # Initialization
try:
  while True:
    p.ChangeDutyCycle(5)
    time.sleep(0.5)
    p.ChangeDutyCycle(7.5)
    time.sleep(0.5)
    p.ChangeDutyCycle(10)
    time.sleep(0.5)
    p.ChangeDutyCycle(12.5)
    time.sleep(0.5)
    p.ChangeDutyCycle(10)
    time.sleep(0.5)
    p.ChangeDutyCycle(7.5)
    time.sleep(0.5)
    p.ChangeDutyCycle(5)
    time.sleep(0.5)
    p.ChangeDutyCycle(2.5)
    time.sleep(0.5)
	
except KeyboardInterrupt:		# Change this to a specific key input 
  p.stop()
  GPIO.cleanup()
