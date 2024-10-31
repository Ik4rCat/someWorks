def replace_reserved_words(text, reserved_words):
    for word in reserved_words:
        text = text.replace(word, word.upper())
    return text

text_input = input("Введите текст: ")
reserved_input = input("Введите зарезервированные слова (через запятую): ")

reserved_words = [word.strip() for word in reserved_input.split(',')]
modified_text = replace_reserved_words(text_input, reserved_words)

print("Измененный текст:")
print(modified_text)
