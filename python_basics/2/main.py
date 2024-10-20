from math import sqrt


def main():
    coeffs = input()
    a, b, c = [float(num) for num in coeffs.split()]
    det = b**2 - 4 * a * c
    if det > 0:
        print(f"2 корня: {(-b + sqrt(det)) / 2 * a} {(-b - sqrt(det)) / 2 * a}")
    elif det == 0:
        print(f"1 корень: {-b / 2 * a}")
    else:
        print("Действительных корней нет.")

   
if __name__ == "__main__":
    main()