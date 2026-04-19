# C++ Object-Oriented Programming (OOP) Solutions

This repository contains a diverse collection of C++ programs designed to demonstrate the core principles of Object-Oriented Programming (OOP), including **Encapsulation**, **Data Hiding**, **Dynamic Memory Management**, and **Static Members**. 

Each solution focuses on modeling real-world entities (like bank accounts, library books, or digital images) using classes and structures to create modular and reusable code.

## 📂 Project Overview

### 1. Image Processing Utility (`ImageProcessing.cpp`)
Models a digital image using a 3D dynamic array of `Pixel` structures. It includes functionality to calculate the average brightness of an image and identify "bright" pixels based on RGB values.

### 2. Pizza Order System (`PizzaOrderSystem.cpp`)
A management system for food orders that tracks details such as toppings, size, and price. It utilizes constructors and copy constructors to handle order data efficiently.

### 3. Custom String Implementation (`CustomStringClass.cpp`)
A hands-on implementation of a string class. Instead of using `std::string`, this file demonstrates manual memory management (new/delete), case conversion logic, and character search algorithms.

### 4. Savings Account Manager (`SavingsAccountManager.cpp`)
Simulates banking operations for savings accounts. It handles unique account number generation (SA00-SA99), interest rate applications, and balance updates for multiple customers.

### 5. Enhanced Integer Wrapper (`EnhancedInteger.cpp`)
Wraps primitive integers in a class to provide advanced metadata, such as counting set bits (2's complement), calculating leading/trailing zeros, and converting values to Hexadecimal or Octal strings.

### 6. Library Management System (`LibraryManagement.cpp`)
An inventory system for a library. It allows for adding books, updating quantities, and sorting the catalog by author name or book price.

### 7. Student Record System (`StudentRecordSystem.cpp`)
A comprehensive tool for managing academic profiles. It tracks student IDs, names, and enrolled courses. It features dynamic arrays to store grades and automatically calculates the overall GPA.

## 🛠️ Requirements & Compilation

- **Compiler**: Any standard C++ compiler (GCC, Clang, or MSVC).
- **Standards**: C++11 or later is recommended.

To compile any individual file:
```bash
g++ filename.cpp -o output_name
./output_name
