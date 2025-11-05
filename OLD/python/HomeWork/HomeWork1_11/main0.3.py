import re

def split_by_sentence(text: str) -> list:
    return re.split(r'(?<=\!|\?|\.)\s*|\.\.\.$', text)

text = "Привет! Как дела? Все хорошо..."
print(split_by_sentence(text))   
