## Как организован механизм генерации случайных чисел в библиотеке random?

Начальное значение *seed* (зерно) передаётся в генератор, который создаёт набор псведослучайных значений. Этот набор значений передаётся в распределение, которое генерирует числа, соответствующие этому распределению.

## Чем отличаются функциональные объекты от функций и лямбда-выражений?

В отличие от функций и лямбда-выражений функциональный объект является объектом, т.е. может иметь собственные поля.

## Какими наборами возможностей обладают итераторы различных категорий?

- Input iterator: конструктор копирования, деструктор, операторы \*, \->, ==, !=, ++ (оба), осуществляет один проход по контейнеру
- Output iterator: конструктор копирования, деструктор, операторы \*, \->, ==, !=, ++ (оба), осуществляет один проход по контейнеру
- Forward iterator: конструктор по умолчанию и копирования, деструктор, операторы \*, \->, ==, !=, ++ (оба), многопроходный.
- Bidirectional iterator: конструктор по умолчанию и копирования, деструктор, операторы \*, \->, ==, !=, ++ (оба), -- (оба), многопроходный.
- Random access iterator: конструктор по умолчанию и копирования, деструктор, операторы \*, \->, ==, !=, >, >=, <, <=, +, -, ++ (оба), -- (оба), многопроходный.

## Какая классификация предлагается для алгоритмов стандартной библиотеки?

- Модифицирующие
- Немодифицирующие
- Перестановочные
- Численные
- Алгоритмы сортировки
- Алгоритмы удаления

## Почему алгоритмы стандартной библиотеки предпочтительнее собственных?

Алгоритмы из стандартной библиотеки, как правило, реализованы оптимальнее и полностью протестированы, что исключает возможность некорректной работы в определённых случаях.