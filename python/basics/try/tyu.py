def test(a):
    try:
        assert type(a) == int, "Input should be an integer"
#        return a + 1
    except AssertionError as e:
        print(e)
    else:
        print("No error occurred")
        return a + 1
    finally:
        print("Finally block executed")

print(test(2))
print(test("2"))

tyt = test("")
print(type(tyt))