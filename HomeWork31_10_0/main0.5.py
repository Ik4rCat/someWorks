import re

def extract_hashtags(text):
    pattern = r'#(w+)'
    return re.findall(pattern, text)

print(extract_hashtags("Loving the weather! #sunny #beautifulDay #nature")) 
