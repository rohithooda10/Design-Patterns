# Decorator Design Pattern

## Overview

The Decorator Design Pattern is a structural design pattern that allows you to attach additional behaviors or responsibilities to objects dynamically, without altering their code. It is useful when you need to extend the functionality of individual objects without modifying their classes.

## Use Case

The Decorator pattern is ideal in the following situations:

- When you want to add responsibilities to objects dynamically and transparently.
- When you have a class with many subclasses, and you want to avoid the explosion of subclasses due to different combinations of features.
- When you want to keep classes open for extension but closed for modification.

## Implementation

In this code example, we implement the Decorator Design Pattern for creating a `FoodItem` and `Decorator` relationship. The key components are:

- **Product Interface:** The `FoodItem` class defines an interface with methods for getting the description and price of a food item. Concrete food items, such as `Pizza` and `Burger`, implement this interface.

- **Concrete Products:** The `Pizza` and `Burger` classes represent concrete food items with specific descriptions and prices.

- **Decorator Interface:** The `Decorator` class, which is a subclass of `FoodItem`, serves as the base class for decorators. It holds a reference to a `FoodItem` object.

- **Concrete Decorators:** The `CheeseDecorator` and `SauceDecorator` classes are concrete decorators that add extra features to food items. They extend the behavior of the `FoodItem` they decorate by modifying the description and price.

## UML class diagram
<img width="884" alt="UML" src="https://github.com/rohithooda10/Design-Patterns/assets/109358642/52fa8b73-c6f5-407d-9940-1437f4311583">


## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program creates instances of `Pizza` and `Burger`, representing food items.

5. It then wraps these food items with `CheeseDecorator` and `SauceDecorator` to add extra features to them.

6. The program demonstrates how the Decorator Design Pattern allows for dynamic addition of features to objects without altering their original classes.

Feel free to explore and modify the code to better understand the Decorator Design Pattern and its use in extending the functionality of objects with decorators.

