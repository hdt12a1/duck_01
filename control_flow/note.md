## Constexpr if statements
* C++17 introduces the constexpr if statement, which requires the conditional to be a constant expression. the conditional of a constexpr if statement will be evaluated at compile-time.

```cpp

#include <iostream>

int main()
{
	constexpr double gravity{ 9.8 };

	if constexpr (gravity == 9.8) // now using constexpr if
		std::cout << "Gravity is normal.\n";
	else
		std::cout << "We are not on Earth.\n";

	return 0;
}
```


## switch case

* We start a switch statement by using a switch keyword, followded by parentheses with the conditional expression that we would like to evaluate inside.

> [!NOTE]
> The one restriction is that the condition must evaluate to an interger type or an enumerated type or be convertible to one.

### Brace initialization disalows narrowing conversions

```cpp

int main()
{
    int i { 3.5 }; // won't compile

    return 0;
}
```
