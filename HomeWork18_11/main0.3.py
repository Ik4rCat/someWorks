points = [(1, 2), (3, 4), (5, 6)]

updated_points = list(map(lambda point: (point[0], point[1] + 10), points))

print(updated_points)  