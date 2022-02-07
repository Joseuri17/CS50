import pandas as pd
import numpy as np
mylist = [7,11,13,17]
result = pd.Series(mylist)
print(result)

only100 = pd.Series(100.0)
only100 = only100.repeat(5)
print(only100)

rnums = pd.Series(np.random.randint(0,100,10))
rnums.describe()
print(rnums)

temps = pd.Series([98.6, 98.9, 100.2, 97.9], index = ['Julie', 'Charlie', 'Sam', 'Andrea'])
print(temps)

myDictionary = {'Julie': 98.6, 'Charlie': 98.9, 'Sam': 100.2, 'Andrea': 97.9}
assVal = pd.Series(myDictionary)
print(assVal)