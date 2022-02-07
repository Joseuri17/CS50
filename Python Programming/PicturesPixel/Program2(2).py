import pandas as pd
Dictionary={'Maxine':[23, 54, 67], 'James':[23, 56, 89], 'Amanda':[56, 43,24]}
temparatures=pd.DataFrame(Dictionary)
print(temparatures)
print("\n\n")
temparatures=pd.DataFrame(Dictionary,index=["Morning", "Afternoon", "Evening"])
print(temparatures)
print("\n\n")
selection=temparatures[["Maxine"]]
print('selection:', selection)
print("\n\n")
column = temparatures.loc[["Morning"],:]
print(column)
print("\n\n")
rows=temparatures.loc[["Morning","Evening"],:]
print(rows)
print("\n\n")
aandM= temparatures[["Amanda"]].loc[["Morning"],:]
print(aandM)
print("\n\n")
morandaft=temparatures[["Amanda", "Maxine"]].loc[["Morning", "Afternoon"]]
print(morandaft)
print("\n\n")
describe = temparatures.describe()
print(describe)
print("\n\n")
transTemp = temparatures.transpose()
print(transTemp)
print("\n\n")
sorting=temparatures.reindex(sorted(temparatures.columns),axis=1)
print(sorting)