## Что означает полнота по Тьюрингу в теории вычислимости?

Полной по Тьюрингу называется вычислительная система, в которой можно создать машину Тьюринга.

## Как можно использовать вычисления на этапе компиляции?

Во время компиляции могут быть вычислены различные математические величины, задающиеся рекуррентными формулами, суммы различных рядов и т.д.

## Какие языковые механики работают на этапе компиляции?

- Выбор специализации шаблона
- Рекурсивное инстанцирование шаблонов
- SFINAE
- `constexpr` переменные, функции, if

## Какие ограничения имеет метапрограммирование шаблонов?

- Ограничение количества уровней рекурсивного инстанцирования
- Ограничения по работе с памятью

## Как устроено гибридное метапрограммирование шаблонов?

При гибридном метапрограммировании общая структура кода вычисляется во время компиляции, а конкретный результат — во время выполнения.