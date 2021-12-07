def time(data):
    print("Welcome")
    def decorator(f):
        print("Hello")
        return f
    print("bye")
    return decorator

@time(12)
def Test():
    print("I am test")

res = Test()