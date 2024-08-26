#include <bits/stdc++.h>

class FileComponent{
public:
    virtual void listContents() = 0;
    virtual void add(FileComponent* a) = 0;
    virtual void move(FileComponent* a, FileComponent* b) = 0;
};

class File: public FileComponent
{
    string name;
public:
    File(string a)
    {
        name = a;
    }
    void listContents()
    {
        cout<<"Name:"<<name<<endl;
    }
    void add(FileComponent* a)
    {
    cout<<"File cant contain"<<endl;
    }
    void move(FileComponent* d, FileComponent* newComp)
    {
    cout<<"File cant move"<<endl;
    }
};

class Directory: public FileComponent
{
    string name;
    vector<FileComponent*> contents;
public:
    Directory(string a)
    {
        name = a;
    }
    void add(FileComponent* a)
    {
        contents.push_back(a);
    }
    void listContents()
    {
        cout<<"Directory:"<<name<<endl;
        for(auto &obj: contents)
          obj->listContents();  
    }
    void move(FileComponent* d, FileComponent* newComp)
    {
        // removing "newComp" from my own content and adding to "d"
        int index= 0;
        for(int i = 0; i < contents.size(); i++)
        {
            if(contents[i] == newComp) 
            {
                index = i;
                break;
            }
        }
        swap(contents.back(), contents[index]);
        contents.pop_back();
        d->add(newComp);
    }
};


int main() {
    FileComponent* root = new Directory("Root");
    FileComponent* f1 = new File("rohit");
    FileComponent* f2 = new File("hooda");
    
    FileComponent* sub = new Directory("Sub");
    FileComponent* newSub = new Directory("new Sub");
    root->add(f1);
    sub->add(newSub);
    newSub->add(f2);
    root->add(sub);
    // sub->listContents();
    sub->move(root, newSub); // moving "newSub" from "sub" to "root"
    newSub->listContents();
}
