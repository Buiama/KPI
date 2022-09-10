import functions as f

fileName = "MainFile.dat"
filenameDay = "Day.dat"
filenameNight = "Night.dat"
again = 'y'
ink = 1
counter = 0

while again[0] == 'y' or again[0] == '1' or again[0] == '+':
    if ink == 1:
        again = ''

    counter = f.writeText(fileName, again, counter)

    docText = f.readFile(fileName, counter)
    print("\nFrom Main binary file:")
    f.output(docText, counter)

    dayCounter, nightCounter = f.writeDayNightFile(filenameDay, filenameNight, docText, counter)

    docDay = f.readFile(filenameDay, dayCounter)
    print("\nFrom Day binary file:")
    f.output(docDay, dayCounter)

    docNight = f.readFile(filenameNight, nightCounter)
    print("\nFrom Night binary file:")
    f.output(docNight, nightCounter)

    again = input('\nDo you want to add something to the file? [Y/N]: ').lower()
    ink = 0
