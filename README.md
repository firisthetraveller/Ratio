# Ratio
## Authors
- Aude Pora
- Guy Luong

## General description
`Ratio` is a C++ library that adds rational numbers to the language.

Rational numbers are numbers composed of two integer parts, called numerator and denominator, and are represented as following:

$$r = \frac{numerator}{denominator}, \medspace with \medspace denominator \in \N+$$

## Testing
### Mandatory steps
After downloading or cloning the project, use these commands to build it.
```sh
$ > mkdir build
$ > cd build
$ > cmake ..
$ > make
```

### Documentation
To build the documentation :
```sh
$ > make install
```

The documentation will be located at `build/libRatio/doc/doc-doxygen/html/index.html`.

### Launch the unit tests
They are located in the folder `build/unitTests/`.
There are three of them, ordered by subjective difficulty of implementation.
- `RatioSimpleUnitTests`
- `RatioIntermediateUnitTests`
- `RatioComplexUnitTests`

Some tests are not passed. They are all related to converting floating point numbers to rationals. The method we're using is the [continued fraction](https://en.wikipedia.org/wiki/Continued_fraction) method.

## Features
### Templated library
`Ratio` is templated, it makes the numerator modulable with the different integer types available.

Examples :
```cpp
Ratio<int> a (5, 2);
Ratio<long int> b (7, 4);
```

### Always in the shortest form
Two equally-valued rational numbers will be represented in the same way.

Examples :
```cpp
Ratio<int> a (5, 2);
Ratio<int> b (10, 4);

std::cout << a << std::endl; // prints "5 / 2"
std::cout << b << std::endl; // prints "5 / 2"
```

### Limits
Both $+\infty$ and $-\infty$ are represented, and they occur when the denominator is set to 0.

Syntax :
```cpp
Ratio<int> a = Ratio<int>::PLUS_INF();
Ratio<int> b = Ratio<int>::MINUS_INF();
Ratio<int> c = Ratio<int>(5, 0);

std::cout << a << std::endl; // prints "+infinity"
std::cout << b << std::endl; // prints "-infinity"
std::cout << c << std::endl; // prints "+infinity"
```

### Other constants
| Name | Value |
| ---- | ----- |
| ZERO | 0     |


### Standard operations
All standard operations are implemented.
  | Symbol | Operation      |
  | ------ | -------------- |
  | \+     | addition       |
  | \-     | subtraction    |
  | \*     | multiplication |
  | \/     | division       |
  | \-     | unary minus    |

Example :
```cpp
Ratio<int> a (5, 2);
Ratio<int> b (7, 4);

Ratio<int> c = a + b;
Ratio<int> d = a - b;
Ratio<int> e = a * b;
Ratio<int> f = a / b;
Ratio<int> g = -a;
```

### Comparison operators
  | Symbol | Operation             |
  | ------ | --------------------- |
  | <      | lesser than           |
  | <=     | lesser than or equal  |
  | >      | greater than          |
  | >=     | greater than or equal |
  | ==     | equal                 |
  | !=     | different             |

Example :
```cpp
Ratio<int> a (5, 2);
Ratio<int> b (7, 4);

std::cout << (a < b) << std::endl;
// prints "false"
```


### Other methods
| Name           | Operation                        |
| -------------- | -------------------------------- |
| `r.abs`()      | Absolute value, distance to zero |
| `r.round`()    | Nearest integer                  |
| `r.truncate`() | Nearest integer lower than r     |
| `r.inv`()      | Inverse                          |

### Variadics
| Name                     | Operation           |
| ------------------------ | ------------------- |
| `Ratio<T>::sum`(...)     | Sum of all elements |
| `Ratio<T>::product`(...) | Product             |
| `Ratio<T>::min`(...)     | Smallest element    |
| `Ratio<T>::max`(...)     | Highest element     |

Example :
```cpp
Ratio<int> result = Ratio<int>::sum(
  Ratio<int>(5), Ratio<int>(26, 5),
  Ratio<int>(3, 2), Ratio<int>::convertFromFloat(4.25));
// Contains the sum of 5, 26/5, 3/2 and 4.25 (as a rational), ie. 17/4.

std::cout << result << std::endl;
// Prints 319 / 20.
```

### Exceptions
An exception occurs when dealing with the rational valued with both the numerator and the denominator to 0 (the fraction $\frac{0}{0}$).

### Conversion between rationals and floating point numbers
| Name                                | Operation                                                   |
| ----------------------------------- | ----------------------------------------------------------- |
| `Ratio<T>::convertFromFloat`(float) | Returns a rational valued to the number given               |
| `r.eval`()                          | Returns a floating point number which value is equal to `r` |

### Floating point things
**Note:** All these operations do not work well in the general case.

| Name       | Operation   |
| ---------- | ----------- |
| `r.pow`()  | Power       |
| `r.cos`()  | Cosinus     |
| `r.sqrt`() | Square root |
| `r.exp`()  | Exponential |


## Contribute
### Syntax

In order to contribute, make sure to follow these code guidelines :
- Variable and function names must be in camelCase.
- Class names must be in camelCase, with the first letter in capital : ie. in CamelCase.
- Global constants must be in capitals and words separated by underscores (_).
