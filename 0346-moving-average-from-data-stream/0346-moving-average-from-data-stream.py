from collections import deque

class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = deque()
        self.sum = 0

    def next(self, val: int) -> float:
        if len(self.queue) == self.size:
            self.sum -= self.queue.popleft()

        self.queue.append(val)
        self.sum += val

        return self.sum / len(self.queue)
        
