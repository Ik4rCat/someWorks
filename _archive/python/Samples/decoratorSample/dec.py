
def decorator(func):
    def wrapper(name):
        print("[$] before func start")
        func(name)
        print("[!] after func start")
    return wrapper

@decorator
def greet(name):
    print(f"hello, {name}!")

namee = input("write name: ")
greet(namee)


