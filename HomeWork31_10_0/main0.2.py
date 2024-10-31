import re

def extract_phone_numbers(text):
    pattern = r'(d{3}) d{3}-d{4}|d{3}-d{3}-d{4}'
    return re.findall(pattern, text)

print(extract_phone_numbers("My numbers are (123) 456-7890 and 123-456-7890.")) 
