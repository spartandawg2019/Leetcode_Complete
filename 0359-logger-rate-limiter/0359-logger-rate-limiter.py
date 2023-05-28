class Logger:

    def __init__(self):
        self.message_timestamps = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message in self.message_timestamps and timestamp - self.message_timestamps[message] < 10:
            return False
        self.message_timestamps[message] = timestamp
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)