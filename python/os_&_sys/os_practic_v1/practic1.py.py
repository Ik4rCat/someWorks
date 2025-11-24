# Этап 2: практика по os и os.path

import os
import sys


def print_section(title: str):
    bar = "=" * len(title)
    print(f"\n{title}\n{bar}")


def safe_input(prompt: str) -> str:
    try:
        return input(prompt)
    except EOFError:
        return ""


def task_1_cwd():
    print_section("Задание 1: текущая директория (os.getcwd, os.chdir)")
    start_cwd = os.getcwd()
    print(f"[i] Текущая директория: {start_cwd}")

    target = safe_input("[?] Введите путь каталога, в который хотите перейти (Enter — пропустить): ").strip()
    if target:
        if os.path.isdir(target):
            try:
                os.chdir(target)
                print(f"[\/] Перешли в: {os.getcwd()}")
            except Exception as e:
                print(f"[!] Не удалось перейти: {e}")
        else:
            print(f"[!] Путь не существует или это не каталог: {target}")

    try:
        os.chdir(start_cwd)
        print(f"[i] Вернулись в исходную директорию: {os.getcwd()}")
    except Exception as e:
        print(f"[!] Не удалось вернуться: {e}")


def task_2_listdir():
    print_section("Задание 2: список файлов и папок (os.listdir)")
    cwd = os.getcwd()
    try:
        entries = os.listdir(cwd)
    except Exception as e:
        print(f"[!] Не удалось прочитать содержимое {cwd}: {e}")
        return

    files = []
    dirs = []
    others = []
    for name in entries:
        path = os.path.join(cwd, name)
        if os.path.isfile(path):
            files.append(name)
        elif os.path.isdir(path):
            dirs.append(name)
        else:
            others.append(name)

    print(f"[i] Текущая директория: {cwd}")
    print(f"- Папки ({len(dirs)}): {dirs}")
    print(f"- Файлы ({len(files)}): {files}")
    if others:
        print(f"- Другое ({len(others)}): {others}")


def task_3_mkdir():
    print_section("Задание 3: создать каталог (os.mkdir)")
    cwd = os.getcwd()
    folder_name = safe_input("[?] Введите имя каталога для создания: ").strip()
    if not folder_name:
        print("[!] Имя каталога не указано.")
        return

    folder = os.path.join(cwd, folder_name)
    if not os.path.exists(folder):
        try:
            os.mkdir(folder)
            print(f"[\/] Создан каталог: {folder}")
        except Exception as e:
            print(f"[!] Не удалось создать: {e}")
    else:
        print(f"[i] Такой каталог уже существует: {folder}")


def task_4_rmdir():
    print_section("Задание 4: удалить каталог (os.rmdir)")
    cwd = os.getcwd()
    folder_name = safe_input("[?] Введите имя каталога для удаления: ").strip()
    if not folder_name:
        print("[!] Имя каталога не указано.")
        return

    folder = os.path.join(cwd, folder_name)
    if os.path.isdir(folder):
        try:
            os.rmdir(folder)
            print(f"[\/] Удалён пустой каталог: {folder}")
        except OSError as e:
            print(f"[i] Не удалось удалить: каталог не пуст или занят. {e}")
        except Exception as e:
            print(f"[!] Ошибка удаления: {e}")
    else:
        print(f"[!] Такого каталога нет или это не папка: {folder}")


def task_5_paths():
    print_section("Задание 5: работа с путями (join, split, basename, dirname)")
    base_dir = safe_input("[?] Введите каталог (Enter — текущий): ").strip()
    if not base_dir:
        base_dir = os.getcwd()

    file_name = safe_input("[?] Введите имя файла (например, notes.txt): ").strip()
    if not file_name:
        print("[!] Имя файла пустое — пропускаем демонстрацию.")
        return

    abs_dir = os.path.abspath(base_dir)
    abs_path = os.path.join(abs_dir, file_name)

    print(f"[i] Абсолютный каталог: {abs_dir}")
    print(f"[i] Собранный путь к файлу: {abs_path}")
    print(f"[i] split → {os.path.split(abs_path)}")
    print(f"[i] dirname(): {os.path.dirname(abs_path)}")
    print(f"[i] basename(): {os.path.basename(abs_path)}")


def task_6_checks():
    print_section("Задание 6: проверки существования (exists, isfile, isdir)")
    path = safe_input("[?] Введите путь для проверки: ").strip()
    if not path:
        print("[!] Путь пуст — пропускаем.")
        return

    print(f"[i] exists={os.path.exists(path)}")
    print(f"[i] isfile={os.path.isfile(path)}")
    print(f"[i] isdir={os.path.isdir(path)}")


def menu():
    print_section("Этап 2 — меню практики")
    print("1) Текущая директория (getcwd/chdir)")
    print("2) Список файлов/папок (listdir)")
    print("3) Создать каталог (mkdir)")
    print("4) Удалить каталог (rmdir)")
    print("5) Работа с путями (join/split/basename/dirname)")
    print("6) Проверки существования (exists/isfile/isdir)")
    print("0) Выход")


def main():
    if len(sys.argv) > 1:
        start_dir = sys.argv[1]
        if os.path.isdir(start_dir):
            try:
                os.chdir(start_dir)
                print(f"[i] Стартуем из каталога: {os.getcwd()}")
            except Exception as e:
                print(f"[!] Не удалось перейти в {start_dir}: {e}")

    while True:
        menu()
        choice = safe_input("[?] Выберите пункт: ").strip()
        if choice == "1":
            task_1_cwd()
        elif choice == "2":
            task_2_listdir()
        elif choice == "3":
            task_3_mkdir()
        elif choice == "4":
            task_4_rmdir()
        elif choice == "5":
            task_5_paths()
        elif choice == "6":
            task_6_checks()
        elif choice == "0" or choice == "":
            print("[i] Завершение.")
            break
        else:
            print("[!] Неизвестный пункт меню.")


if __name__ == "__main__":
    main()
