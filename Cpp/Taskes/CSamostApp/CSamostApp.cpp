#include <algorithm>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

using namespace std;

/// Этот файл содержит решения 26 учебных задач по вводу/выводу,
/// массивам и простым алгоритмам, распределённым по функциям TaskI...TaskXXVI.
/// Каждая функция реализует отдельную задачу и может быть вызвана из главного меню.

/// Текущий год, используемый для расчёта возраста в TaskI.
constexpr int CURRENT_YEAR = 2025;

void TaskI() {

/// Задача 1: Приветствие и возраст.
/// 
/// Программа запрашивает у пользователя год рождения и имя,
/// вычисляет возраст на основе текущего года (CURRENT_YEAR) и выводит приветствие.
/// 
/// Алгоритм:
/// 1. Запрашиваем год рождения (целое число)
/// 2. Запрашиваем имя (строка, может содержать пробелы)
/// 3. Вычисляем возраст: CURRENT_YEAR - birthYear
/// 4. Выводим приветствие с именем и возрастом

	int birthYear = 0;
	string name;

	cout << "Enter your birth year: ";
	cin >> birthYear;
	cout << "Enter your name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);

	int age = CURRENT_YEAR - birthYear;
	cout << "Hello, " << name << "! You are " << age << " years old." << endl;
}

void TaskII() {

/// Задача 2: Конвертер валют.
/// 
/// Программа конвертирует сумму из рублей в доллары по заданному курсу.
/// 
/// Алгоритм:
/// 1. Запрашиваем сумму в рублях (вещественное число)
/// 2. Запрашиваем курс доллара (рублей за 1 USD)
/// 3. Проверяем, что курс положительный (защита от деления на ноль и отрицательных значений)
/// 4. Вычисляем сумму в долларах: rubles / dollarRate
/// 5. Выводим результат

	double rubles = 0.0;
	double dollarRate = 0.0;

	cout << "Enter the amount in rubles: ";
	cin >> rubles;
	cout << "Enter the USD rate (rubles per 1 USD): ";
	cin >> dollarRate;

	if (dollarRate <= 0.0) {
		cout << "The USD rate must be positive." << endl;
		return;
	}

	double dollars = rubles / dollarRate;
	cout << "Equivalent amount in USD: " << dollars << endl;
}


void TaskIII() {

/// Задача 3: Периметр и площадь прямоугольника.
/// 
/// Программа вычисляет периметр и площадь прямоугольника по заданным длине и ширине.
/// 
/// Алгоритм:
/// 1. Запрашиваем длину прямоугольника (вещественное число)
/// 2. Запрашиваем ширину прямоугольника (вещественное число)
/// 3. Вычисляем периметр: 2 * (length + width)
/// 4. Вычисляем площадь: length * width
/// 5. Выводим оба результата

	double length = 0.0;
	double width = 0.0;

	cout << "Enter rectangle length: ";
	cin >> length;
	cout << "Enter rectangle width: ";
	cin >> width;

	double perimeter = 2 * (length + width);
	double area = length * width;

	cout << "Perimeter: " << perimeter << endl;
	cout << "Area: " << area << endl;
}

void TaskIV() {

/// Задача 4: Определение чётности числа.
/// 
/// Программа определяет, является ли введённое число чётным или нечётным.
/// 
/// Алгоритм:
/// 1. Запрашиваем целое число (используем long long для больших значений)
/// 2. Проверяем остаток от деления на 2: value % 2
/// 3. Если остаток равен 0 - число чётное, иначе - нечётное
/// 4. Выводим результат

	long long value = 0;
	cout << "Enter an integer: ";
	cin >> value;

	if (value % 2 == 0) {
		cout << "The number is even." << endl;
	}
	else {
		cout << "The number is odd." << endl;
	}
}

