import os, sys

def main():
    info = [
        f"Тип ОС: {os.name}",
        f"Платформа: {sys.platform}",
        f"Версия Python: {sys.version}",
        f"Текущий путь: {os.getcwd()}",
        f"Исполняемый файл Python: {sys.executable}",
        f"Пути поиска модулей: {sys.path}",
    ]

    # Вывод в консоль
    for line in info:
        print(line)

    # Запись в файл
    with open("system_info.txt", "w") as f:
        f.write("\n".join(info))

main()