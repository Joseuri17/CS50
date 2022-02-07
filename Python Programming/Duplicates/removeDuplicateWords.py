sentence = input("Type text") #type sentecne
ListofStrings = sentence.split() #space

caps = []
for word in ListofStrings:
    word = str(word).lower()
    caps.append(word)
# .sort this function will put it alphabetical order
caps = list(set(caps))
caps.sort()
#printing the sentence and words
print("sentence:",  sentence)
print("Each word is", f"{caps}")
print("Number of words in the sentence = ", f"{len(caps)}")