void TaskV() {

/// Задача 5: Упрощённый калькулятор.
/// 
/// Программа выполняет арифметические операции (+, -, *, /) над двумя числами.
/// 
/// Алгоритм:
/// 1. Запрашиваем первое число (вещественное)
/// 2. Запрашиваем второе число (вещественное)
/// 3. Запрашиваем символ операции (+, -, *, /)
/// 4. Используем switch для выбора операции
/// 5. Для деления проверяем деление на ноль
/// 6. Выводим результат или сообщение об ошибке

	double a = 0.0;
	double b = 0.0;
	char op = '+';

	cout << "Enter the first number: ";
	cin >> a;
	cout << "Enter the second number: ";
	cin >> b;
	cout << "Enter an operation (+, -, *, /): ";
	cin >> op;

	switch (op) {
	case '+':
		cout << "Result: " << a + b << endl;
		break;
	case '-':
		cout << "Result: " << a - b << endl;
		break;
	case '*':
		cout << "Result: " << a * b << endl;
		break;
	case '/':
		if (b == 0.0) {
			cout << "Error: division by zero." << endl;
		}
		else {
			cout << "Result: " << a / b << endl;
		}
		break;
	default:
		cout << "Unknown operation." << endl;
		break;
	}
}

void TaskVI() {

/// Задача 6: Поиск максимума из трёх чисел.
/// 
/// Программа находит наибольшее из трёх введённых целых чисел.
/// 
/// Алгоритм:
/// 1. Запрашиваем три целых числа
/// 2. Используем функцию max() из библиотеки <algorithm> с initializer_list
/// 3. Выводим наибольшее число

	int a = 0, b = 0, c = 0;
	cout << "Enter three integers: ";
	cin >> a >> b >> c;

	int maximum = max({ a, b, c });
	cout << "The largest number is: " << maximum << endl;
}

void TaskVII() {

/// Задача 7: Проверка года на високосность.
/// 
/// Программа определяет, является ли введённый год високосным.
/// 
/// Правило високосного года:
/// - Год високосный, если он кратен 4, но не кратен 100
/// - ИЛИ если он кратен 400
/// 
/// Алгоритм:
/// 1. Запрашиваем год (целое число)
/// 2. Проверяем условие: (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
/// 3. Выводим результат

	int year = 0;
	cout << "Enter a year: ";
	cin >> year;

	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	cout << (isLeap ? "The year is leap." : "The year is not leap.") << endl;
}

void TaskVIII() {

/// Задача 8: Сумматор чисел.
/// 
/// Программа суммирует введённые числа до тех пор, пока не будет введён 0.
/// 
/// Алгоритм:
/// 1. Инициализируем переменную sum = 0
/// 2. В цикле while читаем числа из потока ввода
/// 3. Условие цикла: cin >> value && value != 0
///    (продолжаем, пока ввод успешен и число не равно 0)
/// 4. На каждой итерации добавляем значение к сумме
/// 5. После завершения цикла выводим итоговую сумму

	long long sum = 0;
	long long value = 0;

	cout << "Enter numbers (0 to stop):" << endl;
	while (cin >> value && value != 0) {
		sum += value;
	}
	cout << "Total sum: " << sum << endl;
}

void TaskIX() {

/// Задача 9: Таблица умножения.
/// 
/// Программа выводит таблицу умножения для заданного числа от 1 до 10.
/// 
/// Алгоритм:
/// 1. Запрашиваем число N
/// 2. В цикле for от 1 до 10 выводим произведение N * i
/// 3. Формат вывода: "N x i = результат"

	int n = 0;
	cout << "Enter a number for its multiplication table: ";
	cin >> n;

	for (int i = 1; i <= 10; ++i) {
		cout << n << " x " << i << " = " << n * i << endl;
	}
}

void TaskX() {

/// Задача 10: Обратный отсчёт.
/// 
/// Программа ведёт обратный отсчёт от введённого числа до 1, затем выводит "Start!".
/// 
/// Алгоритм:
/// 1. Запрашиваем положительное целое число
/// 2. Проверяем, что число положительное (n > 0)
/// 3. В цикле for от n до 1 (с шагом -1) выводим текущее значение
/// 4. После завершения цикла выводим "Start!"

	int n = 0;
	cout << "Enter a positive integer for a countdown: ";
	cin >> n;

	if (n <= 0) {
		cout << "The number must be positive." << endl;
		return;
	}

	for (int i = n; i >= 1; --i) {
		cout << i << endl;
	}
	cout << "Start!" << endl;
}


