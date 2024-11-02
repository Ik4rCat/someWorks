import random
import time

1 = {random.randint(0, 1000000001) for i in range(100000)}
2 = {random.randint(0, 1000000001) for i in range(200000)}
3 = {random.randint(0, 1000000001) for i in range(400000)}
4 = {random.randint(0, 1000000001) for i in range(800000)}
5 = {random.randint(0, 1000000001) for i in range(1200000)}

def St(st):
    start = time.time()
    for _ in range(10000):  
        random.randint(0, 1000000000) in st
    stop = time.time()
    print(stop - start)

St(1)
St(2)
St(3)
St(4)
St(5)