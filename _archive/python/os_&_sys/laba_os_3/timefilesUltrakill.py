import os, sys, argparse

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("path", help="Путь к каталогу для очистки")
    parser.add_argument("--dry-run", action="store_true", help="Режим имитации")
    parser.add_argument("--confirm", action="store_true", help="Запрос подтверждения")
    args = parser.parse_args()

    if not os.path.exists(args.path):
        print("Ошибка: каталог не существует.")
        sys.exit(1)

    # Поиск файлов .tmp и .bak
    files_to_delete = []
    for root, dirs, files in os.walk(args.path):
        for file in files:
            if file.endswith((".tmp", ".bak")):
                files_to_delete.append(os.path.join(root, file))

    # Режим dry-run
    if args.dry_run:
        print("Файлы для удаления:", files_to_delete)
        return

    # Подтверждение удаления
    if args.confirm:
        response = input(f"Удалить {len(files_to_delete)} файлов? (y/n): ")
        if response.lower() != "y":
            return

    # Удаление файлов
    for file in files_to_delete:
        try:
            os.remove(file)
            print(f"Удалён: {file}")
        except Exception as e:
            print(f"Ошибка при удалении {file}: {e}")

    print(f"Удалено файлов: {len(files_to_delete)}")

main()