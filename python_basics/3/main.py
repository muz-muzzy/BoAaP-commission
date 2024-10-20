def smallest_divisor(n):
    for i in range(2, n + 1):
        if n % i == 0:
            return i

def main():
    n = int(input())
    if n < 1:
        print("Число должно быть больше 1.")
    else:
        print(smallest_divisor(n))

if __name__ == "__main__":
    main()
