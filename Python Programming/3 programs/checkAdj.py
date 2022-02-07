value = 0
newValue = (input('Enter a value:'))
previousValue = value
while newValue != value:
    if previousValue == newValue:
        print('-- Duplicate input!')
    previousValue = newValue
    newValue = (input('Enter a value:'))
