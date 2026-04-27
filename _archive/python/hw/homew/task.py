vector = list(map(float, input("Enter vector elements separated by space: ").split()))

product = 1
found_positive = False

for num in vector:
    if num > 0:
        product *= num
        found_positive = True


if found_positive:
    print(f"Product of positive elements: {product}")
else:
    print("No positive elements found in the vector.")