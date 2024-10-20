counters = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

def main():
    num = int(input())
    while num > 0:
        counters[num % 10] += 1
        num //= 10
    print(' '.join(map(str, counters)))


if __name__ == "__main__":
    main()