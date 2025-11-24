import sys, os


LANG = "ru"


def tr(ru: str, en: str) -> str:
    return ru if LANG == "ru" else en


def print_section(title: str):
    bar = "=" * len(title)
    print(f"\n{title}\n{bar}")


def safe_input(prompt: str) -> str:
    try:
        return input(prompt)
    except Exception:
        return ""


def menu_ru():
    print_section("Этап 2 — меню практики")
    print("1) Текущая директория (getcwd/chdir)")
    print("2) Список файлов/папок (listdir)")
    print("3) Создать каталог (mkdir)")
    print("4) Удалить каталог (rmdir)")
    print("5) Работа с путями (join/split/basename/dirname)")
    print("6) Проверки существования (exists/isfile/isdir)")
    print("0) Выход")


def menu_en():
    print_section("Step 2 — practice menu")
    print("1) Current directory (getcwd/chdir)")
    print("2) List files/folders (listdir)")
    print("3) Create directory (mkdir)")
    print("4) Remove directory (rmdir)")
    print("5) Work with paths (join/split/basename/dirname)")
    print("6) Existence checks (exists/isfile/isdir)")
    print("0) Exit")


def task_1_cwd():
    print_section(tr(
        "Задание 1: текущая директория (os.getcwd, os.chdir)",
        "Task 1: current directory (os.getcwd, os.chdir)"
    ))
    start_cwd = os.getcwd()
    print(tr(f"[i] Текущая директория: {start_cwd}", f"[i] Current directory: {start_cwd}"))

    target = safe_input(tr(
        "[?] Введите путь каталога, в который хотите перейти (Enter — пропустить): ",
        "[?] Enter a directory path to cd into (Enter — skip): "
    )).strip()
    if target:
        if os.path.isdir(target):
            try:
                os.chdir(target)
                print(tr(f"[/\\] Перешли в: {os.getcwd()}", f"[/\\] Changed to: {os.getcwd()}"))
            except Exception as e:
                print(tr(f"[!] Не удалось перейти: {e}", f"[!] Failed to change directory: {e}"))
        else:
            print(tr(
                f"[!] Путь не существует или это не каталог: {target}",
                f"[!] Path does not exist or not a directory: {target}"
            ))

    try:
        os.chdir(start_cwd)
        print(tr(
            f"[i] Вернулись в исходную директорию: {os.getcwd()}",
            f"[i] Returned to initial directory: {os.getcwd()}"
        ))
    except Exception as e:
        print(tr(f"[!] Не удалось вернуться: {e}", f"[!] Failed to return: {e}"))


def task_2_listdir():
    print_section(tr(
        "Задание 2: список файлов и папок (os.listdir)",
        "Task 2: list files and folders (os.listdir)"
    ))
    cwd = os.getcwd()
    try:
        entries = os.listdir(cwd)
    except Exception as e:
        print(tr(
            f"[!] Не удалось прочитать содержимое {cwd}: {e}",
            f"[!] Failed to read directory {cwd}: {e}"
        ))
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

    print(tr(f"[i] Текущая директория: {cwd}", f"[i] Current directory: {cwd}"))
    print(tr(f"- Папки ({len(dirs)}): {dirs}", f"- Dirs ({len(dirs)}): {dirs}"))
    print(tr(f"- Файлы ({len(files)}): {files}", f"- Files ({len(files)}): {files}"))
    if others:
        print(tr(f"- Другое ({len(others)}): {others}", f"- Other ({len(others)}): {others}"))


def task_3_mkdir():
    print_section(tr(
        "Задание 3: создать каталог (os.mkdir)",
        "Task 3: create directory (os.mkdir)"
    ))
    cwd = os.getcwd()
    folder_name = safe_input(tr(
        "[?] Введите имя каталога для создания: ",
        "[?] Enter directory name to create: "
    )).strip()
    if not folder_name:
        print(tr("[!] Имя каталога не указано.", "[!] Directory name is empty."))
        return

    folder = os.path.join(cwd, folder_name)
    if not os.path.exists(folder):
        try:
            os.mkdir(folder)
            print(tr(f"[/\\] Создан каталог: {folder}", f"[/\\] Created directory: {folder}"))
        except Exception as e:
            print(tr(f"[!] Не удалось создать: {e}", f"[!] Failed to create: {e}"))
    else:
        print(tr(f"[i] Такой каталог уже существует: {folder}", f"[i] Directory already exists: {folder}"))


