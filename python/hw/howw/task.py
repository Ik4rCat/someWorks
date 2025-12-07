# 1. Линейный поиск
def linear_search(arr, target):
    """
    Проходит по массиву и ищет нужный элемент.
    Возвращает индекс найденного элемента или -1, если элемент не найден.
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


# 2. Поиск с барьером
def search_with_sentinel(arr, target):
    """
    Упрощённый линейный поиск с использованием барьера.
    Барьер позволяет убрать проверку границ массива в цикле.
    """
    n = len(arr)
    # Запоминаем последний элемент перед заменой
    last_element = arr[-1]
    # Ставим барьер на место последнего элемента
    arr[-1] = target
    
    i = 0
    while arr[i] != target:
        i += 1
    
    # Возвращаем исходный последний элемент
    arr[-1] = last_element
    
    # Проверяем, нашли ли мы элемент или это был барьер
    if i < n - 1 or arr[n - 1] == target:
        return i
    return -1


# 3. Бинарный поиск
def binary_search(arr, target):
    """
    Ищет элемент в отсортированном массиве, деля область поиска пополам.
    Работает только с отсортированными массивами.
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        middle = (left + right) // 2
        
        if arr[middle] == target:
            return middle
        elif arr[middle] < target:
            left = middle + 1
        else:
            right = middle - 1
    
    return -1


# Рекурсивная версия бинарного поиска
def binary_search_recursive(arr, target, left=0, right=None):
    """
    Рекурсивная реализация бинарного поиска.
    """
    if right is None:
        right = len(arr) - 1
    
    if left > right:
        return -1
    
    middle = (left + right) // 2
    
    if arr[middle] == target:
        return middle
    elif arr[middle] < target:
        return binary_search_recursive(arr, target, middle + 1, right)
    else:
        return binary_search_recursive(arr, target, left, middle - 1)


# 4. Интерполяционный поиск
def interpolation_search(arr, target):
    """
    Улучшенный бинарный поиск для равномерно распределённых данных.
    Использует интерполяцию для более точного определения позиции элемента.
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right and target >= arr[left] and target <= arr[right]:
        # Если все элементы одинаковы
        if arr[right] == arr[left]:
            if arr[left] == target:
                return left
            return -1
        
        # Вычисляем примерную позицию через интерполяцию
        pos = left + int(((target - arr[left]) * (right - left)) / (arr[right] - arr[left]))
        
        if arr[pos] == target:
            return pos
        elif arr[pos] < target:
            left = pos + 1
        else:
            right = pos - 1
    
    return -1


# 5. Следящий поиск
class HuntSearch:
    """
    Класс для следящего поиска, который запоминает последнюю найденную позицию
    и использует её для ускорения следующих поисков.
    """
    
    def __init__(self, arr):
        self.arr = arr
        self.last_index = 0
    
    def binary_hunt_search(self, target):
        """
        Умный поиск, который использует предыдущий результат.
        Если новый элемент близок к предыдущему, использует оптимизированный поиск.
        """
        # Проверяем, близок ли новый элемент к предыдущему найденному
        if (self.last_index > 0 and
            abs(self.arr[self.last_index] - target) < len(self.arr)**0.5):
            
            # Выбираем направление поиска
            if target < self.arr[self.last_index]:
                return self._hunt_left(target)
            else:
                return self._hunt_right(target)
        else:
            # Используем обычный бинарный поиск
            result = binary_search(self.arr, target)
            if result != -1:
                self.last_index = result
            return result
    
    def _hunt_left(self, target):
        """
        Ищет элемент слева от последней найденной позиции.
        Сначала быстро расширяет область поиска, затем использует бинарный поиск.
        """
        min_idx = self.last_index
        step = 1
        
        # Быстро расширяем область поиска влево
        while min_idx >= 0 and self.arr[min_idx] > target:
            min_idx -= step
            step *= 2
        
        # Убеждаемся, что не вышли за границы
        min_idx = max(0, min_idx)
        
        # Теперь делаем точный бинарный поиск в найденной области
        left = min_idx
        right = min(min_idx + step // 2, len(self.arr) - 1)
        
        while left <= right:
            middle = (left + right) // 2
            if self.arr[middle] == target:
                self.last_index = middle
                return middle
            elif self.arr[middle] < target:
                left = middle + 1
            else:
                right = middle - 1
        
        return -1
    
    def _hunt_right(self, target):
        """
        Ищет элемент справа от последней найденной позиции.
        Сначала быстро расширяет область поиска, затем использует бинарный поиск.
        """
        max_idx = self.last_index
        step = 1
        n = len(self.arr)
        
        # Быстро расширяем область поиска вправо
        while max_idx < n and self.arr[max_idx] < target:
            max_idx += step
            step *= 2
        
        # Убеждаемся, что не вышли за границы
        max_idx = min(max_idx, n - 1)
        
        # Делаем точный бинарный поиск в найденной области
        left = max(0, max_idx - step // 2)
        right = max_idx
        
        while left <= right:
            middle = (left + right) // 2
            if self.arr[middle] == target:
                self.last_index = middle
                return middle
            elif self.arr[middle] < target:
                left = middle + 1
            else:
                right = middle - 1
        
        return -1
