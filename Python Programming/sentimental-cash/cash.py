from cs50 import get_float
change = 0
#checking to see if coins is > 0
while True:
    coins = get_float("Changed owed: ")
    if coins > 0:
        break

coins = coins * 100
while coins >= 25:
    coins -= 25
    change += 1

while coins >= 10:
    coins -= 10
    change += 1

while coins >= 5:
    coins -= 5
    change += 1

while coins > 0:
    coins -= 1
    change += 1
#giving back the number of coins
print(change)

