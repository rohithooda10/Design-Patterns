# Iterator Design Pattern

## Overview

The Iterator Design Pattern is a behavioral design pattern that provides a way to access the elements of an aggregate object (e.g., a list) sequentially without exposing the underlying representation. It separates the traversal of a collection from its underlying structure, allowing for various ways to iterate through the elements.

## Use Case

The Iterator pattern is ideal in the following situations:

- When you want to provide a way to access elements of a collection without exposing its internal structure.
- When you need to support multiple traversal methods for a collection.
- When you want to decouple the client code from the collection's specific implementation.

## Implementation

In this code example, we implement the Iterator Design Pattern for creating an `Iterator` and an `Aggregator` relationship. The key components are:

- **Iterator:** The abstract `Iterator` class defines a common interface with methods like `hasNext`, `first`, and `next` for traversing a collection.

- **Concrete Iterator:** The `NumIterator` class implements the iterator interface and provides methods to traverse a collection of integers.

- **Aggregator:** The `ProductManager` class represents an aggregator or a collection. It provides methods to add and remove items and also creates an iterator for the collection.

## How to Use

1. Clone or download this repository.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. The program creates a `ProductManager` instance and adds several products to it.

5. It creates an iterator for the product collection and uses it to traverse the products.

6. The program demonstrates the ability to check for the next item (`hasNext`) and retrieve the first and subsequent items (`first` and `next`).

Feel free to explore and modify the code to better understand the Iterator Design Pattern and its use in providing a way to access elements of a collection in a flexible and decoupled manner.

