arr1 = [[2, 4, 6], [8, 10, 12], [14, 16, 18]]
arr2 = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]
for i in range(3):
    for x in range(3):
        arr1[i][x] = arr1[i][x] * arr2[i][x]
print(arr1)