void TaskXI() {

/// Задача 11: Поиск делителей числа.
/// 
/// Программа находит и выводит все делители введённого числа.
/// 
/// Алгоритм:
/// 1. Запрашиваем целое число
/// 2. Проверяем случай n == 0 (у нуля бесконечно много делителей)
/// 3. Для ненулевого числа находим модуль числа (abs(n))
/// 4. В цикле от 1 до модуля числа проверяем, делится ли число на i без остатка
/// 5. Если n % i == 0, то i является делителем - выводим его
/// 6. Выводим все найденные делители

	int n = 0;
	cout << "Enter an integer to list its divisors: ";
	cin >> n;

	if (n == 0) {
		cout << "Zero has infinitely many divisors." << endl;
		return;
	}

	cout << "Divisors of " << n << ": ";
	int limit = static_cast<int>(abs(n));
	for (int i = 1; i <= limit; ++i) {
		if (n % i == 0) {
			cout << i << " ";
		}
	}
	cout << endl;
}

void TaskXII() {

/// Задача 12: Вычисление факториала.
/// 
/// Программа вычисляет факториал числа N (N! = 1 * 2 * 3 * ... * N).
/// 
/// Алгоритм:
/// 1. Запрашиваем число N
/// 2. Проверяем, что N >= 0 (факториал определён только для неотрицательных чисел)
/// 3. Инициализируем result = 1
/// 4. В цикле от 2 до N умножаем result на текущее значение i
/// 5. Выводим результат
/// 
/// Примечание: используется unsigned long long для больших значений факториала

	int n = 0;
	cout << "Enter a number to compute its factorial: ";
	cin >> n;

	if (n < 0) {
		cout << "Factorial is defined only for non-negative integers." << endl;
		return;
	}

	unsigned long long result = 1;
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	cout << "Factorial of " << n << " is " << result << endl;
}

void TaskXIII() {

/// Задача 13: Сумма и среднее арифметическое.
/// 
/// Программа вычисляет сумму и среднее арифметическое для массива из 5 целых чисел.
/// 
/// Алгоритм:
/// 1. Создаём вектор из 5 элементов
/// 2. Запрашиваем у пользователя 5 целых чисел и заполняем вектор
/// 3. Вычисляем сумму всех элементов (используем long long для больших сумм)
/// 4. Вычисляем среднее арифметическое: sum / количество_элементов
/// 5. Выводим сумму и среднее арифметическое

	vector<int> numbers(5);
	cout << "Enter 5 integers:" << endl;
	for (int& num : numbers) {
		cin >> num;
	}

	long long sum = 0;
	for (int num : numbers) {
		sum += num;
	}
	double average = static_cast<double>(sum) / numbers.size();

	cout << "Sum: " << sum << endl;
	cout << "Average: " << average << endl;
}

void TaskXIV() {

/// Задача 14: Поиск максимума и минимума в массиве.
/// 
/// Программа находит минимальный и максимальный элементы в массиве из 10 чисел.
/// 
/// Алгоритм:
/// 1. Создаём вектор из 10 элементов
/// 2. Запрашиваем у пользователя 10 чисел и заполняем вектор
/// 3. Используем функцию minmax_element() из библиотеки <algorithm>
///    для одновременного поиска минимума и максимума
/// 4. Функция возвращает пару итераторов (minIt, maxIt)
/// 5. Выводим значения по этим итераторам

	vector<int> numbers(10);
	cout << "Enter 10 integers:" << endl;
	for (int& num : numbers) {
		cin >> num;
	}

	pair<vector<int>::iterator, vector<int>::iterator> result = minmax_element(numbers.begin(), numbers.end());
	cout << "Minimum: " << *(result.first) << endl;
	cout << "Maximum: " << *(result.second) << endl;
}

///

