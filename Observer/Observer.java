import java.util.HashSet;
import java.util.Set;

interface Observer {
    void notified();
} 

class ConcreteObserver implements Observer{
    String name;
    ConcreteObserver(String name)
    {
        this.name = name;
    }
    public void notified() {
        System.out.println(name + " was notified.");
    }
}

class Subject {
    Set<Observer> observers = new HashSet<>();
    public void addObserver(Observer obs)
    {
        observers.add(obs);
    }
    public void removeObserver(Observer obs)
    {
        observers.remove(obs);
    }
    public void notifyObservers()
    {
        for(Observer obs: observers)
        {
            obs.notified();
        }
    }
}

class Main {
    public static void main(String[] args) 
    {
        Subject subject = new Subject();
        Observer first = new ConcreteObserver("First");
        Observer second = new ConcreteObserver("Second");
        subject.addObserver(first);
        subject.addObserver(second);
        subject.notifyObservers();

        subject.removeObserver(second);
        subject.notifyObservers();
    }
}
