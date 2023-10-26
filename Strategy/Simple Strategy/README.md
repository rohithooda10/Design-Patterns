# Strategy Design Pattern

## Overview

The Strategy Design Pattern is a behavioral design pattern that defines a family of algorithms, encapsulates each one, and makes them interchangeable. It allows you to select an algorithm's implementation at runtime, providing flexibility and reducing the need for conditional statements in your code.

## Use Case

The Strategy pattern is ideal in the following situations:

- When you have a set of related algorithms and want to make them interchangeable without altering the client code.
- When you want to isolate the implementation details of an algorithm from the client code.
- When you want to avoid the proliferation of conditional statements in your code for selecting different behaviors.

## Implementation

In this code example, we implement the Strategy Design Pattern for creating a `PaymentStrategy` and `PaymentManager` relationship. The key components are:

- **Strategy:** The abstract `PaymentStrategy` class defines a common interface with methods for verifying payment and making payments.

- **Concrete Strategies:** The `CreditCardStrategy` and `PaypalStrategy` classes implement the payment strategy interface and provide specific implementations for payment methods.

- **Context:** The `PaymentManager` class represents the context in which a payment strategy is chosen and used. It can accept different payment strategies and execute payment operations.

## UML class diagram
<img width="674" alt="UML" src="https://github.com/rohithooda10/Design-Patterns/assets/109358642/1b3cb57d-c5f4-436e-bf00-2fa96709678b">

## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program asks the user to choose a payment method (1 for Credit Card, 2 for Paypal).

5. Depending on the chosen method, the program creates the corresponding payment strategy and the `PaymentManager`.

6. The `PaymentManager` uses the selected strategy to verify and make a payment.

7. The program demonstrates the flexibility of switching payment strategies without altering the client code.

Feel free to explore and modify the code to better understand the Strategy Design Pattern and its use in making interchangeable algorithms for payment methods.

