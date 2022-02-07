def Fahrenheit(C):
    return (9.0/5) * C + 32
for x in range(90,101):
    print(x," ",round(Fahrenheit(x),1)) #The round function will round the double int