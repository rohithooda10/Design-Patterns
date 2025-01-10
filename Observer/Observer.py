from abc import ABC, abstractmethod

class Observer(ABC):
    @abstractmethod
    def notify(self):
        pass

class FirstObserver(Observer):
    def notify(self):
        print("FirstObserver notified")

class SecondObserver(Observer):
    def notify(self):
        print("SecondObserver notified")

class Subject:
    observers: list
    def __init__(self):
        self.observers = []
    def add_observer(self, observer: Observer):
        self.observers.append(observer)
    def remove_observer(self, obs: Observer):
        for index, observer in enumerate(self.observers):
            if observer == obs:
                self.observers = self.observers[:index] + self.observers[index + 1:]
                break
    def notify_observers(self):
        for observer in self.observers:
            observer.notify()
    
if __name__ == "__main__":
    subject = Subject()
    obs1 = FirstObserver()
    obs2 = SecondObserver()
    subject.add_observer(obs1)
    subject.notify_observers()
    print("#################")

    subject.add_observer(obs2)
    subject.notify_observers()
    print("#################")

    subject.remove_observer(obs1)
    subject.notify_observers()