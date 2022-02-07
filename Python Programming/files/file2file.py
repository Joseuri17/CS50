def readlist(filename: str):
    file = open(filename, 'r')
    strings = file.readlines()
    file.close()
    return strings


def writefile(strings: list, filename: str):
    file = open(filename, 'w')
    each = 1
    for string in strings:
        file.write('/* ' + str(each) + ' */ ' + string)
        each += 1
    file.close()


inputStrings = readlist("infile.txt")
writefile(inputStrings, "outfile.txt")