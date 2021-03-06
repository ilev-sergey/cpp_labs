## Что такое контекстное переключение задач?

Контекстным переключением задач называется процесс обработки нескольких задач, при котором происходит переход между задачами с сохранением состояния прерванной задачи.

## Назовите основные подходы к организации параллелизма?

- Процессы (обмен данными происходит между процессами)
- Потоки (обмен данными происходит между потоками через общий участок памяти)

## Что может влиять на производительность параллельных алгоритмов?

- Количество доступных ядер
- Количество выполняемых задач
- Объём рабочих данных
- Конкуренция за данные
- Ложное разделение

## Как в стандартной библиотеке реализована концепция асинхронного исполнения?

`std::async`

## Что нужно учитывать при замене последовательной реализации алгоритма на параллельную?

- Количество данных
- Сложность задач
- Доля кода, которая может быть распараллелена