# Command Design Pattern

## Overview

The Command Design Pattern is a behavioral design pattern that encapsulates a request as an object, thereby allowing you to parameterize clients with queues, requests, and operations. It promotes loose coupling between the sender (invoker) and the receiver (the object that performs the actual action), and allows for the support of undoable operations.

## Use Case

The Command pattern is ideal in the following situations:

- When you need to decouple an object making a request from the object receiving and handling the request.
- When you want to support undo and redo functionality.
- When you want to queue, log, or schedule requests, and parameterize them.

## Implementation

In this code example, we implement the Command Design Pattern for creating a `Command`, `Receiver`, and `Invoker` relationship. The key components are:

- **Command:** The abstract `Command` class defines a common interface with an `execute` method that concrete commands must implement. Each concrete command encapsulates a specific request to the receiver.

- **Receiver:** The `Document` class represents the receiver, which knows how to perform the actual operations, such as opening and saving a file.

- **Concrete Commands:** The `OpenCommand` and `SaveCommand` classes implement the `execute` method and encapsulate requests to open and save a file, respectively.

- **Invoker:** The `Menu` class acts as the invoker. It holds instances of concrete commands and can execute them when requested.

## UML class diagram


## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program creates a `Document` instance, which represents a file.

5. It creates two concrete commands (`OpenCommand` and `SaveCommand`) and associates them with the `Document`.

6. The `Menu` (invoker) is created with the two commands.

7. The menu is used to execute the open and save commands, which in turn call the corresponding methods on the document.

Feel free to explore and modify the code to better understand the Command Design Pattern and its use in encapsulating requests and actions in a decoupled manner.

