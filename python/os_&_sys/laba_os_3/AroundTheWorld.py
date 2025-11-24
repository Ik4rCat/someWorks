import os

def main():
    # Все переменные окружения
    print("Переменные окружения:", dict(os.environ))

    # Значение переменной PATH
    print("PATH:", os.environ.get("PATH", "Не найдено"))

    # Имя пользователя
    username = os.environ.get("USERNAME") or os.environ.get("USER")
    print("Имя пользователя:", username)

    # Добавление переменной MY_COURSE
    os.environ["MY_COURSE"] = "OS_LAB3"
    print("MY_COURSE после добавления:", os.environ.get("MY_COURSE"))

    # Удаление переменной
    del os.environ["MY_COURSE"]
    print("MY_COURSE после удаления:", os.environ.get("MY_COURSE"))

main()