import random

i = []

def func():
    for q in range(15):
        rand_num = random.randrange(2, 6)
        i.append(rand_num)
    print(f"now: {i}")

def modify_array():
    while True:
        if i:
            removed = random.choice(i)
            i.remove(removed)
            print(f"del: {removed}")

        new_num = random.randrange(2, 6)
        i.append(new_num)
        print(f"new: {new_num}")

        if i:
            index_to_replace = random.randint(0, len(i) - 1)
            old_value = i[index_to_replace]
            i[index_to_replace] = random.randrange(2, 6)
            print(f"del {old_value} new {i[index_to_replace]}")

        print(f"now: {i}")
        print("-" * 40)

def main():
    func()
    print(f"\n{i}\n end, crazy while true time")
    modify_array()


main()
