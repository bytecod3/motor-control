# imports
import sys, csv, os
from matplotlib import pyplot as plt
from pyfirmata import Arduino, util
from time import sleep
import numpy as np

# board configuration
port = 'COM13'
board = Arduino(port)
sleep(3)

# prevent buffer overflow
it = util.Iterator(board)
it.start()

# assign pin role
a0 = board.get_pin('a:0:i')

# initialize py plot interactive mode
plt.ion()
fig = plt.figure()
plt.title('Real-Time Potentiometer Reading')

i = 0
x = list()
y = list()

while True:
    data = a0.read()
    print(data)
    x.append(i)
    y.append(data)
    plt.scatter(i, float(data), s=25)
    i += 1
    plt.show()
    plt.pause(0.0001)





