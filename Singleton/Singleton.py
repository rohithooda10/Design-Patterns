from threading import Lock

class Logger():
    type: str
    def __init__(self, type):
        self.type = type
    def log(self, message: str):
        print(self.type + " logged: " + message)

class Singleton:
    _instance: Logger = None
    _lock: Lock = Lock()
    @staticmethod
    def get_instance(type):
        if Singleton._instance is None:
            with Singleton._lock:
                if Singleton._instance is None:
                    Singleton._instance = Logger(type)
        return Singleton._instance
        
if __name__ == "__main__":
    logger = Singleton.get_instance("debug")
    logger.log("new log message")

    # Notice you get "debug" both time, since singleton, it returns same instance of logger
    logger = Singleton.get_instance("info")
    logger.log("new log message")


