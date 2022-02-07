temps = {"Mon": [66, 70, 74], "Tue": [50, 56, 64], "Wed": [75, 80, 83], "Thu": [67, 74, 81]} #data
avg = {days: round(sum(temps[days])/len(temps[days]), 2) for days in temps}#dictionary
for days in avg:
    print(f"{days}","{0:.2f}".format(avg[days])) #output using the floating points