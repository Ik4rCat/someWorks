import os



def createFile(filename="participants.txt"):

    if not os.path.exists(filename):
        with open(filename, "w") as f:
            for i in range(10):  
                f.write(f"Имя: {i}\n")
        print(f"Файл {filename} создан.")
    else:
        print(f"Список участников уже существует: {filename}")

filename = "participants.txt"

def add(name):

    try:
        with open(filename, "a") as f:
            f.write(name + "\n")
        print(f"Участок {name} добавлен.")
    except Exception as e:
        print(f"Ошибка при добавлении {name}: {e}")

def show(filename):

    try:
        with open(filename, "r") as f:
            participants = f.readlines()
        print("\nСписок участников:")
        for i in range(0, len(participants), 2):
            print(f"{participants[i]}")
    except FileNotFoundError:
        print(f"Файл {filename} не найден.")
    except Exception as e:
        print(f"Ошибка при чтении файла {filename}: {e}")
    


def main():


    while True:
        print("""
            \nTake a choice:
            1. Add participant
            2. Show participants
            3. Make a file
            0. Exit
            """)


        choice = input("choice: ")

        if choice == "1":
            try:
                name = input("Введите имя участника: ")
                add(name)
            except Exception as e:
                print(f"Ошибка при добавлении {name}: {e}")

        elif choice == "2":
            show(filename)

        elif choice == "3":
            createFile(filename)

        elif choice == "0":
            print("Выход из программы")
            break

        else:
            print("Неверный выбор. Пожалуйста, попробуйте снова.")


main()