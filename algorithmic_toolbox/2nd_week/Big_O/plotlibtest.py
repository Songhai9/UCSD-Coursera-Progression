import numpy as np
import matplotlib.pyplot as plt

n = np.linspace(1, 100)
plt.plot(n, n ** .1, label="n^.1")
plt.plot(n, np.log(n) ** 5, label="(log n)^5")
plt.legend(loc='upper left')
for index in range(1, 20):
    if (np.log(index) ** .1) > (np.log(index) ** 5):
        turning_point = index
        print(turning_point)
        break


plt.show()