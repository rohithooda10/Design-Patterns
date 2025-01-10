from abc import ABC, abstractmethod

class FileComponent(ABC):
    name: str = ""
    contents: list
    @abstractmethod
    def get_name(self):
        pass
    
    @abstractmethod
    def get_contents(self):
        pass

    @abstractmethod
    def add_content(self, content):
        pass

    @abstractmethod
    def remove_content(self, content):
        pass

    @abstractmethod
    def move_content(self, content, destination):
        pass
    
class File(FileComponent):
    name: str = ""

    def __init__(self, filename: str):
        self.name = filename
    
    def get_name(self):
        print("Name:", self.name)
    
    def get_contents(self):
        return

    def add_content(self):
        return
    
    def remove_content(self, content: FileComponent):
        return
    
    def move_content(self, content: FileComponent, destination: FileComponent):
        return

class Directory(FileComponent):
    name: str = ""
    contents: list

    def __init__(self, filename: str):
        self.name = filename
        self.contents = []
    
    def get_name(self):
        print("Name:", self.name)
    
    def get_contents(self):
        for component in self.contents:
            component.get_name()
            component.get_contents()
    
    def add_content(self,component: FileComponent):
        self.contents.append(component)

    def remove_content(self, component: FileComponent):
        for index, content in enumerate(self.contents):
            if content == component:
                self.contents = self.contents[:index] + self.contents[index  + 1:]
                break
    
    def move_content(self, content: FileComponent, destination: FileComponent):
        self.remove_content(content)
        destination.add_content(content)

if __name__ == "__main__":
    folder1 = Directory("root")
    folder2 = Directory("subroot1")
    folder3 = Directory("subroot2")
    file1 = File("file1")
    file2 = File("file2")

    folder1.add_content(folder2)
    folder2.add_content(folder3)
    folder1.add_content(file1)
    folder2.add_content(file2)
    folder1.get_contents()
    print('######################')

    folder1.move_content(file1, folder3)
    folder1.get_contents()
    print('######################')

    folder1.remove_content(file1)
    folder1.get_contents()
    

        