void TaskXV() {

/// Задача 15: Вывод массива в обратном порядке.
/// 
/// Программа выводит элементы массива в обратном порядке без изменения самого массива.
/// 
/// Алгоритм:
/// 1. Запрашиваем количество элементов массива
/// 2. Проверяем, что размер положительный
/// 3. Создаём вектор заданного размера
/// 4. Запрашиваем элементы массива и заполняем вектор
/// 5. Используем обратные итераторы (rbegin, rend) для вывода элементов
///    в обратном порядке без изменения исходного массива

	int n = 0;
	cout << "Enter array length: ";
	cin >> n;

	if (n <= 0) {
		cout << "Length must be positive." << endl;
		return;
	}

	vector<int> data(n);
	cout << "Enter array elements:" << endl;
	for (int& value : data) {
		cin >> value;
	}

	cout << "Elements in reverse order: ";
	for (auto it = data.rbegin(); it != data.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}


void TaskXVI() {

/// Задача 16: Поиск элемента в массиве.
/// 
/// Программа проверяет, есть ли введённое число в заранее заданном массиве.
/// 
/// Алгоритм:
/// 1. Создаём константный вектор с предопределёнными значениями
/// 2. Выводим элементы массива для информации
/// 3. Запрашиваем число для поиска
/// 4. Используем функцию find() из библиотеки <algorithm> для поиска элемента
/// 5. Если find() возвращает итератор, не равный end(), элемент найден
/// 6. Выводим результат: "Found." или "Not found."

	const vector<int> preset{ 3, 7, 15, 23, 42, 56, 78, 99 };
	int target = 0;

	cout << "Preset array: ";
	for (int value : preset) {
		cout << value << " ";
	}
	cout << endl;

	cout << "Enter a number to search: ";
	cin >> target;

	bool found = find(preset.begin(), preset.end(), target) != preset.end();
	cout << (found ? "Found." : "Not found.") << endl;
}

void TaskXVII() {

/// Задача 17: Подсчёт количества чётных элементов в массиве.
/// 
/// Программа подсчитывает, сколько чётных чисел содержится в массиве.
/// 
/// Алгоритм:
/// 1. Запрашиваем количество элементов массива
/// 2. Проверяем, что размер положительный
/// 3. Создаём вектор заданного размера
/// 4. Запрашиваем элементы массива и заполняем вектор
/// 5. Инициализируем счётчик чётных элементов (evenCount = 0)
/// 6. Проходим по всем элементам массива
/// 7. Если элемент делится на 2 без остатка (value % 2 == 0), увеличиваем счётчик
/// 8. Выводим количество чётных элементов

	int n = 0;
	cout << "Enter the number of elements: ";
	cin >> n;

	if (n <= 0) {
		cout << "The count must be positive." << endl;
		return;
	}

	vector<int> data(n);
	cout << "Enter the elements:" << endl;
	for (int& value : data) {
		cin >> value;
	}

	int evenCount = 0;
	for (int value : data) {
		if (value % 2 == 0) {
			++evenCount;
		}
	}

	cout << "Even elements: " << evenCount << endl;
}

void TaskXVIII() {

/// Задача 18: Проверка числа на простоту.
/// 
/// Программа определяет, является ли введённое число простым.
/// Простое число - это число, которое делится без остатка только на 1 и на само себя.
/// 
/// Алгоритм:
/// 1. Запрашиваем число для проверки
/// 2. Если n <= 1, число не является простым
/// 3. Проверяем делители от 2 до sqrt(n) (оптимизация: i * i <= n)
/// 4. Если найдётся делитель, число составное - выходим из функции
/// 5. Если делителей не найдено, число простое
/// 
/// Примечание: проверка до sqrt(n) достаточна, так как если есть делитель больше sqrt(n),
/// то обязательно есть и делитель меньше sqrt(n)

	int n = 0;
	cout << "Enter an integer to test for primality: ";
	cin >> n;

	if (n <= 1) {
		cout << "The number is not prime." << endl;
		return;
	}

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			cout << "The number is composite." << endl;
			return;
		}
	}
	cout << "The number is prime." << endl;
}


void TaskXIX() {

/// Задача 19: Реверс массива "на месте".
/// 
/// Программа разворачивает массив без использования дополнительного массива,
/// меняя местами элементы: первый с последним, второй с предпоследним и т.д.
/// 
/// Алгоритм:
/// 1. Запрашиваем размер массива
/// 2. Проверяем, что размер положительный
/// 3. Создаём вектор и заполняем его элементами
/// 4. Используем два индекса: i (начало) и j (конец)
/// 5. В цикле меняем местами элементы data[i] и data[j]
/// 6. Увеличиваем i и уменьшаем j, пока i < j
/// 7. Выводим массив после реверса

	int n = 0;
	cout << "Enter array size: ";
	cin >> n;

	if (n <= 0) {
		cout << "Size must be positive." << endl;
		return;
	}

	vector<int> data(n);
	cout << "Enter the elements:" << endl;
	for (int& value : data) {
		cin >> value;
	}

	for (int i = 0, j = n - 1; i < j; ++i, --j) {
		swap(data[i], data[j]);
	}

	cout << "Array after in-place reverse: ";
	for (int value : data) {
		cout << value << " ";
	}
	cout << endl;
}


