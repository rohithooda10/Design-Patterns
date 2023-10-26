# Strategy Design Pattern with Strategy Factory

## Overview

The Strategy Design Pattern with a Strategy Factory is a behavioral design pattern that provides a way to select and use specific algorithms (strategies) at runtime. It allows you to encapsulate various strategies, and a factory creates the appropriate strategy based on client requirements, promoting flexibility and maintainability.

## Use Case

The Strategy pattern with a Strategy Factory is ideal in the following situations:

- When you want to separate the selection of a strategy from the client code to improve maintainability.
- When you have a set of related algorithms and need to choose among them at runtime.
- When you want to avoid direct instantiation of strategy objects at the client side.

## Implementation

In this code example, we implement the Strategy Design Pattern with a Strategy Factory for creating a `PaymentStrategy` and `PaymentManager` relationship. The key components are:

- **Strategy:** The abstract `PaymentStrategy` class defines a common interface with methods for verifying payment and making payments.

- **Concrete Strategies:** The `CreditCardStrategy` and `PaypalStrategy` classes implement the payment strategy interface with specific implementations.

- **Strategy Factory:** The `PaymentStrategyFactory` class creates the appropriate strategy based on the client's method choice.

- **Context:** The `PaymentManager` class represents the context in which a payment strategy is chosen and used. It utilizes the factory to create the strategy and then executes the payment operations.

## UML class diagram
<img width="824" alt="UML" src="https://github.com/rohithooda10/Design-Patterns/assets/109358642/362749e7-d416-463a-94ae-da5e192ada8a">


## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program asks the user to choose a payment method (1 for Credit Card, 2 for Paypal).

5. Depending on the chosen method, the program creates the corresponding payment strategy using the factory.

6. The `PaymentManager` uses the selected strategy to verify and make a payment.

7. The program demonstrates how the Strategy Design Pattern with a Strategy Factory separates the strategy creation from the client code.

Feel free to explore and modify the code to better understand the Strategy Design Pattern with a Strategy Factory and its use in creating and using strategies with flexibility.

