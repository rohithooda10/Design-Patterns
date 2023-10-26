# Observer Design Pattern

## Overview

The Observer Design Pattern is a behavioral design pattern that defines a one-to-many dependency between objects, so that when one object changes its state, all its dependents (observers) are notified and updated automatically. This pattern is often used in situations where one object needs to notify a group of other objects about changes.

## Use Case

The Observer pattern is ideal in the following situations:

- When you need to maintain consistency between related objects without making them tightly coupled.
- When you want to notify multiple objects about changes without them having explicit knowledge of each other.
- When you need to implement distributed event handling systems.

## Implementation

In this code example, we implement the Observer Design Pattern for creating an `Observer` and `Subject` relationship. The key components are:

- **Observer:** The abstract `Observer` class defines a common interface with a `notify` method that concrete observers must implement.

- **Concrete Observer:** The `ConcreteObserver` class implements the `notify` method and represents the objects that want to be notified of changes. They can react to notifications in their specific ways.

- **Subject:** The `Subject` class maintains a list of observers and provides methods to attach, detach, and notify observers. When a subject's state changes, it notifies all attached observers.

## UML class diagram
<img width="649" alt="UML" src="https://github.com/rohithooda10/Design-Patterns/assets/109358642/b8143bf1-7231-4a69-90e7-fab734ada66b">


## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program creates a `Subject` instance (e.g., an order) and two `ConcreteObserver` instances (e.g., "Customer" and "Delivery").

5. It attaches both observers to the subject and then updates the subject's status.

6. After that, it detaches one observer and updates the subject's status again to show how observers are notified.

Feel free to explore and modify the code to better understand the Observer Design Pattern and its use in notifying and updating dependent objects when a subject's state changes.

