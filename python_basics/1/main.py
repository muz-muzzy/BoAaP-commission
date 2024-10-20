import sys

# Словарь для хранения вычисленных факториалов (Мемоизация)
factorial_memo = {}

def factorial(n):
    if n in factorial_memo:
        return factorial_memo[n]
    
    result = 1
    for i in range(2, n + 1):
        result *= i
        factorial_memo[i] = result
    
    return result

def main():
    num = int(input('-> '))
    
    # Увеличение максимально допустимой длины int для конвертации 
    sys.set_int_max_str_digits(100_000)
    
    print(f"{num}! = {factorial(num)}")
    
    
if __name__ == "__main__":
    main()


# плюсы этого метода: 
# - оптимизированный по рантайму, вычисление почти моментальное
# - Единственное, что ограничивает размер вычислимого факториала - 
#   лимит длины строки для конвертации в int (можно увеличить через sys.set_int_max_str_digits()).
# - при установленном лимите в 100к символов, скрипт моментально вычисляет факториал 25302 (это максимум)
# - при этом factorial_memo занимает всего 1.31Mb памяти