void TaskXX() {

/// Задача 20: Сортировка пузырьком.
/// 
/// Программа сортирует массив целых чисел по возрастанию, используя алгоритм пузырьковой сортировки.
/// 
/// Алгоритм пузырьковой сортировки:
/// 1. Внешний цикл проходит n-1 раз (количество проходов)
/// 2. Внутренний цикл сравнивает соседние элементы
/// 3. Если data[j] > data[j+1], элементы меняются местами
/// 4. После каждого прохода внешнего цикла наибольший элемент "всплывает" в конец
/// 5. Оптимизация: внутренний цикл проходит до n-i-1, так как последние i элементов уже отсортированы
/// 
/// Шаги выполнения:
/// 1. Запрашиваем размер массива и заполняем его
/// 2. Выводим массив до сортировки
/// 3. Выполняем сортировку пузырьком
/// 4. Выводим массив после сортировки

	int n = 0;
	cout << "Enter array size: ";
	cin >> n;

	if (n <= 0) {
		cout << "Size must be positive." << endl;
		return;
	}

	vector<int> data(n);
	cout << "Enter the elements:" << endl;
	for (int& value : data) {
		cin >> value;
	}

	cout << "Before sorting: ";
	for (int value : data) {
		cout << value << " ";
	}
	cout << endl;

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]);
			}
		}
	}

	cout << "After bubble sort: ";
	for (int value : data) {
		cout << value << " ";
	}
	cout << endl;
}


void TaskXXI() {

/// Задача 21: Частотный анализ символов.
/// 
/// Программа подсчитывает, сколько раз каждый символ встречается в введённой строке.
/// 
/// Алгоритм:
/// 1. Запрашиваем строку (используем getline для строк с пробелами)
/// 2. Используем map<char, int> для хранения частоты каждого символа
/// 3. Проходим по каждому символу строки
/// 4. Для каждого символа увеличиваем счётчик в map (++freq[ch])
/// 5. Выводим все символы и их частоты в алфавитном порядке
///    (map автоматически сортирует ключи)

	cout << "Enter a string for frequency analysis: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string text;
	getline(cin, text);

	map<char, int> freq;
	for (char ch : text) {
		++freq[ch];
	}

	cout << "Character frequencies:" << endl;
	for (map<char, int>::const_iterator it = freq.begin(); it != freq.end(); ++it) {
		cout << "'" << it->first << "': " << it->second << endl;
	}
}


void TaskXXII() {

/// Задача 22: Числа Фибоначчи.
/// 
/// Программа выводит первые N чисел последовательности Фибоначчи.
/// Последовательность Фибоначчи: каждое следующее число является суммой двух предыдущих.
/// Начало: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
/// 
/// Алгоритм:
/// 1. Запрашиваем количество чисел N
/// 2. Проверяем, что N > 0
/// 3. Инициализируем два переменные: a = 0 (первое число), b = 1 (второе число)
/// 4. В цикле от 0 до N-1:
///    - Выводим текущее значение a
///    - Вычисляем следующее число: next = a + b
///    - Обновляем: a = b, b = next
/// 5. Выводим последовательность

	int n = 0;
	cout << "Enter how many Fibonacci numbers to print: ";
	cin >> n;

	if (n <= 0) {
		cout << "The amount must be positive." << endl;
		return;
	}

	long long a = 0;
	long long b = 1;

	cout << "Sequence: ";
	for (int i = 0; i < n; ++i) {
		cout << a << " ";
		long long next = a + b;
		a = b;
		b = next;
	}
	cout << endl;
}


