import os
import numpy as np
import matplotlib.pyplot as plt
data1=np.loadtxt("ejercicio28.dat")
data2=np.loadtxt("ejercicio28_sin_friccion.dat")

plt.figure()
plt.plot(data1[:,0], data1[:,1],label="Con fricción")
plt.plot(data2[:,0], data2[:,1],label="Sin fricción")
plt.legend()
plt.savefig("ejercicio28.png")