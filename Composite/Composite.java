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