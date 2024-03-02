# PROTOTYPE DESIGN PATTERN

A prototype is an existing design.
It is a fully or partially initialized object that you copy and make use of.

> When it's easier to copy an existing object
> to fully initialize new object.

The motivation for prototype design pattern are:

- complex objects aren't created from scratch (e.g: new cars are iteration of old ones)
- we copy (clone) the prototype and customize it (it requires deep copy)
- provides nice API for cloning (e.g: via a Factory)


### Examples
- [C++ way](./copy_ctors.cpp) make deep copy constructors
- [Prototype Factory](./prototype_factory.cpp) hide constructors and provide methods to generate objects from default prototype.
