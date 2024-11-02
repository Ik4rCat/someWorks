import random
import time

q = random.randint(0, 1000000001)

set0 = {q for _ in range(100000)}
set1 = {q for _ in range(200000)}
set2 = {q for _ in range(400000)}
set3 = {q for _ in range(800000)}
set4 = {q for _ in range(1200000)}

def randForSet(set_obj):
    start = time.time()
    for _ in range(1000000):  
        random.randint(0, 1000000000) in set_obj
    stop = time.time()
    print(stop - start)

randForSet(set0)
randForSet(set1)
randForSet(set2)
randForSet(set3)
randForSet(set4)
