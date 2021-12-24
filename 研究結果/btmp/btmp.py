#!/usr/bin/env python
# coding: utf-8

# In[28]:


get_ipython().run_line_magic('matplotlib', 'inline')
import numpy as np
import matplotlib.pyplot as plt
import sys


# In[29]:


j=32
x=np.array([])
y=np.array([])
for line in open('test4.txt','r'):
    i=1
    nums = line.split()
    numbers = []
    for num in nums:
        num = int(num)
        numbers.append(num)
        if num == 255:
            x=np.append(x,i)
            y=np.append(y,j)
        i+=1
    j-=1
def reg1dim(x, y):
    a = np.dot(x, y)/ (x ** 2).sum()
    return a
a = reg1dim(x, y)
plt.plot([x.min(),x.max()], [a*x.min(), a * x.max()],color="k")
plt.scatter(x, y)
slope,intercept=np.polyfit(x,y,1)
print(slope)
print(intercept)
atan = np.arctan(slope)*180/np.pi
print(atan)
plt.show()


# In[ ]:





# In[ ]:




