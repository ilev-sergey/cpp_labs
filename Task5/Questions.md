## На чём основано объектно-ориентированное программирование?

* Абстракция (использование минимального набора данных и функций для описания объекта).

* Инкапсуляция (объединение данных и функций в одной сущности).

* Наследование (производные классы наследуют свойства базового).

* Полиморфизм (одинаковый интерфейс с разной реализацией).

## Какие аспекты следует учитывать при проектировании классов?

* Использование `private` спецификатора для данных, которые не должны изменяться извне.

* Использование `public` спецификатора для функций-членов, которые работают с данными класса.

* Взаимодействие с данными из `private` секции  происходит через геттеры и сеттеры.

* Для данных, характеризующие класс в целом, а не его экземпляр, следует использовать `static` переменные.

## Почему удобно разделять классы на интерфейс и реализацию?

Такое разделение позволяет упростить работу с классом для пользователя, поскольку для использования класса требуется лишь работа с простым интерфейсом, а не понимание его сложной реализации.

## Чем внутреннее связывание отличается от внешнего связывания?

...

## Какими особенностями обладают именованные пространства имён?

* Пространства имён позволяют разрешить конфликт имён, который возникает, когда два одинаковых идентификатора находятся в одной области видимости.

* Допускается объявление пространства имён в нескольких местах. При этом содержание каждого из объявленных блоков будет принадлежать пространству имён.

* Возможно использование вложенных пространств имён.