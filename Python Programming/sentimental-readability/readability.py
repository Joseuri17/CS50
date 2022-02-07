from cs50 import get_string
import re

text = get_string("Text: ")
#number of sentences
s = re.split('[.?!]', text)[:-1]
sentence = len(s)
#number of letters
letters = 0
for i in text:
    if(i.isalpha()):
        letters += 1
#Getting number of words counting the spaces + 1
words = 1 + len(re.findall(" ", text))
#getting average
L = (letters / words) * 100
S = (sentence / words) * 100
#Coleman-Liau formula
index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index > 16:
    print("Grade 16+")
elif index > 1:
    print(f"Grade {index}")
elif index < 1:
    print("Before Grade 1")