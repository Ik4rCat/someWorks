import random

def test_square_random():
	for _ in range(100):
		x = random.randint(1,1000)
		assert square (x) == x * x