def task_4_rmdir():
    print_section(tr(
        "Задание 4: удалить каталог (os.rmdir)",
        "Task 4: remove directory (os.rmdir)"
    ))
    cwd = os.getcwd()
    folder_name = safe_input(tr(
        "[?] Введите имя каталога для удаления: ",
        "[?] Enter directory name to remove: "
    )).strip()
    if not folder_name:
        print(tr("[!] Имя каталога не указано.", "[!] Directory name is empty."))
        return

    folder = os.path.join(cwd, folder_name)
    if os.path.isdir(folder):
        try:
            os.rmdir(folder)
            print(tr(f"[/\\] Удалён пустой каталог: {folder}", f"[/\\] Removed empty directory: {folder}"))
        except OSError as e:
            print(tr(
                f"[i] Не удалось удалить: каталог не пуст или занят. {e}",
                f"[i] Failed to remove: directory not empty or in use. {e}"
            ))
        except Exception as e:
            print(tr(f"[!] Ошибка удаления: {e}", f"[!] Removal error: {e}"))
    else:
        print(tr(f"[!] Такого каталога нет или это не папка: {folder}", f"[!] No such directory or not a folder: {folder}"))


def task_5_paths():
    print_section(tr(
        "Задание 5: работа с путями (join, split, basename, dirname)",
        "Task 5: work with paths (join, split, basename, dirname)"
    ))
    base_dir = safe_input(tr(
        "[?] Введите каталог (Enter — текущий): ",
        "[?] Enter a directory (Enter — current): "
    )).strip()
    if not base_dir:
        base_dir = os.getcwd()

    file_name = safe_input(tr(
        "[?] Введите имя файла (например, notes.txt): ",
        "[?] Enter a file name (e.g., notes.txt): "
    )).strip()
    if not file_name:
        print(tr("[!] Имя файла пустое — пропускаем демонстрацию.", "[!] Empty file name — skipping demo."))
        return

    abs_dir = os.path.abspath(base_dir)
    abs_path = os.path.join(abs_dir, file_name)

    print(tr(f"[i] Абсолютный каталог: {abs_dir}", f"[i] Absolute directory: {abs_dir}"))
    print(tr(f"[i] Собранный путь к файлу: {abs_path}", f"[i] Built file path: {abs_path}"))
    print(tr(f"[i] split → {os.path.split(abs_path)}", f"[i] split → {os.path.split(abs_path)}"))
    print(tr(f"[i] dirname(): {os.path.dirname(abs_path)}", f"[i] dirname(): {os.path.dirname(abs_path)}"))
    print(tr(f"[i] basename(): {os.path.basename(abs_path)}", f"[i] basename(): {os.path.basename(abs_path)}"))


def task_6_checks():
    print_section(tr(
        "Задание 6: проверки существования (exists, isfile, isdir)",
        "Task 6: existence checks (exists, isfile, isdir)"
    ))
    path = safe_input(tr(
        "[?] Введите путь для проверки: ",
        "[?] Enter a path to check: "
    )).strip()
    if not path:
        print(tr("[!] Путь пуст — пропускаем.", "[!] Empty path — skipping."))
        return

    print(tr(f"[i] exists={os.path.exists(path)}", f"[i] exists={os.path.exists(path)}"))
    print(tr(f"[i] isfile={os.path.isfile(path)}", f"[i] isfile={os.path.isfile(path)}"))
    print(tr(f"[i] isdir={os.path.isdir(path)}", f"[i] isdir={os.path.isdir(path)}"))


def lang_menu():
    print("1) русский")
    print("2) english")
    print("0) выход/exit")


def main():
    global LANG

    if len(sys.argv) > 1:
        start_dir = sys.argv[1]
        if os.path.isdir(start_dir):
            try:
                os.chdir(start_dir)
            except Exception:
                pass

    lang_menu()
    choice = safe_input("[?] выберете язык/select language: ").strip()
    if choice == "1":
        LANG = "ru"
    elif choice == "2":
        LANG = "en"
    else:
        return

    while True:
        if LANG == "ru":
            menu_ru()
            sel = safe_input("[?] Выберите пункт: ").strip()
        else:
            menu_en()
            sel = safe_input("[?] Select an item: ").strip()

        if sel == "1":
            task_1_cwd()
        elif sel == "2":
            task_2_listdir()
        elif sel == "3":
            task_3_mkdir()
        elif sel == "4":
            task_4_rmdir()
        elif sel == "5":
            task_5_paths()
        elif sel == "6":
            task_6_checks()
        elif sel == "0" or sel == "":
            print(tr("[i] Завершение.", "[i] Exiting."))
            break
        else:
            print(tr("[!] Неизвестный пункт меню.", "[!] Unknown menu item."))


main()