phone_book = {}

def main():
    with open("phonebook.txt", 'r', encoding="utf-8") as f:
        for line in f.readlines():
            surname, phone = line.split('\t')
            phone_book[surname.casefold()] = phone.strip()
    
    promt = input("-> ").casefold()
    while promt:
        search_res = phone_book.get(promt)
        print(search_res) if search_res else print("не найдено")
        promt = input("-> ").casefold()
        


if __name__ == "__main__":
    main()