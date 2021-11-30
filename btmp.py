%matplotlib inline
import numpy as np
import matplotlib.pyplot as plt
import sys
j=50
x=[]
y=[]
for line in open('test.txt','r'):
    i=1
    nums = line.split()
    numbers = []
    for num in nums:
        num = int(num)
        numbers.append(num)
        if num == 255:
            x.append(i)
            y.append(x)
        i+=1
    j-=1
plt.scatter(x, y)
plt.show()
