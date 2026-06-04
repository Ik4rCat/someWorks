# Тесты division — 21.04.2026

## Тестируемый модуль
`utils.py` — функция `division(a, b)` — деление двух чисел

## Фреймворк
`pytest` с `parametrize`

## Покрытые сценарии

| Тест | Входные данные | Ожидаемый результат | Результат |
|------|----------------|---------------------|-----------|
| `test_division_params` | 10 / 2 | 5.0 | ✅ PASSED |
| `test_division_params` | 20 / 10 | 2.0 | ✅ PASSED |
| `test_division_params` | 5 / 2 | 2.5 | ✅ PASSED |
| `test_division_params` | 30 / -3 | -10.0 | ✅ PASSED |
| `test_division_raises` | 10 / 0 | ZeroDivisionError | ✅ PASSED |
| `test_division_raises` | 20 / "2" | TypeError | ✅ PASSED |

## Запуск

```bash
pytest test_func.py -v
```
