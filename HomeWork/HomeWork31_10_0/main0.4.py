import re

def remove_duplicate_words(text):
    pattern = r'b(w+)( 1b)+'
    return re.sub(pattern, r'1', text)

print(remove_duplicate_words("This is is a test test.")) 
