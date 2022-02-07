n = int(input("Enter card number: "))
s = str(n)
x = 0
y = 0
z = 0
doublesum = 0
last_num = 0
test = n
rest = n
everyother = 0
# adding the secong to last and multiplying it by 2 and adding it to doublesum
while test > 0:
    last_num = int(test / 10)
    everyother = int(last_num % 10)
    x = everyother * 2
    if x >= 10:
        x = x % 10
        x += 1
    doublesum += x
    test = int(test / 100)
# adding doublesum to the rest of the lasty digfits only
while rest > 0:
    y = rest % 10
    doublesum += y
    rest = int(rest/100)
# storing what numver is the last number on doublesum when everything is added
z = doublesum % 10
# checking if conditions are true in a card
if z != 0 and len(s) < 12 or len(s) > 16:
    print("INVALID")
elif z == 0 and len(s) > 12:
    if len(s) == 15 and (s[:2] == "34" or s[:2] == "37"):
        print("AMEX")
    elif len(s) == 16 and (s[:2] == "51" or s[:2] == "52" or s[:2] == "53" or s[:2] == "54" or s[:2] == "55"):
        print("MASTERCARD")
    elif (len(s) == 13 or len(s) == 16) and s[0] == "4":
        print("VISA")
    else:        print("INVALID")