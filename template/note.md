# C++ Templates
- In C++, the template system was designed to simplify the process of creating functions (or classes) that are able to work with different data types

## Function Templates

* A function templates is a function-like definition that is used to generate one or more overload funcitons, each with a different set of actual types.

### Template parameter declaration

```cpp

template <typename T> // this is the template parameter declaration
T max(T x, T y) // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}

```

### Function template instantiation
* The process of creating functions (with specific types) from function template is call function template instantiation.


### Template argument deduction

