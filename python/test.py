
def Test():
    p=1
    i=1

    n = int(input("enter num: "))

    for i in range(n+1):
        p = p*i
        print(p)

def Bruh():             # так правельнее 
    n=int(input("n="))
    p=1
    i=1
    while i<=n:
        p=p*i
        i=i+1
        print(p) 

def main():
    while True:
        print("""Choice how:
                1. - my vers
                2. - on photo
                0. - exit
                """)
        choice = int(input("Enter: "))
        if (choice == 1):
            Test()
        elif (choice== 2):
            Bruh()
        elif (choice == 0):
            break
        else:
            print("wront num")
        
        
main()