void TaskXXIII() {

/// Задача 23: Игра "Угадай число" с ограниченным числом попыток.
/// 
/// Программа загадывает случайное число от 1 до 100, а пользователь пытается его угадать.
/// После каждой попытки программа даёт подсказку "Higher" или "Lower".
/// 
/// Алгоритм:
/// 1. Запрашиваем количество попыток K
/// 2. Проверяем, что K > 0
/// 3. Генерируем случайное число от 1 до 100 с помощью rand()
/// 4. В цикле от 1 до K:
///    - Запрашиваем предположение пользователя
///    - Если угадали - поздравляем и выходим из функции
///    - Если число меньше загаданного - выводим "Higher"
///    - Если число больше загаданного - выводим "Lower"
/// 5. Если попытки закончились - выводим загаданное число

	int attempts = 0;
	cout << "Enter the number of attempts: ";
	cin >> attempts;

	if (attempts <= 0) {
		cout << "Attempts must be positive." << endl;
		return;
	}

	int secret = rand() % 100 + 1;

	for (int i = 1; i <= attempts; ++i) {
		int guess = 0;
		cout << "Attempt " << i << ": ";
		cin >> guess;

		if (guess == secret) {
			cout << "Congratulations! You guessed the number." << endl;
			return;
		}
		if (guess < secret) {
			cout << "Higher." << endl;
		}
		else {
			cout << "Lower." << endl;
		}
	}

	cout << "Out of attempts. The number was " << secret << "." << endl;
}


void TaskXXIV() {

/// Задача 24: Шифр Цезаря (упрощённый).
/// 
/// Программа шифрует строку, заменяя каждую строчную букву английского алфавита
/// на букву, стоящую в алфавите на ключ позиций дальше.
/// После 'z' следует 'a' (циклический сдвиг).
/// 
/// Алгоритм:
/// 1. Запрашиваем строку для шифрования (используем getline)
/// 2. Запрашиваем ключ (сдвиг)
/// 3. Нормализуем ключ: ((key % 26) + 26) % 26
///    Это обеспечивает корректную работу с отрицательными ключами
///    и ключами больше 26 (приводим к диапазону 0-25)
/// 4. Проходим по каждому символу строки
/// 5. Если символ - строчная буква ('a'-'z'):
///    - Вычисляем новую позицию: (ch - 'a' + shift) % 26
///    - Заменяем символ: 'a' + новая_позиция
/// 6. Остальные символы остаются без изменений
/// 7. Выводим зашифрованную строку

	cout << "Enter a string to encrypt: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string text;
	getline(cin, text);

	int key = 0;
	cout << "Enter the shift value: ";
	cin >> key;

	int shift = ((key % 26) + 26) % 26;

	for (char& ch : text) {
		if (ch >= 'a' && ch <= 'z') {
			ch = static_cast<char>('a' + (ch - 'a' + shift) % 26);
		}
	}

	cout << "Encrypted text: " << text << endl;
}


void TaskXXV() {

/// Задача 25: Построение графика функции y = x^2 в консоли.
/// 
/// Программа строит простой текстовый график функции y = x^2 для x в диапазоне от -N до N.
/// 
/// Алгоритм:
/// 1. Запрашиваем N (положительное число)
/// 2. Проверяем, что N > 0
/// 3. В цикле от -N до N:
///    - Вычисляем y = x * x
///    - Выводим "x= " с выравниванием (добавляем пробел для положительных x)
///    - Выводим пробелы в количестве y (визуализация расстояния от оси x)
///    - Выводим символ '*' и значение y в скобках
/// 4. Каждая строка представляет одну точку графика
/// 
/// Примечание: график строится горизонтально, где количество пробелов
/// перед '*' пропорционально значению y

	int n = 0;
	cout << "Enter N to plot y = x^2 for x in [-N, N]: ";
	cin >> n;

	if (n <= 0) {
		cout << "N must be positive." << endl;
		return;
	}

	cout << "Plot:" << endl;
	for (int x = -n; x <= n; ++x) {
		int y = x * x;
		cout << "x=" << (x >= 0 ? " " : "") << x << " ";
		for (int i = 0; i < y; ++i) {
			cout << ' ';
		}
		cout << "* (y=" << y << ")" << endl;
	}
}

