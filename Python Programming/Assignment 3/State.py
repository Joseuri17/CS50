print('Select a temperature value in Celcius or Fahrenheit.' )
print('Press C for Celcius.' )
print('Press F for Fahrenheit.')
degrees = (input('Enter Degree letter'))
temp = int(input('Enter temperatue of water.'))
if degrees == 'F' and temp <= 32:
    print('Solid at', temp, ' Fahrenheit') #Water will turn solid at minimum 32 degress F
elif degrees == 'F' and temp >= 212:
    print('Gaseous at', temp, 'Fahrenheit')  #Water will turn into gas at minimum 212 degress F
elif degrees == 'F' and (temp >= 33 or temp <= 211):
    print('liquid at', temp, 'Degrees Fahrenheit') #Water will stay liquid between 32-312 F
elif degrees == 'C' and temp <= 0:
    print('Solid at', temp, 'Celcius')
elif degrees == 'C' and temp >= 100:
    print('Gaseous at', temp, 'Celcius')
elif degrees == 'C' and (temp >= 1 or temp <= 99):
    print('liquid at', temp, 'Celcius')
else:
    print('Try again')