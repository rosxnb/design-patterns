# SOLID DESIGN PRINCIPLES
SOLID design principles were introduced by *Robert C. Martin* aka *Uncle Bob*.

It comprises of five design principles:

#### Single Responsibility Principle

- A class should have only one reason to change
- Separation of concerns: different classes handling different independent tasks/problems

A class should have primary responsibility and it should not take other responsibility.

In example program at [single_responsibility_principle](./single_responsibility_principle.cpp),
the `Journal` class should not be concerned with saving file. User might want to save journal to
some file or some database and this is handled with separate class `PersistenceManager`.



#### Open Closed Principle

- Classes should be open for extension but closed for modification

A class should be open for extension (i.e through inheritance)
but the class should not be modified (don't add new member functions).

In example program at [open_closed_principle](./open_closed_principle.cpp),
the `ProductFilter` class is used to add new filter constraints for the `Product`
class. Several specification are constructed by deriving from `Specification` abstract class
which provides `is_satisfied` method interface that can be utilized by filter class in `filter`
method.

> NOTE: The example also implements [Specification Pattern](https://enterprisecraftsmanship.com/posts/specification-pattern-c-implementation/)



#### Liskov Substitution Principle

- You should be able to substitute a base type for subtype

This states that substituting a derived class in places(like functions) where
base class is used should not break code and expected behaviour of program.

In example program at [liskov_substitution_principle](./liskov_substitution_principle.cpp),
the function `process` breaks logically with `Square` class which is derived from `Rectangle` class
when `expected area ≠ calculate area`.

This can be solved through various method:
- provide `is_square` method in `Rectangle` class instead of inheriting.
- use a Factory method to create `Rectangle` and `Square` objects.



#### Interface Segregation Principle

- Don't put too much into an interface; split into separate interfaces
- YAGNI: You Ain't Going to Need It

This simply says do not overcrowd the interface forcing the inheriting class to implement potentially
not needed functionality. Example at [interface_segregation_principle](./interface_segregation_principle.cpp).


#### Dependency Inversion Principle

- High-level modules should not depend of low-level modules. Both should depend of abstraction (Interface or Abstract Class).
- Abstractions should not depend of details. Details should depend on abstractions.

Example can be found at [dependency_inversion_principle](./dependency_inversion_principle.cpp).
