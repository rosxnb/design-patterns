# BUILDER DESIGN PATTERN

> When piecewise object construction is complicated,
> provide an API for doing it succinctly.

Builder design pattern is used to make object piecewise (step-by-step).

- A builder is a separate component for building an object
- Can either give builder a constructor or return it via a static function
- To make builder fluent, return by reference (`this` pointer)
- Different facets of an object can be built with different builders working in tandem (together) via a base class.


### Examples

- [html_builder](./html_builder.cpp) shows use of `HTMLBuilder` class to build instance of `HTMLElement` class.
- [groovy_style_html_builder](./groovy_style_html_builder.cpp) shows use of HTML like structure inside C++.
- [facets](./facets.cpp) shows multiple builders used to build an object of `Person` class.
