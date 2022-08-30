import os
import numpy as np
import matplotlib.pyplot as plt
data1=np.loadtxt("ejercicio28.dat", encoding='UTF-8')
data2=np.loadtxt("ejercicio28_sin_friccion.dat", encoding='UTF-8')



plt.figure()
plt.plot(data1[:,0], data1[:,1],label="friction")
plt.plot(data2[:,0], data2[:,1],label="fricionless")
plt.legend()
plt.savefig("ejercicio28.png")
