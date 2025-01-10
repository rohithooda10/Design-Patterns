from abc import abstractmethod, ABC

class Handler(ABC):
    @abstractmethod
    def add_name(self, name: str):
        pass
    @abstractmethod
    def handle(self):
        pass
    @abstractmethod
    def add_next_handler(self, handler):
        pass

class Manager(Handler):
    name: str
    next_handler: Handler = None
    def add_name(self, name):
        self.name = name
    def handle(self):
        print("Handled by ", self.name)
        if self.next_handler is not None:
            self.next_handler.handle()
    def add_next_handler(self, handler):
        self.next_handler = handler

class HR(Handler):
    name: str
    next_handler: Handler = None
    def add_name(self, name):
        self.name = name
    def handle(self):
        print("Handled by ", self.name)
        if self.next_handler is not None:
            self.next_handler.handle()
    def add_next_handler(self, handler):
        self.next_handler = handler

class CEO(Handler):
    name: str
    next_handler: Handler = None
    def add_name(self, name):
        self.name = name
    def handle(self):
        print("Handled by ", self.name)
        if self.next_handler is not None:
            self.next_handler.handle()
    def add_next_handler(self, handler):
        self.next_handler = handler

if __name__ == "__main__":
    ceo = CEO()
    hr = HR()
    manager = Manager()

    manager.add_name("Manager")
    hr.add_name("HR")
    ceo.add_name("CEO")

    hr.add_next_handler(manager)
    manager.add_next_handler(ceo)

    hr.handle()