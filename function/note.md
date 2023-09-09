# Namespace

* The :: symbol is an operator called **scope resolution operator**

* When an identifier inlucdes namespace preix, the identifier is called a **qualied name**

## Using namespace std
* Another way to access identifier inside a namespace is to use a **directive statement**

### const vs constexpr

**Constant Expression**

- A constant expression is an expression that can be evaluated by the
compiler at compile-time.
- To be a constant expression, all the value in the expression must be
known at compile-time ( and all of the operators and functions called must support compile-time evaluation)
- Evaluating constatn expressions at compile-time makes our compilation take longer, but such expression only need to be evaluated once (rather than every time the program is run). The rusulting executables are faster and use less memory.

**Compile-time const**
- A const variable is a compile-time constant if its initializer is a constant expression.

**Runtime const**
- any const variable that is initialized with a non-constant expression is a runtime constant.

**The `constexpr` keywork