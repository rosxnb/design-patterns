# INTRODUCTION

The OOP design patterns are categorized into three categories.
This is called **Gamma Categorization** after *Erich Gamma*, one of *Gang Of Four* Book authors.


Category 1: **Creational Design Patterns**

- Deals with the creation(construction) of objects.
- Objects can be created **explicitly** (constructor) or **implicitly** (Dependency Injection, reflection, etc)
- Objects can be crated at one i.e **wholesale** (single statement) or **piecewise** (step-by-step)

**Some of the creational design patterns are:**
- [Builder](./Builder/)
- [Factories](./Factory/)
    - Abstract Factory
    - Factory Method
- [Prototype](./Prototype/)
- [Singleton](./Singleton/)


Category 2: **Structural Design Patterns**

- Concerned with the structure (e.g., class members, class adhering to some interface)
- Many patterns are wrapper that mimic the underlying class interface
- Puts stress on importance of good API design

**Some of the structural design patterns are:**
- Adapter
- Bridge
- Composite
- Decorator
- Facade
- Flyweight
- Proxy


Category 3: **Behavioral Design Patterns**

- These design patterns are all different; no central theme
These solve a particular problem in a particular way with a particular set of concerns.

**Some of the behavioral design patterns are:**
- Chain of Responsibility
- Command
- Interpreter
- Iterator
- Mediator
- Memento
- Observer
- State
- Strategy
- Template Method
- Visitor
