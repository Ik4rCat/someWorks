import random
import time

1 = [random.randint(0, 1000000001) for i in range(100000)]
2 = [random.randint(0, 1000000001) for i in range(200000)]
3 = [random.randint(0, 1000000001) for i in range(400000)]
4 = [random.randint(0, 1000000001) for i in range(800000)]
5 = [random.randint(0, 1000000001) for i in range(1200000)]

def rand(lst):
  start = time.time()
  for _ in range(1000):
    random.randint(0, 1000000000) in lst
  stop = time.time()
  print(stop - start)

rand(1)
rand(2)
rand(3)
rand(4)
rand(5)