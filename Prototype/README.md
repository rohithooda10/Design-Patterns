# Prototype Design Pattern

## Overview

The Prototype Design Pattern is a creational design pattern that allows you to create new objects by copying an existing object, known as the prototype. The pattern is useful when you need to create multiple instances of objects that share similar properties and initial states.

## Use Case

The Prototype pattern is ideal in the following situations:

- When you want to create new objects by copying an existing object, making it easier to create similar objects with different attributes.
- When the construction of new objects is more efficient or convenient by copying an existing object.
- When you want to maintain a collection of related objects, and each new object can be derived from an existing one with some modifications.

## Implementation

In this code example, we implement the Prototype Design Pattern for creating `Person` objects. The key components are:

- **Prototype (Person):** The `Person` class represents the object that will be cloned. It contains attributes like name, age, and roll number.

- **Prototype Interface (PersonPrototype):** An abstract class or interface that declares a method for cloning an object, which concrete prototypes must implement.

- **Concrete Prototype (Person):** The `Person` class implements the clone method, allowing it to create a new instance by copying an existing one.

## UML diagram
![UML](https://github.com/rohithooda10/Design-Patterns/tree/163bd395e312e7524810b0e952a8c8c970deed17/Prototype/UML.png)

## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program creates a `Person` object and then clones it to create another person.

5. It displays the original and cloned persons, demonstrating the ability to duplicate objects with similar properties.

Feel free to explore and modify the code to better understand the Prototype Design Pattern and its use in creating objects by copying an existing prototype.

