import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox
import re
from abc import ABC, abstractmethod
from typing import Dict, List, Optional


class CodeAnalyzer(ABC):
    """Абстрактный базовый класс для анализаторов кода"""
    
    @abstractmethod
    def analyze(self, code: str) -> str:
        """Анализирует код и возвращает объяснение"""
        pass
    
    @abstractmethod
    def get_language(self) -> str:
        """Возвращает название языка программирования"""
        pass


class PythonAnalyzer(CodeAnalyzer):
    """Анализатор кода Python"""
    
    def __init__(self):
        self.patterns = {
            r'^def\s+\w+\s*\([^)]*\)\s*:': self._explain_function,
            r'^class\s+\w+': self._explain_class,
            r'^import\s+\w+': self._explain_import,
            r'^from\s+\w+\s+import': self._explain_from_import,
            r'^if\s+.*:': self._explain_if,
            r'^for\s+\w+\s+in\s+.*:': self._explain_for,
            r'^while\s+.*:': self._explain_while,
            r'^\w+\s*=\s*.*': self._explain_assignment,
            r'^return\s+.*': self._explain_return,
            r'^print\s*\(.*\)': self._explain_print,
        }
    
    def get_language(self) -> str:
        return "Python"
    
    def analyze(self, code: str) -> str:
        """Анализирует код Python и возвращает объяснение"""
        code = code.strip()
        if not code:
            return "Пустая строка кода"
        
        for pattern, explainer in self.patterns.items():
            if re.match(pattern, code):
                return explainer(code)
        
        return self._explain_generic(code)
    
    def _explain_function(self, code: str) -> str:
        match = re.match(r'def\s+(\w+)\s*\(([^)]*)\)', code)
        if match:
            name = match.group(1)
            params = match.group(2)
            return f"Определение функции '{name}' с параметрами: {params if params else 'нет параметров'}"
        return "Определение функции"
    
    def _explain_class(self, code: str) -> str:
        match = re.match(r'class\s+(\w+)', code)
        if match:
            name = match.group(1)
            return f"Определение класса '{name}'"
        return "Определение класса"
    
    def _explain_import(self, code: str) -> str:
        match = re.match(r'import\s+(\w+)', code)
        if match:
            module = match.group(1)
            return f"Импорт модуля '{module}'"
        return "Импорт модуля"
    
    def _explain_from_import(self, code: str) -> str:
        match = re.match(r'from\s+(\w+)\s+import\s+(.+)', code)
        if match:
            module = match.group(1)
            items = match.group(2)
            return f"Импорт {items} из модуля '{module}'"
        return "Импорт из модуля"
    
    def _explain_if(self, code: str) -> str:
        match = re.match(r'if\s+(.+):', code)
        if match:
            condition = match.group(1)
            return f"Условный оператор: если {condition}, то выполнить следующий блок кода"
        return "Условный оператор if"
    
    def _explain_for(self, code: str) -> str:
        match = re.match(r'for\s+(\w+)\s+in\s+(.+):', code)
        if match:
            variable = match.group(1)
            iterable = match.group(2)
            return f"Цикл for: для каждого элемента '{variable}' в {iterable} выполнить блок кода"
        return "Цикл for"
    
    def _explain_while(self, code: str) -> str:
        match = re.match(r'while\s+(.+):', code)
        if match:
            condition = match.group(1)
            return f"Цикл while: пока {condition} истинно, выполнять блок кода"
        return "Цикл while"
    
    def _explain_assignment(self, code: str) -> str:
        match = re.match(r'(\w+)\s*=\s*(.+)', code)
        if match:
            variable = match.group(1)
            value = match.group(2)
            return f"Присваивание: переменной '{variable}' присваивается значение {value}"
        return "Присваивание значения"
    
    def _explain_return(self, code: str) -> str:
        match = re.match(r'return\s+(.+)', code)
        if match:
            value = match.group(1)
            return f"Возврат значения: {value}"
        return "Возврат значения из функции"
    
    def _explain_print(self, code: str) -> str:
        match = re.match(r'print\s*\((.+)\)', code)
        if match:
            content = match.group(1)
            return f"Вывод на экран: {content}"
        return "Вывод на экран"
    
    def _explain_generic(self, code: str) -> str:
        return f"Код Python: {code}\n\nЭто может быть вызов функции, выражение или другая конструкция языка."


