import numpy as np

array = np.arange(1,7,1, dtype=int).reshape(2,3)
array2 = np.array([1,2,3])
array3= np.array([4,5,6])
array4 = np.vstack((np.hstack((array2,array2)), np.hstack((array3,array3))))
array4 = np.vstack((array4,array4))
array5 = array4*array4
array6 = np.concatenate((array4, array5), axis=0)

print("1:\n", array)
print("2:\n",array4)
print("3:\n",array5)
print("4:\n",array6)


