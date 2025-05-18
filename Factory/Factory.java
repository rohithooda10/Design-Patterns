/*
 * Run:
 * javac Factory.java
 * java Main
 */

interface Shape {
    void setLength(Double x);
    Double getArea();
}

class Square implements Shape {
    private Double len;
    public void setLength(Double x){
        this.len = x;
    }
    public Double getArea() {
        return len * len;
    }
}

class Circle implements Shape {
    private Double len;
    public void setLength(Double x){
        this.len = x;
    }
    public Double getArea() {
        return len * Math.PI * len;
    }
}

public class Factory {
    public Shape getShape(String name) {
        if(name.equals("square")) return new Square();
        else return new Circle();
    }
}

class Main {
    public static void main(String[] args){
        Factory shapeFactory = new Factory();
        Shape shape = shapeFactory.getShape("circle");
        shape.setLength(10.0);
        System.out.println("Area: " + shape.getArea().toString());
    }
}