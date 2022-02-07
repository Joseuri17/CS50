import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python tournament.py FILENAME")

    dna = []
    dnakeys = []
    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as file:
    # TODO: Read DNA sequence file into a variable
        reader = csv.DictReader(file)
        #adding the information to a list as dicts in dna[]
        for row in reader:
            dna.append(row)
        #adding the names of a key in dnakeys[] as a list
        for key in row.keys():
            dnakeys.append(key)

    #taking name out from keys.
    dnakeys = dnakeys[1:]

    match = []
    # TODO: Find longest match of each STR in DNA sequence
    with open(sys.argv[2], "r") as file:
        text = file.read()
        #looping through the dnakeys
        for i in range(len(dnakeys)):
            #setting dna keys and saving it to a string replaciong it each time.
            dnastring = dnakeys[i]
            #appending count of how many times there was a match from Longtext and the dna string.
            match.append(longest_match(text,dnastring))

    # TODO: Check database for matching profiles

    #taking 0 out from matches.
    match = match[0:]
    #itterating through my dictionary
    for i in range((len(dna))):
        #itterating through my dna keys
        for j in range(len(dnakeys)):
            #is its at the end and it matches print the name who it belongs to
            if j + 1 == len(match) and match[j] == int(dna[i][dnakeys[j]]):
                print(dna[i]["name"])
                return
            #if its any other than the first one do nothing
            elif match[j] == int(dna[i][dnakeys[j]]):
                pass
            #if it dont match break the dna loop and go to the next dict name
            else:
                break
    #if nothing found print no match and return
    print("No Match")
    return

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
