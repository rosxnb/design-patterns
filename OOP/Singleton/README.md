# SINGLETON DESIGN PATTERN

A singleton is a component that is instantiated only once.

Motivations:
- When we want a single instance of object for program lifetime; for instance
    - Database Repository
    - Object Factory
    - Renderer
- When constructor call is expensive
- Prevent user from making new instance of object
- Need to take care of lazy instantiation and thread safety


### Examples
- [Singleton](./singleton.cpp) one instance throughout program.
- [Multiton](./multiton.cpp) fixed multiple instances throughout program.
