#      ******************************************************************
#      *                                                                *
#      *                 Header file for main.py                        *
#      *                                                                *
#      *           Copyright (c) Josh Benson and Pratik Gupta           *
#      *                                                                *
#      ******************************************************************

from pidev.SlaveMaster import SerialMaster, Arduino
from pidev import RPiMIB
import time

# from pidev.Cyprus_Commands import Cyprus_Commands_RPi as cyprus

RPiMIB.openSPI()

a = Arduino(SerialMaster(baud=9600), 17)
# b = Arduino(SerialMaster(baud=115200), 18)

FORMAT_LIST = 0
FORMAT_BYTE = 1
FORMAT_STRING = 2
NO_RESPONSE = 3


def run_arduinos():
    print(a.setStepperSpeed([1, 1] + list((500).to_bytes(2, "little")), format_out=FORMAT_STRING))
    print(a.setStepperSpeed([2, 1] + list((1000).to_bytes(2, "little")), format_out=FORMAT_STRING))
    print(a.setStepperSpeed([3, 1] + list((1500).to_bytes(2, "little")), format_out=FORMAT_STRING))

    # moveStepperToPos Testing Block

    # print(a.moveStepperToPos([1, 1] + list((500).to_bytes(2, "little")), format_out=FORMAT_STRING))
    # print(a.moveStepperToPos([2, 1] + list((500).to_bytes(2, "little")), format_out=FORMAT_STRING))
    # print(a.moveStepperToPos([3, 1] + list((300).to_bytes(2, "little")), format_out=FORMAT_STRING))
    # print(a.moveStepperToPos([4, 1] + list((500).to_bytes(2, "little")), format_out=FORMAT_STRING))
    # print(a.moveStepperToPos([5, 1] + list((0).to_bytes(2, "little")), format_out=FORMAT_STRING))

    # setStepperAcceleration Testing Block
    # print(a.moveStepperRev([1, 1] + list((50).to_bytes(2, "little")), format_out=FORMAT_STRING))
    # print(a.moveStepperRev([2, 1] + list((50).to_bytes(2, "little")), format_out=FORMAT_STRING))
    # print(a.moveStepperRev([3, 1] + list((50).to_bytes(2, "little")), format_out=FORMAT_STRING))
    #  print(a.moveStepper([1, 1] + list((800).to_bytes(2, "little")), format_out=FORMAT_STRING))

    #   time.sleep(2)

    print(a.moveStepperHome([1, 255, 255, 29, 2], format_out=FORMAT_STRING))
    # print(a.moveStepperHome([1, 255, 255, 29, 2], format_out=FORMAT_STRING))

    # print(a.moveStepperHome([1, 1] + list((29).to_bytes(2, "little")), format_out=FORMAT_STRING))

    #  cyprus.setup_servo(1)
    #  while True:
    #       if cyprus.read_gpio() & 0b0001:
    #           sleep(0.05)
    #           if cyprus.read_gpio() & 0b0001:
    #               print("Reading switch")

    #  print(b.moveStepperRev([1, 1] + list((1).to_bytes(2, "little")), format_out=FORMAT_STRING))
    #   print(b.moveStepperRev([2, 1] + list((1).to_bytes(2, "little")), format_out=FORMAT_STRING))

    #  time.sleep(.1)
    #  print(a.moveStepper([2, 1] + list((200).to_bytes(2, "little")), format_out=FORMAT_STRING))
    #   time.sleep(3)
    #   print(a.moveStepper([2, 0] + list((200).to_bytes(2, "little")), format_out=FORMAT_STRING))
    #   time.sleep(3);

    time.sleep(60)

    print(a.disable(format_out=FORMAT_STRING))


run_arduinos()
