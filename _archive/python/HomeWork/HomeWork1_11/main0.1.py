import re

def is_email_valid(email: str) -> bool:
    pattern = r'^[a-zA-Z0-9._]+@[a-zA-Z]+\.(com|org|ru)$'
    return bool(re.match(pattern, email))

print(is_email_valid("example.email@gmail.com")) 
print(is_email_valid("wrong_email@domain")) 
print(is_email_valid("user_name@domain.org")) 
