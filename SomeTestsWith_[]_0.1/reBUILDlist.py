import random, time

list01 = [random.randint(0, 1000000001) 
          for i in range(100000)]
list02 = [random.randint(0, 1000000001) 
          for i in range(200000)]
list03 = [random.randint(0, 1000000001) 
          for i in range(400000)]
list04 = [random.randint(0, 1000000001) 
          for i in range(800000)]
list05 = [random.randint(0, 1000000001) 
          for i in range(1200000)]

def List(list):
  start = time.time()
  for _ in range(1000):
    random.randint(0, 1000000000) in list
  stop = time.time()
  print(stop - start)

List(list01)
List(list02)
List(list03)
List(list04)
List(list05)