import re

def replace_prices(text: str) -> str:
    return re.sub(r'\d+\s?руб(ля|.)?', 'PRICE', text)

text = "Цена ноутбука 50000 руб., а телефона - 2000 рубля."
print(replace_prices(text))  
