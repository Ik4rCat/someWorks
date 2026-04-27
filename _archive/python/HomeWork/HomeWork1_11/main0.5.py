import re

def is_strong_password(password: str) -> bool:
    return (len(password) >= 8 and
            re.search(r'[A-Z]', password) and 
            re.search(r'[a-z]', password) and 
            re.search(r'[0-9]', password) and  
            re.search(r'[@#$%&*]', password))  

print(is_strong_password("Passw0rd@")) 
print(is_strong_password("nike")) 
