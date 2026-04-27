
#--------------------task-1--------------------#

def RepeatMessage(message, times):
    for i in range(times):
        print(message)

def RunTask1():
    userInp = input("[!MESSEGE_TIME!] Введите сообщение: ")
    userNumInp = int(input("[!WHHAAAT!] Введите количество повторений: "))        
    RepeatMessage(userInp, userNumInp)

#--------------------task-2--------------------#

def RangeWithStep(start, end, step):
    while start<=end:
        print(start)
        start+step
        return

def RunTask2():
    userNumInp1 = int(input("[Start] Введите начальное число: "))
    userNumInp2 = int(input("[Step] Введите число шага: "))
    userNumInp3 = int(input("[End] Введите конечное число: "))

    RangeWithStep(userNumInp1, userNumInp2, userNumInp3)

#--------------------task-3--------------------#

def FilterAndSquare(numbers, threshold):
    for i in range(len(numbers)):
        numbers[i] = int(numbers[i])
        if (numbers[i] **2) > threshold:
            print(numbers[i])

def RunTask3():
    userNumInp1 = input("[#] Введите список чисел: ")
    userNumInp2 = int(input("[===] Введите числовой барьер: "))
    userNumsList = userNumInp1.split()
    FilterAndSquare(userNumsList, userNumInp2)

#--------------------task-4--------------------#

def  NumberSequence(start, end, even=True):
    while start<=end:
        if even:
            if start % 2 == 0:
                print(start)
                start+1
                return
        else:
            if start % 2 != 0:
                print(start)
                start+1
                return

def RunTask4():
    userStartInp = int(input("[Start] Введите начальное число: "))
    userEndInp = int(input("[End] Введите конечное число"))
    userEvenChoice = input(" Четные = 0 или нечетеные = 1")

    if userEvenChoice == 0:
        usrEven = True
    elif userEvenChoice == 1:
        usrEven = False
    else:
        print("Неверное значение")
        userEvenChoice = input(" Четные = 0 или нечетеные = 1")

    NumberSequence(userStartInp, userEndInp, usrEven)

#---------------------main---------------------#
def main():
    print("""
        1) task 1
        2) task 2
        3) task 3
        4) task 4
        0) Exit
    """)
    userChoice=int(input("Choice: "))

    while True:
        if userChoice == 1:
            RunTask1()
        elif userChoice == 2:
            RunTask2()
        elif userChoice == 3:
            RunTask3()
        elif userChoice == 4:
            RunTask4()
        elif userChoice == 0:
            break
        else:
            print("[!] Неверное значение [!]")
            break

main()