class CppAnalyzer(CodeAnalyzer):
    """Анализатор кода C++"""
    
    def __init__(self):
        self.patterns = {
            r'^#include\s*[<"].*[>"]': self._explain_include,
            r'^using\s+namespace': self._explain_using,
            r'^int\s+main\s*\(': self._explain_main,
            r'^\w+\s+\w+\s*\([^)]*\)\s*\{': self._explain_function,
            r'^class\s+\w+': self._explain_class,
            r'^if\s*\([^)]+\)': self._explain_if,
            r'^for\s*\([^)]+\)': self._explain_for,
            r'^while\s*\([^)]+\)': self._explain_while,
            r'^\w+\s+\w+\s*=\s*.*;': self._explain_declaration,
            r'^cout\s*<<': self._explain_cout,
            r'^return\s+.*;': self._explain_return,
        }
    
    def get_language(self) -> str:
        return "C++"
    
    def analyze(self, code: str) -> str:
        """Анализирует код C++ и возвращает объяснение"""
        code = code.strip()
        if not code:
            return "Пустая строка кода"
        
        for pattern, explainer in self.patterns.items():
            if re.match(pattern, code):
                return explainer(code)
        
        return self._explain_generic(code)
    
    def _explain_include(self, code: str) -> str:
        match = re.match(r'#include\s*([<"].*[>"])', code)
        if match:
            header = match.group(1)
            return f"Подключение заголовочного файла: {header}"
        return "Подключение заголовочного файла"
    
    def _explain_using(self, code: str) -> str:
        match = re.match(r'using\s+namespace\s+(\w+)', code)
        if match:
            namespace = match.group(1)
            return f"Использование пространства имен: {namespace}"
        return "Использование пространства имен"
    
    def _explain_main(self, code: str) -> str:
        return "Определение главной функции программы (точка входа)"
    
    def _explain_function(self, code: str) -> str:
        match = re.match(r'(\w+)\s+(\w+)\s*\(([^)]*)\)', code)
        if match:
            return_type = match.group(1)
            name = match.group(2)
            params = match.group(3)
            return f"Определение функции '{name}' возвращающей {return_type} с параметрами: {params if params else 'нет параметров'}"
        return "Определение функции"
    
    def _explain_class(self, code: str) -> str:
        match = re.match(r'class\s+(\w+)', code)
        if match:
            name = match.group(1)
            return f"Определение класса '{name}'"
        return "Определение класса"
    
    def _explain_if(self, code: str) -> str:
        match = re.match(r'if\s*\((.+)\)', code)
        if match:
            condition = match.group(1)
            return f"Условный оператор: если {condition}, то выполнить следующий блок кода"
        return "Условный оператор if"
    
    def _explain_for(self, code: str) -> str:
        match = re.match(r'for\s*\(([^)]+)\)', code)
        if match:
            parts = match.group(1).split(';')
            if len(parts) == 3:
                init = parts[0].strip()
                condition = parts[1].strip()
                increment = parts[2].strip()
                return f"Цикл for: инициализация ({init}), условие ({condition}), инкремент ({increment})"
        return "Цикл for"
    
    def _explain_while(self, code: str) -> str:
        match = re.match(r'while\s*\((.+)\)', code)
        if match:
            condition = match.group(1)
            return f"Цикл while: пока {condition} истинно, выполнять блок кода"
        return "Цикл while"
    
    def _explain_declaration(self, code: str) -> str:
        match = re.match(r'(\w+)\s+(\w+)\s*=\s*(.+);', code)
        if match:
            type_name = match.group(1)
            variable = match.group(2)
            value = match.group(3)
            return f"Объявление переменной типа {type_name} с именем '{variable}' и значением {value}"
        return "Объявление переменной"
    
    def _explain_cout(self, code: str) -> str:
        match = re.match(r'cout\s*<<\s*(.+)', code)
        if match:
            content = match.group(1)
            return f"Вывод на экран через cout: {content}"
        return "Вывод на экран"
    
    def _explain_return(self, code: str) -> str:
        match = re.match(r'return\s+(.+);', code)
        if match:
            value = match.group(1)
            return f"Возврат значения: {value}"
        return "Возврат значения из функции"
    
    def _explain_generic(self, code: str) -> str:
        return f"Код C++: {code}\n\nЭто может быть вызов функции, выражение или другая конструкция языка."


