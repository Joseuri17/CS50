def search(list, Val):
    for i in range(len(list)):
        if list[i] == Val:
            return True
    return False
#list created here
List = []
for x in range(0,21):
    if x % 2 != 0:
        List.append(x)
print(List)
#Displaying element values.
if search(List, Val = 15):
    print('number 15 index value is 7', )
else:
    print(" ")
if search(List, Val = 25):
    print(" ", List.index(25))
else:
    print("cannot find the element 25")