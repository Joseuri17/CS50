import pandas as pd
import matplotlib.pyplot as pp
list = [1, 2, 5, 4, 3, 5, 2, 1, 3, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 5]
mySeries = pd.Series(data=list)
print(mySeries.value_counts(sort=False))
pp.bar([1, 2, 3, 4, 5], mySeries.value_counts(sort=False), 0.5, color=('k', 'r', 'b', 'c', 'g'))
pp.title('Cafeteria Food Ranking')
pp.xlabel('Ranking Level')
pp.ylabel('Counts')
pp.show()
