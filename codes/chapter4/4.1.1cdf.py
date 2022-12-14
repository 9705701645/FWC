import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0,20,50)#points on the x axis
simlen = int(1e7) #number of samples
err = [] #declaring probability list
randvar1 = np.random.normal(0,1,simlen)
randvar2= np.random.normal (0,1,simlen)
for i in range(0,50):
	err_ind = np.nonzero((randvar1)**2+(randvar2)**2 < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

	
plt.plot(x.T,err)#plotting the CDF
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')


	
plt.plot(x.T, err )#,marker='o')#plotting the CDF

plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_V(x)$')

plt.savefig('/home/srinath/figs/4.1.1cdf.pdf')
plt.show()
