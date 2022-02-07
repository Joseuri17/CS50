try:
    file = open("numbers.txt","r")
    total = 0
    count = 0
    for line in file:
        try:
            num = float(line.strip())
            total += num
            count += 1
        except ValueError:
            pass
    file.close()
    print("The average of all numbers are", total/count)
except IOError:
    print("numbers.txt not found")