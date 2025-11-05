import random
import time

q = random.randint(0, 1000000001)

list0 = [q for _ in range(100000)]
list1 = [q for _ in range(200000)]
list2 = [q for _ in range(400000)]
list3 = [q for _ in range(800000)]
list4 = [q for _ in range(1200000)]

def randForList(list):
  start = time.time()
  for _ in range(1000):
    random.randint(0, 1000000000) in list
  stop = time.time()
  print(stop - start)

randForList(list0)
randForList(list1)
randForList(list2)
randForList(list3)
randForList(list4)