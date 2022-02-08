## Пути нормального выполнения

1.  Если `e.title() == "CEO" || e.salary() > 100000`
    ```cpp
    std::cout << e.name() << " " << e.surname() << " is overpaid.\n";
    return e.name() + " " + e.surname();
    ```
    
2.  Если `e.title() != "CEO" && e.salary() <= 100000`
    ```cpp
    std::cout << e.name() << " is not overpaid.\n";
    return e.name() + " " + e.surname();
    ```

## Пути выполнения с исключениями.
Выбросы исключений возможны в:  
1. `e.title()` (3)
2. `operator==` (3)
3. `e.salary()` (3)
4. `operator>` (3)
5. `e.name()` (5)
6. `operator<<` (5)
7. `e.surname()` (5)
8. `operator<<` (5)
9. `e.name()` (9)
10. `operator<<` (9)
11. `e.name()` (12)
12. `operator+` (12)
13. `e.surname()` (12)
14. `operator+` (12)  

*В `()` указан номер строки*

Всего 16 путей.