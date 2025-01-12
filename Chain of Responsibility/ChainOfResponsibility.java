import java.util.*;

interface Handler {
    public void setNextHandler(Handler handler);
    public void handle();
}

class HR implements Handler {
    private Handler nextHandler;
    @Override
    public void setNextHandler(Handler handler)
    {
        this.nextHandler = handler;
    }
    @Override
    public void handle() {
        System.out.println("Processed by HR");
        if(this.nextHandler != null)
            this.nextHandler.handle();
    }
}
class Manager implements Handler {
    private Handler nextHandler;
    @Override
    public void setNextHandler(Handler handler)
    {
        this.nextHandler = handler;
    }
    @Override
    public void handle() {
        System.out.println("Processed by Manager");
        if(this.nextHandler != null)
            this.nextHandler.handle();
    }
}
class CEO implements Handler {
    private Handler nextHandler;
    @Override
    public void setNextHandler(Handler handler)
    {
        this.nextHandler = handler;
    }
    @Override
    public void handle() {
        System.out.println("Processed by CEO");
        if(this.nextHandler != null)
            this.nextHandler.handle();
    }
}
class Main {
    public static void main(String[] args)
    {
        Handler hr = new HR();
        Handler manager = new Manager();
        Handler ceo = new CEO();
        hr.setNextHandler(manager);
        manager.setNextHandler(ceo);
        hr.handle();
    }
}