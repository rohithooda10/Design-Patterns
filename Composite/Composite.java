import java.util.*;

/*
 * Run:
 * javac Composite.java
 * java Main
 */
interface FileComponent{
    String getName();
    void getContents();
    void addContent(FileComponent content);
    void removeContent(FileComponent content);
    void moveContent(FileComponent content, FileComponent dest);
}

class Directory implements FileComponent {
    private String name;
    private List<FileComponent> contents;
    public Directory(String n)
    {
        this.name = n;
        contents = new ArrayList<>();
    }
    @Override
    public String getName()
    {
        return this.name;
    }
    @Override
    public void getContents()
    {
        System.out.print(this.name + "->");
        for(FileComponent content: contents)
        {
            content.getContents();
        }
    }
    @Override
    public void addContent(FileComponent content)
    {
        this.contents.add(content);
    }
    @Override
    public void removeContent(FileComponent content)
    {
        int n = contents.size(), index = -1;
        for(int i = 0; i < n ; i++)
        {
            if(contents.get(i).equals(content))
            {
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            System.out.println("content not found");
            return;
        }
        contents.remove(index);
    }
    @Override
    public void moveContent(FileComponent content, FileComponent dest)
    {
        FileComponent c = content;
        this.removeContent(content);
        dest.addContent(c);
    }
}


class File implements FileComponent {
    private String name;
    public File(String n)
    {
        this.name = n;
    }
    @Override
    public String getName()
    {
        return this.name;
    }
    @Override
    public void getContents()
    {
        System.out.print(this.name + "->");
    }
    @Override
    public void addContent(FileComponent content)
    {
        return;
    }
    @Override
    public void removeContent(FileComponent content)
    {
        return;
    }
    @Override
    public void moveContent(FileComponent content, FileComponent dest)
    {
        return;
    }
}

class Main{
    public static void main(String[] args){
        Directory folder1 = new Directory("root");
        Directory folder2 = new Directory("subroot1");
        Directory folder3 = new Directory("subroot2");
        File file1 = new File("file1");
        File file2 = new File("file2");
        File file3 = new File("file3");

        folder1.addContent(folder2);
        folder2.addContent(folder3);
        folder1.addContent(file1);
        folder1.addContent(file3);
        folder2.addContent(file2);

        System.out.println("Contents of folder1:");
        folder1.getContents();

        System.out.println();

        folder1.moveContent(file1, folder3);
        System.out.println("Contents of folder1 after moving file1 to folder3:");
        folder1.getContents();

        System.out.println();

        folder1.removeContent(file3);
        System.out.println("Contents of folder1 after removing file3:");
        folder1.getContents();
    }
}

// import java.util.ArrayList;
// import java.util.Collections;
// import java.util.List;

// interface FileComponent {
//     public void getName();
//     public void displayContent();
//     public void addContent(FileComponent item);
//     public void removeContent(FileComponent item);
//     public void moveContent(FileComponent item, FileComponent destination);
// }

// class Directory implements FileComponent {
//     private String name;
//     List<FileComponent> contents = new ArrayList<>();
//     Directory(String name)
//     {
//         this.name = name;
//     }
//     public void getName()
//     {
//         System.out.print(name);
//     }
//     public void displayContent()
//     {
//         getName();
//         for(int i = 0; i < contents.size(); i++)
//         {
//             System.out.print("->");
//             contents.get(i).displayContent();
//         }
//         System.out.println();
//     }
//     public void addContent(FileComponent item)
//     {
//         contents.add(item);
//     }
//     public void removeContent(FileComponent item)
//     {
//         int index = -1;
//         for(int i = 0; i < contents.size(); i++)
//         {
//             if(contents.get(i) == item)
//             {
//                 index = i;
//                 break;
//             }
//         }
//         Collections.swap(contents, index, contents.size() - 1);
//         contents.remove(contents.size() - 1);
//     }
//     public void moveContent(FileComponent item, FileComponent destination)
//     {
//         removeContent(item);
//         destination.addContent(item);
//     }
// }

// class File implements FileComponent {
//     private String name;
//     List<FileComponent> contents = new ArrayList<>();
//     File(String name)
//     {
//         this.name = name;
//     }
//     public void getName()
//     {
//         System.out.print(name);
//     }
//     public void displayContent()
//     {
//         getName();
//         return;
//     }
//     public void addContent(FileComponent item)
//     {
//         return;
//     }
//     public void removeContent(FileComponent item)
//     {
//         return;
//     }
//     public void moveContent(FileComponent item, FileComponent destination)
//     {
//         return;
//     }
// }

// class Main {
//     public static void main(String[] args)
//     {
//         Directory folder1 = new Directory("root");
//         Directory folder2 = new Directory("subroot1");
//         Directory folder3 = new Directory("subroot2");
//         File file1 = new File("file1");
//         File file2 = new File("file2");
//         File file3 = new File("file3");

//         folder1.addContent(folder2);
//         folder2.addContent(folder3);
//         folder1.addContent(file1);
//         folder1.addContent(file3);
//         folder2.addContent(file2);

//         System.out.println("Contents of folder1:");
//         folder1.displayContent();

//         System.out.println();

//         folder1.moveContent(file1, folder3);
//         System.out.println("Contents of folder1 after moving file1 to folder3:");
//         folder1.displayContent();

//         System.out.println();

//         folder1.removeContent(file3);
//         System.out.println("Contents of folder1 after removing file3:");
//         folder1.displayContent();
//     }
// }
