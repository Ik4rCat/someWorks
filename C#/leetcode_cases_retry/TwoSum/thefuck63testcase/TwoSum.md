# Two Sum

## Задача

Дан массив целых чисел `nums` и число `target`.  
Найди два числа в массиве, сумма которых равна `target`, и верни их **индексы**.

- Ровно одно решение всегда существует
- Один и тот же элемент нельзя использовать дважды
- Порядок индексов в ответе не важен

### Пример

```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Потому что: nums[0] + nums[1] = 2 + 7 = 9
```

---

## Подходы к решению

### 1. Брутforce — O(n²)

Два вложенных цикла: проверяем все пары.  
Работает, но медленно на больших массивах.

```csharp
for (int i = 0; i < nums.Length - 1; i++)
    for (int j = i + 1; j < nums.Length; j++)
        if (nums[i] + nums[j] == target)
            return new int[] { i, j };
```

### 2. Hash Map — O(n) ✅ Оптимальное решение

Идея: для каждого элемента `nums[i]` вычисляем `complement = target - nums[i]`.  
Если `complement` уже встречался раньше — мы нашли пару.  
Храним уже просмотренные элементы в словаре `{ значение → индекс }`.

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> history = new();

        for (int i = 0; i < nums.Length; i++)
        {
            int complement = target - nums[i];

            if (history.TryGetValue(complement, out int complementIndex))
            {
                return new int[] { i, complementIndex };
            }

            history[nums[i]] = i;
        }

        return null;
    }
}
```

#### Трассировка на примере `nums = [2, 4, 11, 3]`, `target = 6`

| i | nums[i] | complement | history до проверки          | Результат          |
|---|---------|------------|------------------------------|--------------------|
| 0 | 2       | 4          | {}                           | нет → добавляем 2  |
| 1 | 4       | 2          | {2:0}                        | нашли! → [1, 0]    |

#### Почему это быстрее

| Подход    | Время | Память |
|-----------|-------|--------|
| Brute force | O(n²) | O(1) |
| Hash Map  | O(n)  | O(n)  |

Вместо повторного прохода по массиву — мгновенный поиск в словаре за O(1).