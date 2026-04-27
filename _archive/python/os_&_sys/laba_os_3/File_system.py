import os, sys

def main():
    # Определение текущей директории
    print("Текущая директория:", os.getcwd())

    # Создание папки test_dir (с проверкой существования)
    folder_name = sys.argv[1] if len(sys.argv) > 1 else "test_dir"
    try:
        os.makedirs(folder_name, exist_ok=True)
        print(f"Папка '{folder_name}' создана или уже существует.")
    except Exception as e:
        print("Ошибка при создании папки:", e)

    # Переход в папку и вывод абсолютного пути
    os.chdir(folder_name)
    print("Абсолютный путь текущей директории:", os.path.abspath(os.curdir))

    #  Создание трёх пустых файлов
    files = ["file1.txt", "file2.txt", "file3.txt"]
    for file in files:
        try:
            open(file, 'a').close
        except IOError as e:
            print("Ошибка при создании файла:", e)

    # Вывод списка файлов и папок
    print("Содержимое директории:", os.listdir())

    # Проверка существования file2.txt
    print("file2.txt существует:", os.path.exists("file2.txt"))

    # Переименование file3.txt в renamed.txt
    try:
        os.rename("file3.txt", "renamed.txt")
    except FileNotFoundError:
        print("file3.txt не найден.")

    # Удаление file1.txt
    try:
        os.remove("file1.txt")
    except FileNotFoundError:
        print("file1.txt не найден.")

    # Возврат в исходную директорию и удаление test_dir
    os.chdir("..")
    try:
        os.rmdir(folder_name)
    except OSError as e:
        print("Ошибка при удалении папки:", e)

main()