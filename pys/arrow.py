import numpy as np
import matplotlib.pyplot as plt

v = 50
theta = np.pi/6
g = 9.8
lostEnergy = 5
m = .15
impactPointAltitude = 12
totalEnergy = .5*m*v**2

vix = v*np.cos(theta)
viy = v*np.sin(theta)

t = np.linspace(0,2*viy/g,1000)

x_ideal = vix*t
y_ideal = viy*t - 0.5*g*t**2



plt.plot(x_ideal,y_ideal)
plt.show()