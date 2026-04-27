import re

def is_valid_email(email):
    pattern = r'^[w.-]+@[w.-]+.w{2,6}$'
    return bool(re.match(pattern, email))

print(is_valid_email("example@test.com")) 
print(is_valid_email("example@com")) 
