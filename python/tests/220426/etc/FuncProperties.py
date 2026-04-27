def test_square_non_negative():
    for x in range(-100, 100):
        assert square(x) >= 0;
        