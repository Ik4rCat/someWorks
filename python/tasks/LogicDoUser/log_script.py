
loglist = []

def log(func):
    def wrapper(username, *args):
        loglist.append(f"Вызов функции {func.__name__} пользователем {username} с аргументами {args}")
        return func(username, *args)
    return wrapper

@log
def Login(name, passw):
    return name, passw

@log
def Registr(name, passw, email):
    return name, passw, email

Login("User","1234")
Registr("NewUser", "4321", "email")


print(loglist)