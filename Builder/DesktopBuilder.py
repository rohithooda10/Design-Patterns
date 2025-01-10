from abc import ABC, abstractmethod

class Desktop:
    os: str
    processor: str
    ram: str

class DesktopBuilder(ABC):
    @abstractmethod
    def add_os(self):
        pass
    @abstractmethod
    def add_processor(self):
        pass
    @abstractmethod
    def add_ram(self):
        pass

class DellBuilder(DesktopBuilder):
    desktop: Desktop = Desktop()
    def add_os(self):
        self.desktop.os = "DellOS"
    
    def add_processor(self):
        self.desktop.processor = "DellProcessor"
    
    def add_ram(self):
        self.desktop.ram = "DellRam"

    def get_desktop(self):
        return self.desktop

class HpBuilder(DesktopBuilder):
    desktop: Desktop = Desktop()
    def add_os(self):
        self.desktop.os = "HpOS"
    
    def add_processor(self):
        self.desktop.processor = "HpProcessor"
    
    def add_ram(self):
        self.desktop.ram = "HpRam"
    
    def get_desktop(self):
        return self.desktop

class Director:
    desktop: Desktop
    def __init__(self):
        self.desktop = Desktop()
    def contruct(self, builder):
        builder.add_os()
        builder.add_processor()
        builder.add_ram()
        self.desktop = builder.get_desktop()
    def get_desktop(self):
        return self.desktop
    
if __name__=="__main__":
    director = Director()
    builder = HpBuilder()
    director.contruct(builder)
    desktop = director.get_desktop()
    
    print(desktop.os)
    print(desktop.processor)
    print(desktop.ram)
