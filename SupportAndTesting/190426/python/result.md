# Тесты BankAccount — 19.04.2026

## Тестируемый модуль
`bank.py` — класс `BankAccount` (депозит, снятие, перевод, история операций)

## Фреймворки
- `pytest` (фикстуры, parametrize, marks, raises)
- `unittest` (альтернативная реализация тех же тестов)

## Покрытые сценарии

| Тест | Описание | Результат |
|------|----------|-----------|
| `test_create_with_default_balance` | Начальный баланс = 0 | ✅ PASSED |
| `test_create_negative_balance_raises` | Отрицательный баланс → ValueError | ✅ PASSED |
| `test_deposit_valid` | Пополнение: 0.01 / 100 / 500 / 1000 / 9999.99 | ✅ PASSED |
| `test_withdraw_invalid_raises` | Снятие больше баланса → ValueError | ✅ PASSED |
| `test_history_records_deposit` | История фиксирует пополнение | ✅ PASSED |
| `test_transfer` | Перевод между счетами | ✅ PASSED |
| `test_transfer_insufficient_raises` | Перевод при нехватке средств → ValueError | ✅ PASSED |

## Запуск

```bash
pytest test_bank_pytest.py -v
python -m unittest test_bank_unittest.py -v
```
