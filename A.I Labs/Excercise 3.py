import math
help(math)
help(math.sqrt)

from math import sqrt
print(sqrt(9))

import math as maths
print(maths.sqrt(9))

from math import sqrt as squareroot
print(squareroot(9))

import time
print(time.time())

current_time = time.time()
print(time.ctime(current_time))
print(time.ctime())

print(time.sleep(3))
print(time.sleep(0.5))

import glob
glob.glob("file.py")
glob.glob("*")
glob.glob("*.py")

import random
print(random.randint(1, 10))
print(random.random())
x = [1,2,3,4,5]
random.shuffle(x)
print(x)
x = [1,2,3,4,5]
print(random.sample(x, 2))

