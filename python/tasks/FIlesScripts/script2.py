
filename = "book.txt"

def read_book_info(filename):
    try:
        with open(filename, "r") as f:
            content = f.read()
        return content
    except FileNotFoundError:
        print("Файл не найден.")
        return None
    except Exception as e:
        print(f"Ошибка при чтении файла {filename}: {e}")
        return None


def main():

    book_info = read_book_info(filename)

    if book_info:
        print("Название книги:", book_info)
        print("Автор:", book_info)
    else:
        print("Программа не может прочитать файл.")


main()