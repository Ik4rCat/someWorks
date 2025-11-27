import random
start = 16
end = 45
q = []
elements_in_range = []

for i in range(30):
    q.append(random.randint(0,50))


for x in q:
    if start <= x <= end:
        elements_in_range.append(x)
    
print(elements_in_range)