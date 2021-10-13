from collections import deque

queue = deque([4])


def test(queue):
    queue.append(4)


test(queue)

print(queue)
