from math import sqrt


def main():
    with open("input.txt", 'r', encoding="utf-16") as f:
        nums = [int(num) for num in f.readline().split(',')]
        answer = filter(lambda x: int(sqrt(x)) ** 2 == x, nums)
        print(' '.join(map(str, answer)))
        

if __name__ == "__main__":
    main()