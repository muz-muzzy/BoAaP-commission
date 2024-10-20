exc_sdts = set()
athl_sdts = set()


def main():
    with open("excellent_students.txt", 'r', encoding="utf-8") as e:
        for line in e.readlines():
            exc_sdts.add(line.strip())
            
    with open("athlete_students.txt", 'r', encoding="utf-8") as a:
        for line in a.readlines():
            athl_sdts.add(line.strip())
            
    print(' '.join(sorted(exc_sdts & athl_sdts)))
    
    
if __name__ == "__main__":
    main()