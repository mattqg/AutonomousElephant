# Plays a random sound over bluetooth when digital input
# pin is triggered (pressure sensor)

import time
import random
import RPi.GPIO as GPIO
from pydub import AudioSegment
from pydub.playback import play


input_pin1 = 12
input_pin1 = 15


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(input_pin1, GPIO.IN)
GPIO.setup(input_pin2, GPIO.IN)
mp3Files = ["/home/pi/Desktop/elephantSnort.mp3", "/home/pi/Desktop/elephantGrumble1.mp3",
            "/home/pi/Desktop/elephantGrumble2.mp3", "/home/pi/Desktop/elephantGrumble3.mp3"]


def playRandomSound():
    file = random.choice(mp3Files)
    print(file)
    sound = AudioSegment.from_file(file)
    play(sound)


try:
    while True:
        digitalInput1 = GPIO.input(input_pin1)
        digitalInput2 = GPIO.input(input_pin2)
        print("Digital Input 1:", digialInput1,
              " Digital Input 2:", digialInput2)

        if digitalInput1 or digitalInput2:
            playRandomSound()

        time.sleep(1)

finally:
    GPIO.cleanup()
