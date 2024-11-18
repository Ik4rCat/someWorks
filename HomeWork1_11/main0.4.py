import re

def extract_hashtags(text: str) -> list:
    return re.findall(r'#\w+', text)

text = "Сегодня отличный день! #python #programming #100DaysOfCode"
print(extract_hashtags(text)) 
