import numpy as np
arr= np.array([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15])
arr=np.reshape(arr, (3, 5))

print("My table would look like\n 1  2  3  4  5\n 6  7  8  9  10\n 11 12 13 14 15\n and columns start from #0\n")
selection = arr[0:3, :]
print("Row 0 is:\n", selection)

selection = arr[:,3:4]
print("column 4 is:\n",selection)

selection =arr[:2,:]
print("rows 0 and 1 are\n",selection)

selection =arr[:,2:5]
print("column 2-4 are\n",selection)


selection =arr[0:2,[0,2,4]]
print("numbers in rows 2-3 and columns 0,2,4\n",selection)