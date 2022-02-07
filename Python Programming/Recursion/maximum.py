def max2( x, y ):
    if x > y:
        return x
    return y
def max3( x, y, z ):
    return max2( x, max2( y, z ) )
print ("maximum (15, 20, 36)")
print("output is:",max3(15,20,36))
print ("maximum (12,3, 17.8, 1.5)")
print("output is:",max3(3,17.8,1.5))
list = ["apple", "orange", "banana"]
longest_string = max(list, key=len)
print("maximum(‘apple’,‘orange’,’banana’)")
print("output is:",longest_string)