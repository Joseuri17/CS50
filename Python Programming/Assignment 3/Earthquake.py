value=float(input('Enter the measure of the earthquake. '))
if value >= 8:
    print ('Most stuctures fall')
elif value > 6.99:
    print ('Many buildings destroyed')
elif value > 5.99:
    print('Many buildings considerably damaged, some collapse')
elif value >= 4.5 and value <= 5.99:
    print('Damage to poorly constructed buildings')
else:
    print('No destruction of buildings')