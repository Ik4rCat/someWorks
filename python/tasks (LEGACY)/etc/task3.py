import random


list = []
tuple = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
dict = { }

def safe_input(prompt: str) -> str:
    try:
        return input(prompt)
    except Exception:
        return ""

def fullIT():
    for i in range(50):
        q = random.randrange(0,100)
        list.append(q) 

def workiworkiWithList():
    while True:
        print("""
        0 - exit
        1 - add
        2 - remove
        3 - pop
        4 - count
        5 - sort""")
        print(list)
        n = int(input("Chose your num: "))
        if n == 0:
            break
        elif n == 1:
            a=int(input("Write num to add: "))
            list.append(a)
        elif n == 2:
            a=int(input("Write num to remove: "))
            list.remove(a)
        elif n == 3:
            a=int(input("Write num: "))
            list.pop()
        elif n == 4:
            a=int(input("Write num to count: "))
            print(list.count(a))
        elif n == 5:
            list.sort()
            

def workiworkiWithTuple():
    while True:
        print("""
        0 - exit
        1 - count
        2 - index""")
        print(tuple)
        n = int(input("Chose your num: "))
        if n == 0:
            break
        elif n == 1:
            a=int(input("Write num to count: "))
            print(tuple.count(a))
        elif n == 2:
            a=int(input("Write num for index: "))
            print(tuple.index(a))


def   m_menu():
    print("""
    0 - exit
    1 - list work
    2 - tuple work""")

def main():
    fullIT()
    m_menu()
    choice = safe_input("[?] select: ").strip()
    if choice == "1":
        workiworkiWithList()
    elif choice == "2":
        workiworkiWithTuple()
    else:
        return 
 

main()