## Ошибка с обнаружением многократно определённого внешнего символа
> header.h
```cpp
void f();
```

> function.cpp
```cpp
#include "header.h"
#include <iostream>

void f()
{
    std::cout << "f";
}
```
> main.cpp
```cpp
#include "header.h"
#include <iostream>

void f()
{
    std::cout << "ff";
}

int main()
{
    f();
    return EXIT_SUCCESS;
}
```
Функция `f()` определена дважды: в файле `function.cpp` и `main.cpp`, поэтому возникает ошибка.

## Ошибка с неразрешённым внешнем символом

> header.h
```cpp
void f();
```

> main.cpp
```cpp
#include "header.h"
#include <iostream>

int main()
{
    f();
    return EXIT_SUCCESS;
}
```
Функция `f()` не определена ни в одном файле проекта, поэтому возникает ошибка.