void TaskXXVI() {

/// Задача 26: Симулятор броска монеты.
/// 
/// Программа симулирует серию бросков монеты и выводит результаты каждого броска,
/// а также итоговую статистику (количество орлов и решек).
/// 
/// Алгоритм:
/// 1. Запрашиваем количество бросков
/// 2. Проверяем, что количество > 0
/// 3. Используем rand() для генерации 0 (tails) или 1 (heads)
/// 4. Инициализируем счётчики: heads = 0, tails = 0
/// 5. В цикле от 1 до количества бросков:
///    - Генерируем случайное значение (0 или 1)
///    - Если 1 - орёл, увеличиваем heads и выводим "Heads"
///    - Если 0 - решка, увеличиваем tails и выводим "Tails"
/// 6. После всех бросков выводим итоговую статистику

	int tosses = 0;
	cout << "How many coin tosses? ";
	cin >> tosses;

	if (tosses <= 0) {
		cout << "The number of tosses must be positive." << endl;
		return;
	}

	int heads = 0;
	int tails = 0;

	for (int i = 1; i <= tosses; ++i) {
		bool isHeads = (rand() % 2) == 1;
		if (isHeads) {
			++heads;
			cout << "Toss " << i << ": Heads" << endl;
		}
		else {
			++tails;
			cout << "Toss " << i << ": Tails" << endl;
		}
	}

	cout << "Totals -> Heads: " << heads << ", Tails: " << tails << endl;
}




int main() {

	/// Главная функция программы.
	/// 
	/// Реализует интерактивное меню для выбора и выполнения одной из 26 задач.
	/// Программа работает в цикле до тех пор, пока пользователь не выберет выход (0).
	/// 
	/// Алгоритм:
	/// 1. В бесконечном цикле выводим меню
	/// 2. Запрашиваем выбор пользователя
	/// 3. Проверяем корректность ввода (если ввод некорректен - завершаем программу)
	/// 4. Если выбран 0 - выходим из цикла
	/// 5. Используем switch для вызова соответствующей функции Task
	/// 6. Если выбран несуществующий номер - выводим сообщение об ошибке

	srand(time(0));

	int userChoice = 0;

	while (true)
	{

		cout << "Choice task: " << endl;
		cout << " 1 - task I" << endl;
		cout << " 2 - task II" << endl;
		cout << " 3 - task III" << endl;
		cout << " 4 - task IV" << endl;
		cout << " 5 - task V" << endl;
		cout << " 6 - task VI" << endl;
		cout << " 7 - task VII" << endl;
		cout << " 8 - task VIII" << endl;
		cout << " 9 - task IX" << endl;
		cout << " 10- task X" << endl;
		cout << " 11- task XI" << endl;
		cout << " 12- task XII" << endl;
		cout << " 13- task XIII" << endl;
		cout << " 14- task XIV" << endl;
		cout << " 15- task XV" << endl;
		cout << " 16- task XVI" << endl;
		cout << " 17- task XVII" << endl;
		cout << " 18- task XVIII" << endl;
		cout << " 19- task XIX" << endl;
		cout << " 20- task XX" << endl;
		cout << " 21- task XXI" << endl;
		cout << " 22- task XXII" << endl;
		cout << " 23- task XXIII" << endl;
		cout << " 24- task XXIV" << endl;
		cout << " 25- task XXV" << endl;
		cout << " 26- task XVI" << endl;
		cout << " 0- exit" << endl;

		cin >> userChoice;

		if (userChoice == 0) {
			break;
		}

		switch (userChoice) {
		case 1:  TaskI(); break;
		case 2:  TaskII(); break;
		case 3:  TaskIII(); break;
		case 4:  TaskIV(); break;
		case 5:  TaskV(); break;
		case 6:  TaskVI(); break;
		case 7:  TaskVII(); break;
		case 8:  TaskVIII(); break;
		case 9:  TaskIX(); break;
		case 10: TaskX(); break;
		case 11: TaskXI(); break;
		case 12: TaskXII(); break;
		case 13: TaskXIII(); break;
		case 14: TaskXIV(); break;
		case 15: TaskXV(); break;
		case 16: TaskXVI(); break;
		case 17: TaskXVII(); break;
		case 18: TaskXVIII(); break;
		case 19: TaskXIX(); break;
		case 20: TaskXX(); break;
		case 21: TaskXXI(); break;
		case 22: TaskXXII(); break;
		case 23: TaskXXIII(); break;
		case 24: TaskXXIV(); break;
		case 25: TaskXXV(); break;
		case 26: TaskXXVI(); break;
		default:
			cout << "No such task. Please try again." << endl;
			break;
		}
	}

	return 0;
}