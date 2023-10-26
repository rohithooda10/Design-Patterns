# Chain of Responsibility Design Pattern

## Overview

The Chain of Responsibility Design Pattern is a behavioral design pattern that allows you to pass a request along a chain of handlers. Each handler decides either to process the request or pass it to the next handler in the chain. This pattern helps to decouple the sender and receiver of a request and allows multiple objects to handle the request without the sender needing to know which object will ultimately process it.

## Use Case

The Chain of Responsibility pattern is ideal in the following situations:

- When you want to pass a request to a chain of handlers and avoid explicitly specifying the receiver.
- When you have multiple objects that can handle a request, and you want to determine the receiver dynamically.
- When you want to achieve flexibility in handling the request, allowing you to add or remove handlers without affecting the client.

## Implementation

In this code example, we implement the Chain of Responsibility Design Pattern for creating a chain of handlers. The key components are:

- **Handler:** The abstract `Handler` class defines a common interface with a `handle` method for handling requests and a `setNextHandler` method to set the next handler in the chain.

- **Concrete Handlers:** The `Manager`, `HR`, and `CTO` classes implement the `handle` method and determine whether to process the request or pass it to the next handler in the chain.

## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program creates three concrete handlers: `Manager`, `HR`, and `CTO`.

5. The handlers are linked in a chain by setting the next handler for each handler.

6. The `Manager` initiates the handling process by calling `handle`.

7. The request is passed along the chain of handlers. Each handler decides whether to process it or pass it to the next handler.

8. The program displays messages indicating which handler successfully processed the request.

Feel free to explore and modify the code to better understand the Chain of Responsibility Design Pattern and its use in handling requests through a chain of handlers.

