from cs50 import get_int
#declaring a global variable.
j = 1
#checking for only 1-8
while True:
    x = get_int("Height: ")
    if x > 0 and x < 9:
        break

while True:
    #printing the number of spaces(height) - 1
    print(" " * (x-1), end="")
    #printing the number of # starting from top.
    print("#" * j, end="")
    #printing a new space in betgween the pyramid
    print("  ",end="")
    #printing the pyramid from 1 to height
    print("#" * j)

    x -= 1
    j += 1
    #get out of this while loop when x == 0ye
    if x == 0:
        break