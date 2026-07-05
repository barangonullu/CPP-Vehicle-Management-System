# C++ Vehicle Management System

This repository contains a two-phase C++ Object-Oriented Programming (OOP) project. It demonstrates the evolution of a vehicle management system from basic data encapsulation and operator overloading to a complex, hierarchical architecture utilizing inheritance, polymorphism, and dynamic memory allocation.

## Project Structure

The project is divided into two main phases:

### Phase 1: Basic OOP & Operator Overloading (`Phase1-Operator-Overloading` folder)
A foundational vehicle tracking system focusing on robust data validation and object comparison.
* **Key Concepts:** Encapsulation, Data Validation, Operator Overloading (`operator==`), Const Correctness.
* **Features:**
  * Secure data entry with strict validation loops for license plates, chassis numbers, and numeric inputs to prevent runtime crashes.
  * Direct comparison of `Car` objects based on unique chassis and engine numbers using custom operator overloading.

### Phase 2: Inheritance & Polymorphism (`Phase2-Polymorphism-Inheritance` folder)
An advanced insurance calculation system built upon the foundational `Car` class.
* **Key Concepts:** Inheritance, Polymorphism (Virtual Functions), Dynamic Memory Allocation (Pointers), Virtual Destructors.
* **Features:**
  * Hierarchical class structure featuring `PersonalCar`, `CompanyCar`, and `FleetCar` subclasses inheriting from the base `Car` class.
  * Dynamic calculation of insurance premiums using overridden virtual functions tailored to specific vehicle types and business rules.
  * Safe and leak-free memory management utilizing array of pointers and virtual destructors.
