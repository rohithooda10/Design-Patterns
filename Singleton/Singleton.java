import java.util.*;
/*
 * Run:
 * javac Singleton.java
 * java Main
 */
class Logger {
    public String type;
    public Logger(String t)
    {
        this.type = t;
    }
    public void log(String msg)
    {
        System.out.println("Logged by:" + this.type + " - " + msg);
    }
}

class Singleton {
    private static Logger instance;
    public static Logger getInstance(String type)
    {
        if(instance == null)
        {
            synchronized(Singleton.class)
            {
                if(instance == null)
                {
                    instance = new Logger(type);
                }
            }
        }
        return instance;
    }
}

class Main{
    public static void main(String[] args)
    {
        Logger logger1 = Singleton.getInstance("DEBUG");
        logger1.log("Hello World");
        
        Logger logger2 = Singleton.getInstance("INFO");
        logger2.log("Hello World");
    }
}