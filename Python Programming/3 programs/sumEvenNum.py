total = 0
num = 1
while num <= 100:
    if num % 2 == 0:
        print(num)
        total = total + num
    num = num + 1
print('sum of even numbers is: ',total)
