numbers1=[1, 2, 3, 4, 5]
numbers2=[-1, 1, -2, 3, -1, 3]
userList = []

def InputTime(usernums):
    userInp = input("Введите числа через пробел: ")
    usernums = [int(num) for num in userInp.split()]
    userList.extend(usernums)


def SumList(nums):
    if not nums:
        return 0
    return nums[0] + SumList(nums[1:])


print(f""" суммы из задания: \n
    {SumList(numbers1)}
    {SumList(numbers2)}
    """)

def main():
    InputTime(userList)
    print(SumList(userList))

main()