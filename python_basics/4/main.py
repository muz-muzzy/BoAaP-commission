def main():
    nums = [float(num) for num in input().split()]
    print(sum(sorted(nums)[1:-1]))
    

if __name__ == "__main__":
    main()
    