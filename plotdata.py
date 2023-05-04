import os
import numpy as np
import matplotlib.pyplot as plt
data1=np.loadtxt("friction.dat", encoding='UTF-8')
data2=np.loadtxt("frictionless.dat", encoding='UTF-8')

plt.figure()
plt.title('Effect of air friction in projectile motion')
plt.plot(data1[:,0], data1[:,1],label="friction")
plt.plot(data2[:,0], data2[:,1],label="fricionless")
plt.legend()
plt.savefig("projectile_motion_plot.png")
