## Что обеспечивает идеальная передача и как она реализуется?

Идеальная передача обеспечивает передачу параметров в другую функцию без создания временных переменных.

Можно реализовать с помощью многократной перегрузки "обёрточной" функции (чем больше параметров, тем больше перегрузок):

```cpp
template <typename T>
void wrapper(T& t)          { func(t); }

template <typename T>
void wrapper(const T& t)    { func(t); }
```

Либо с помощью использования сжатия ссылок и особого вывода типа для rvalue-ссылок:                                                             <a name="reference-collapse"></a>

> Сжатие ссылок:  
> & + & → &  
> && + & → &  
> & + && → &  
> && + && → &&

> Особый вывод типа для rvalue-ссылок:                                                                                                                      <a name="rvalue"></a>
> ```cpp
> void f(T&& t) {}
> ```
> 
> ```cpp
> Type arg;
> void f(arg);
> ```
> arg is rvalue → T is Type  
> arg is lvalue → T is Type&

Реализация:

```cpp
template <typename T>
void wrapper(T& t)
{
    func(forward<T>(t));
}

template<typename T>
T&& forward(T& t) 
{
    return static_cast<T&&>(t);
}
```

## Какая ссылка называется пробрасывающей или универсальной?

Универсальной ссылкой называется rvalue-ссылка в контексте вывода типов ([см. выше](#rvalue)).

## В чём заключается идиома SFINAE применительно к шаблонам?

> SFINAE — substitution failure is not an error.

При неудачной попытке инстанцирования шаблона функции компилятор не выбрасывает ошибку, а пытается инстанцировать шаблон другой подходящей перегрузки (если она существует).

```cpp
(1) template<typename T>
    void f(T, typename T::iterator);
(2) template<typename T>
    void f(T, T);
```

При вызове `f(1, 2)` происходит попытка инстанцирования шаблона 1. Так как тип `int` не является классом, содержащим `iterator`, подстановка типа не удаётся, компилятор переходит к следующему шаблону.


## Как можно использовать вспомогательный шаблон `enable_if`?

`enable_if` может быть использован как дополнительный аргумент функции:

```cpp
template<typename T>
void f(typename std::enable_if< condition, T >::type t) {}
```

как тип возвращаемого значения функции:

```cpp
template<typename T>
auto f() -> typename std::enable_if< condition, T >::type {}
```

как параметр шаблона класса:

```cpp
template<typename T, 
         typename B = std::enable_if< condition, bool >::type
        >
class C {};
```

как параметр шаблона функции:

```cpp
template<typename T, 
         typename B = std::enable_if< condition, bool >::type
        >
void g() {}
```

## Какие правила вывода применяются при работе с шаблонами?

При выводе типа шаблона применяются [сжатие ссылок](#reference-collapse) и [особый вывод типа для rvalue-ссылок](#rvalue).