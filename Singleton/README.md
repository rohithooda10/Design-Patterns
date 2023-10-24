# Singleton Design Pattern

## Overview

The Singleton Design Pattern is a creational design pattern that ensures a class has only one instance and provides a global point of access to that instance. It's useful when you want to control the creation and access to a single, shared resource, such as a configuration manager, a logging service, or a database connection.

## Use Case

The Singleton pattern is ideal in the following situations:

- When you need to ensure that there is only one instance of a class to control access to a shared resource.
- When you want to provide a global point of access to that instance to coordinate actions within an application.

## Implementation

In this code example, we implement the Singleton Design Pattern for creating a `Logger` class. The key components are:

- **Product (Logger):** The `Logger` class represents the object that will have a single instance. It contains attributes like `loggerType` and `timeframe` and provides a `display` method to show its properties.

- **Singleton Class (LoggerSingleton):** This class is responsible for controlling the creation and access to the `Logger` instance. It uses a double-checking lock to ensure thread-safety when creating the instance.

## UML class diagram

![UML]()

## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program creates a `Logger` instance through the `LoggerSingleton`, ensuring that only one instance is created.

5. It then displays the properties of the `Logger` instance, showcasing that it's the same instance throughout the program.

Feel free to explore and modify the code to better understand the Singleton Design Pattern and its use in ensuring the uniqueness of an object.

