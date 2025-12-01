'''
def calcul(a:int,b:int) -> int:
    return(a+b)
num = calcul(5.9,5)
print(num) 

ab = lambda:2+3
print(ab, 2)
'''

def calculator(a:str):
    nums = []
    op = []

    for i in a:
        if i.isdigit():
            nums.append(int(i))
        else:
            op.append(i)
    for i in range(len(op)):
        if op[i] == "+":
            print(a) 
#            summ(nums[i],nums[i+1])


#    def summ():
        



#    print(nums)
#    print(op)
#    return nums[-1]
#print(calculator())
