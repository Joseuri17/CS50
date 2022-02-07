word = input("Enter word:")

#A)
def uppercase(word) :
    for i in word:
     if i.isupper():
        print("the upper case letters in the word are",i)

#B)
def everysecond(word) :
    s = len(word)
    for i in range(1,s,2):
        print("The second letter is", word[i])

#C)
def vowels(word) :
    vowels = ["a" , "e" , "i", "o", "u"]
    for i in word:
        if i in vowels:
            print("The vowels on the word are", i)

#D
def digits(word):
    nums = 0
    for i in word:
        if i.isdigit():
            nums +=1
            print("The number of digits in the string is", {nums})
#E
def position(word):
    vowels = ["a", "e", "i", "o", "u"]
    s = len(word)
    for i in range(s):
        if word[i] in vowels:
            print("The position vowels in the word are", word[i],i)

# We call our Functions

uppercase(word)
everysecond(word)
vowels(word)
digits(word)
position(word)
