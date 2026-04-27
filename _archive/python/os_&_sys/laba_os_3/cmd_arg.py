import sys, os

def main():
    # Имя файла и список аргументов
    print("Имя скрипта:", sys.argv[0])
    print("Аргументы:", sys.argv[1:])

    # Проверка наличия аргументов
    if len(sys.argv) < 3:
        print("Нет аргументов. Укажите хотя бы один параметр.")
        return

    # Создание файла с текстом
    filename, text = sys.argv[1], sys.argv[2]
    if os.path.exists(filename):
        print("Файл уже существует. Удалите его или выберите другое имя.")
    else:
        with open(filename, "w", encoding="utf-8") as f:
            f.write(text)
        print(f"Файл {filename} создан.")

main()