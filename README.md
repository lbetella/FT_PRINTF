*This project has been created as part of the 42 curriculum by lbetella.*

# ft_printf - Because ft_putnbr() and ft_putstr() aren't enough

## Description

**ft_printf** is a project from the 42 school common core curriculum. The main goal of this project is to recode the standard C library function `printf()` from `<stdio.h>`.

Through this project, we learn how to implement **variadic functions** in C (functions that accept a variable number of arguments) using the `<stdarg.h>` library (`va_list`, `va_start`,`va_arg`,`va_end`), while writing modular, well-structured, and extensible code. Once validated, `ft_printf()` can be integrated into `libft` for future C projects at 42.

### Supported Conversions

| Specifier | Description |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | Prints a `void *` pointer argument in hexadecimal format (`0x...`). |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a literal percent sign. |

## Algorithm and Data Structure Justification

### 1. Data Structures

* **`va_list` (`<stdarg.h>`)**: Since the number and types of arguments passed to `ft_printf` are unknown at compile time, `va_list` is used to iterate sequentially through the stack/registers containing the variadic arguments.
* **Direct Unbuffered Output (`write`)**: As required by the subject, the internal buffer management of the original `printf()` is not implemented. To keep memory usage minimal and avoid heap allocation overhead (`malloc`/`free`) and potential memory leaks, characters are written directly to the standard output (`fd 1`) via the `write()` system call.

### 2. Algorithm Choice

1. **Single-Pass String Traversal ($O(N)$ Time Complexity)**:
   The function iterates through the `str` string character by character in a single pass:
   * Regular characters are immediately output using `write(1, &str[i], 1)` and added to the total printed character count.
   * When a `%` delimiter is found, the parser advances to the next character to evaluate the conversion specifier.

2. **Modular Dispatcher Pattern**:
   A dispatcher function evaluates the character following `%` and routes the `va_list` argument to the appropriate conversion helper function (character, string, signed integer, unsigned integer, hexadecimal, or pointer). This keeps functions short, compliant with the 42 Norm, and easy to maintain or extend.

3. **Recursive Base Conversion ($O(\log_b(V))$ Space & Time)**:
   For some numerical conversions (`%x`, `%X`,), a recursive division and modulo algorithm is used (`n / x` and `n % x`) were x is the base for hexadecimal "0123456789abcdef" or "0123456789ABCDEF".
   * **Justification**: Recursion naturally orders digits from most significant to least significant without allocating heap memory (`malloc`). Because a 64-bit unsigned integer (`uintptr_t` for `%p`) has at most 16 hexadecimal digits (or 20 decimal digits), the maximum recursion depth never exceeds 20 stack frames, ensuring zero risk of stack overflow and optimal execution speed.

## Instructions

### Prerequisites

* A C compiler (`cc` / `gcc` / `clang`)
* `make` and `ar` utilities

### Compilation

Clone the repository and run `make` at the root of the project to compile the static library `libftprintf.a`:

```bash
git clone <repository_url> ft_printf
cd ft_printf
make
```

Available `Makefile` rules:

* `make` or `make all`: Compiles the source files and generates `libftprintf.a`.
* `make bonus`: Compiles the project including the bonus files (if applicable).
* `make clean`: Removes the object files (`.o`).
* `make fclean`: Removes the object files and the `libftprintf.a` library.
* `make re`: Executes `fclean` followed by `all`.

### Usage

To use `ft_printf` in your project, include `ft_printf.h` in your C file and link `libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d, Hex: %x, Pointer: %p\n", "42", 42, 42, &count);
    ft_printf("Total characters printed: %d\n", count);
    return (0);
}
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

## Resources

### Classic References

* **Linux Manual Pages**:
  * `man 3 printf` — Official specification of format strings, conversion specifiers, and return values.
  * `man 3 stdarg` — Documentation on variable argument lists (`va_start`, `va_arg`, `va_end`, `va_copy`).
* [cppreference.com - Variadic functions](https://en.cppreference.com/w/c/variadic) — Technical reference for variadic arguments and default argument promotions in C.
* [GNU C Library (glibc) - Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html) — Standard behavior and edge cases of `printf`.

### Use of AI

In accordance with the 42 AI instructions, AI tools were used strictly as a learning assistant and documentation aid, specifically for:

* **Conceptual Understanding**: Clarifying how variadic macros (`va_start`, `va_arg`, `va_end`) handle type promotion in C (such as `char` and `short` being promoted to `int`).
* **Edge Case Verification**: Reviewing standard `printf` behavior on edge cases such as passing a `NULL` pointer to `%s` and `%p`.
* **Documentation**: Structuring and formatting this `README.md` file in compliance with Chapter V of the project subject.
* *No project source code was generated or copied from AI.*
