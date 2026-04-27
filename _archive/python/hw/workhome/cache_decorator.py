from functools import wraps
from typing import Any, Callable, Dict, Tuple


def cache(func: Callable) -> Callable:
    cache_dict: Dict[Tuple, Any] = {}
    
    @wraps(func)
    def wrapper(*args, **kwargs):
        key = (args, tuple(sorted(kwargs.items())))
        
        if key in cache_dict:
            print(f"Результат найден в кэше для аргументов: {args}, {kwargs}")
            return cache_dict[key]
        
        print(f"Вычисляем результат для аргументов: {args}, {kwargs}")
        result = func(*args, **kwargs)
        cache_dict[key] = result
        
        return result
    
    wrapper.cache_clear = lambda: cache_dict.clear()
    wrapper.cache_info = lambda: f"Размер кэша: {len(cache_dict)}"
    
    return wrapper


if __name__ == "__main__":
    import time
    
    @cache
    def slow_fibonacci(n: int) -> int:
        if n <= 1:
            return n
        return slow_fibonacci(n - 1) + slow_fibonacci(n - 2)
    
    @cache
    def slow_calculation(x: int, y: int, operation: str = "add") -> int:
        time.sleep(1)
        
        if operation == "add":
            return x + y
        elif operation == "multiply":
            return x * y
        else:
            return x ** y
    
    print("=== Тест 1: Числа Фибоначчи ===")
    start_time = time.time()
    result1 = slow_fibonacci(10)
    end_time = time.time()
    print(f"Результат: {result1}, время: {end_time - start_time:.4f} сек")
    
    start_time = time.time()
    result2 = slow_fibonacci(10)
    end_time = time.time()
    print(f"Результат: {result2}, время: {end_time - start_time:.4f} сек")
    
    print(f"\nИнформация о кэше: {slow_fibonacci.cache_info()}")
    
    print("\n=== Тест 2: Медленные вычисления ===")
    start_time = time.time()
    result3 = slow_calculation(5, 3, "add")
    end_time = time.time()
    print(f"Результат: {result3}, время: {end_time - start_time:.4f} сек")
    
    start_time = time.time()
    result4 = slow_calculation(5, 3, "add")
    end_time = time.time()
    print(f"Результат: {result4}, время: {end_time - start_time:.4f} сек")
    
    start_time = time.time()
    result5 = slow_calculation(5, 3, "multiply")
    end_time = time.time()
    print(f"Результат: {result5}, время: {end_time - start_time:.4f} сек")
    
    print(f"\nИнформация о кэше: {slow_calculation.cache_info()}")
    
    slow_calculation.cache_clear()
    print(f"После очистки: {slow_calculation.cache_info()}")
