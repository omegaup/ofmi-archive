def provider(maeva, lorena, ramona):
    while True:
        for _ in range(maeva):
            yield "Maeva"
        for _ in range(lorena):
            yield "Lorena"
        for _ in range(ramona):
            yield "Ramona"


generator = provider(*[int(x) for x in input().split(' ')])

for t in range(44):
    next(generator)

print(next(generator))
