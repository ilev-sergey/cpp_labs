## Какие концепции лежат в основе стандартной библиотеки?

- Контейнер — класс, предназначенный для хранения и организации объектов определённого типа данных
- Итератор — объект, способный перебирать элементы класса-контейнера
- Алгоритм — алгоритмическая операция (над контейнерами и другими последовательностями)
- Функциональный объект (функтор) — объект, имеющий функцию вызова (создаётся с помощью перегрузки `operator()` в определении класса объекта)
- Адаптер — класс, преобразующий интерфейс объекта
- Аллокатор — объект, отвечающий за распределение памяти для элементов контейнера
- Предикат — функтор с типом возврата `bool`. Используются в алгоритмах поиска и сортировки (проверка на удовлетворение объектом неких свойств или результат сравнения двух объектов по определённому признаку)

## Зачем в проектах используются системы контроля версий?

- Можно "откатиться" на предыдущую версию проекта при появлении каких-то неисправностей
- Удобное отслеживание изменений (автор, время, краткий комментарий, содержание изменения)
- Удобная синхронизация проекта при работе в команде
- Безопасное хранение файлов проекта (одновременное хранение файлов и локально, и на сервере)
- Удобная разработка и тестирование новой функциональности продукта (за счёт наличия веток и возможности отката)

## Из каких основных действий состоит взаимодействие с Git?

- `clone` — клонирование существующего репозитория
- `pull` — "подтягивание" новых коммитов из удалённого репозитория
- `add` — добавление изменений в индекс
- `commit` — коммит изменённого состояния
- `checkout` — переход в другую ветку
- `merge` — слияние выбранной ветки с текущей веткой
- `push` — отправка новых локальных коммитов в удалённый репозиторий
- `rebase` — перемещение последовательности коммитов к новому коммиту или их объединение

## Когда следует создавать отдельные ветки для разработки?

Отдельные ветки создаются при разработке нового функционала, чтобы можно было добавить и протестировать новые возможности без вмешательства в основную ветку с рабочим и протестированным проектом. По окончании разработки выполняется её `merge` в основную ветку или `rebase` с указанием на конечное состояние основной ветки (если поддерживается линейная история проекта).

## Какие основные элементы содержатся в библиотеке chrono?

- `std::chrono::duration` — тип интервала времени, характеризуется типом количества периодов и дробью `std::ratio`

- `std::chrono::time_point` — тип момента времени, характеризуется интервалом времени и некоторым начальным моментом времени (определяется таймером)

- clocks - таймеры (`system_clock`, `steady_clock`, `high_resolution_clock`)

[*Примеры использования*](https://github.com/ilev-sergey/cpp_labs/blob/master/2nd_semester/Task1/chrono_examples.cpp) (C++20)