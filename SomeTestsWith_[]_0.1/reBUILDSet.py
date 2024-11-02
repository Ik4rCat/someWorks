import random, time

set01 = {random.randint(0, 1000000001) 
         for i in range(100000)}
set02 = {random.randint(0, 1000000001)
          for i in range(200000)}
set03 = {random.randint(0, 1000000001)
          for i in range(400000)}
set04 = {random.randint(0, 1000000001) 
         for i in range(800000)}
set05 = {random.randint(0, 1000000001) 
         for i in range(1200000)}

def Set(set_obj):
    start = time.time()
    for _ in range(100000):  
        random.randint(0, 1000000000) in set_obj
    stop = time.time()
    print(stop - start)

Set(set01)
Set(set02)
Set(set03)
Set(set04)
Set(set05)
