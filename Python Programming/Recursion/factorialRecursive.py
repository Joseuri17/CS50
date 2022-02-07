def factorial(n):
   if n == 1: # this will be one only.
       return n
   else:
       return n*factorial(n-1)  #do formula


num = int(input("Input a number: "))
if num < 0:
   print("cannot do negative numbers")
elif num == 0:
   print("Factorial of 0 is 1")
else:
   pri1nt("Factorial of", num, "is", factorial(num))