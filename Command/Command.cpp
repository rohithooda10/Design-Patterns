#include <iostream>
using namespace std;

// Command
class Command{
public:
    virtual void execute() = 0;
};

// Receiver
class Document{
public:
    void open()
    {
        cout<<"File opened"<<endl;
    }
    void save()
    {
        cout<<"File saved"<<endl;
    }
};

// Concrete commands
class OpenCommand: public Command{
    Document* doc;
public:
    OpenCommand(Document* document)
    {
        doc = document;
    }
    void execute()
    {
        doc->open();
    }
};
class SaveCommand: public Command{
    Document* doc;
public:
    SaveCommand(Document* document)
    {
        doc = document;
    }
    void execute()
    {
        doc->save();
    }
};

// Invoker
class Menu{
    OpenCommand* openCommand;
    SaveCommand* saveCommand;
public:
    Menu(OpenCommand* op, SaveCommand* sv)
    {
        openCommand = op;
        saveCommand = sv;
    }
    void clickOpen()
    {
        openCommand->execute();
    }
    void clickSave()
    {
        saveCommand->execute();
    }
};

int main() {
    Document* document = new Document();
    OpenCommand* openCommand = new OpenCommand(document);
    SaveCommand* saveCommand = new SaveCommand(document);
    Menu* menu = new Menu(openCommand, saveCommand);
    menu->clickOpen();
    menu->clickSave();
}