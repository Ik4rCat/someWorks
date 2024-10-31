import re

def replace_dates(text):
    pattern = r'(d{2})/(d{2})/(d{4})'
    return re.sub(pattern, r'3-2-1', text)

print(replace_dates("Today's date is 24/10/2024.")) 
