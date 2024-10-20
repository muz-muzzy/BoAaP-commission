def main():
    try:
        with open("input.txt", 'r', encoding="utf-16") as i:
            nums = [float(num) for num in i.readline().split()]
            
            if len(nums) > 2:
                sorted_nums = sorted(nums)[1:-1]  
                with open("output.txt", 'w') as o:
                    o.write(' '.join(map(str, sorted_nums)))  
            else:
                with open("output.txt", 'w') as o:
                    o.write('')  
                    
    except FileNotFoundError:
        print("Файл с входными данными не найден.")
    except ValueError:
        print("Файл должен содержать только числа.")

if __name__ == "__main__":
    main()