class CodeExplainer:
    """Класс для управления анализаторами кода"""
    
    def __init__(self):
        self.analyzers: Dict[str, CodeAnalyzer] = {
            'python': PythonAnalyzer(),
            'cpp': CppAnalyzer(),
            'c++': CppAnalyzer(),
        }
    
    def explain(self, code: str, language: str) -> str:
        """Объясняет код на указанном языке"""
        language = language.lower()
        if language in self.analyzers:
            analyzer = self.analyzers[language]
            return analyzer.analyze(code)
        else:
            return f"Неподдерживаемый язык: {language}"
    
    def get_supported_languages(self) -> List[str]:
        """Возвращает список поддерживаемых языков"""
        return list(self.analyzers.keys())


class CodeExplainerGUI:
    """Графический интерфейс для приложения объяснения кода"""
    
    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("Объяснитель кода")
        self.root.geometry("800x600")
        
        self.explainer = CodeExplainer()
        
        self._create_widgets()
        self._layout_widgets()
    
    def _create_widgets(self):
        """Создает виджеты интерфейса"""
        # Заголовок
        self.title_label = tk.Label(
            self.root,
            text="Объяснитель кода",
            font=("Arial", 16, "bold")
        )
        
        # Выбор языка
        self.language_frame = tk.Frame(self.root)
        self.language_label = tk.Label(
            self.language_frame,
            text="Выберите язык:",
            font=("Arial", 10)
        )
        self.language_var = tk.StringVar(value="python")
        self.language_python = tk.Radiobutton(
            self.language_frame,
            text="Python",
            variable=self.language_var,
            value="python",
            font=("Arial", 10)
        )
        self.language_cpp = tk.Radiobutton(
            self.language_frame,
            text="C++",
            variable=self.language_var,
            value="cpp",
            font=("Arial", 10)
        )
        
        # Поле ввода кода
        self.input_label = tk.Label(
            self.root,
            text="Введите код:",
            font=("Arial", 10, "bold")
        )
        self.input_text = scrolledtext.ScrolledText(
            self.root,
            height=8,
            width=80,
            font=("Consolas", 10),
            wrap=tk.WORD
        )
        
        # Кнопка анализа
        self.analyze_button = tk.Button(
            self.root,
            text="Объяснить код",
            command=self._analyze_code,
            font=("Arial", 11, "bold"),
            bg="#4CAF50",
            fg="white",
            padx=20,
            pady=10
        )
        
        # Поле вывода объяснения
        self.output_label = tk.Label(
            self.root,
            text="Объяснение:",
            font=("Arial", 10, "bold")
        )
        self.output_text = scrolledtext.ScrolledText(
            self.root,
            height=12,
            width=80,
            font=("Arial", 11),
            wrap=tk.WORD,
            state=tk.DISABLED,
            bg="#f0f0f0"
        )
        
        # Кнопка очистки
        self.clear_button = tk.Button(
            self.root,
            text="Очистить",
            command=self._clear_all,
            font=("Arial", 10),
            bg="#f44336",
            fg="white",
            padx=15,
            pady=5
        )
    
    def _layout_widgets(self):
        """Размещает виджеты в окне"""
        self.title_label.pack(pady=10)
        
        self.language_frame.pack(pady=5)
        self.language_label.pack(side=tk.LEFT, padx=5)
        self.language_python.pack(side=tk.LEFT, padx=10)
        self.language_cpp.pack(side=tk.LEFT, padx=10)
        
        self.input_label.pack(pady=(10, 5), anchor=tk.W, padx=20)
        self.input_text.pack(pady=5, padx=20, fill=tk.BOTH, expand=True)
        
        self.analyze_button.pack(pady=10)
        
        self.output_label.pack(pady=(10, 5), anchor=tk.W, padx=20)
        self.output_text.pack(pady=5, padx=20, fill=tk.BOTH, expand=True)
        
        self.clear_button.pack(pady=10)
    
    def _analyze_code(self):
        """Анализирует введенный код и выводит объяснение"""
        code = self.input_text.get("1.0", tk.END).strip()
        language = self.language_var.get()
        
        if not code:
            messagebox.showwarning("Предупреждение", "Пожалуйста, введите код для анализа")
            return
        
        # Получаем объяснение
        explanation = self.explainer.explain(code, language)
        
        # Выводим объяснение
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        self.output_text.insert("1.0", explanation)
        self.output_text.config(state=tk.DISABLED)
    
    def _clear_all(self):
        """Очищает все поля"""
        self.input_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.DISABLED)


def main():
    """Главная функция для запуска приложения"""
    root = tk.Tk()
    app = CodeExplainerGUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()

