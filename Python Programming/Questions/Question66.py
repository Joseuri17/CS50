def reverse(word):
    if len(word) == 0:
        return ""
    else:
        firstletter = word[0]
        leftover = word[1:]
        return reverse(leftover) + firstletter
print(reverse('flow'))