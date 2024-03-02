# FACTORY DESIGN PATTERN

Factory design pattern is responsible solely for the wholesale (not piecewise)
creation of objects.

The motivation for factory design pattern are:

- factories allow you to work with interfaces rather than concrete implementations
- if there are changes in the way objects are created, you only need to update the factory code rather than every place where objects are created
- object creation logic becomes too convoluted
- constructor is not descriptive
    - name mandated by name of containing type
    - cannot overload with same sets of arguments with different name
    - can turn into "optional parameter hell"
- object creation (non-piecewise, unlike [Builder](../Builder/README.md)) can be outsourced to
    - a separate function (Factory Method)
    - that may exist in a separate class (Factory)
    - Can create hierarchy of factories with Abstract Factory


### Examples

1. [Factory Method](./factory_method.cpp)
2. [Factory Class](./faactory_class.cpp)
3. [Abstract Factory](./abstract_factory.cpp)
