import re

def count_sentences(text):
    sentences = re.split(r'[.!?]+', text)
    sentences = [s.strip() for s in sentences if s.strip()]
    return len(sentences)

text_input = input("Введите текст: ")
sentence_count = count_sentences(text_input)

print(f"Количество предложений в тексте: {sentence_count}")
