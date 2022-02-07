n = int(input("Input a number: "))
sum=0
while n > 0:
    rest = n % 10
    if rest % 2 != 0:
        sum += rest
    n //= 10
print("Sum = ", sum)





