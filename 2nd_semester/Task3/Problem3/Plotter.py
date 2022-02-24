import numpy as np                   # работа с массивами и линейной алгеброй
import matplotlib.pyplot as plt      # для отрисовки графиков
import pandas as pd                  # для чтения и работы с данными
import math                          # для работы с мат. функциями
import matplotlib as mpl             # для управления стилем рисунков 
from scipy.optimize import curve_fit # фитирующая процедура
import seaborn as sns

def import_data(name, separator = ','):
    """Возвращает данные из файла
    
    name: имя файла в формате 'data.csv' или
          путь к файлу в формате './data/data.csv'
    sep: разделитель значений ('\s+' - для пробелов)
    """
    return pd.read_csv(f"./data/{name}", sep = separator)

def get_columns(data):
    """Разделяет данные по столбцам, удаляет NaN-значения"""
    return [data.iloc[:, i].dropna() for i in range(len(data.columns))]

def line(x, k, b):
    """Параметрическая прямая"""
    return k*x + b

def parabola(x, a, b, c):
    """Параметрическая парабола"""
    return a*x**2 + b*x + c

def cubic_function(x, a, b, c, d):
    """Параметрическая кубическая функция"""
    return a*x**3 + b*x**2 + c*x + d

def polynom5(x, a0, a1, a2, a3, a4, a5):
    """Параметрический полином пятой степени"""
    return a5*x**5 + a4*x**4 + a3*x**3 + a2*x**2 + a1*x + a0

def polynom10(x, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10):
    """Параметрический полином десятой степени"""
    return a10*x**10 + a9*x**9 + a8*x**8 + a7*x**7 + a6*x**6 + a5*x**5 + a4*x**4 + a3*x**3 + a2*x**2 + a1*x + a0

def exponent(x, a, b):
    """Параметрическая экспонента"""
    return np.exp(a*x) + b

def log(x, a, b):
    """Параметрический логарифм"""
    return a*np.log(x) + b

def approximation(function, x, y):
    """Аппроксимация функцией function"""
    return curve_fit(f = function, xdata = x, ydata = y)

def print_params(params, cov):
    """Печать параметров"""
    for counter, param in enumerate(params):
        print(f"{counter}: {param:.3} \u00B1 {np.sqrt(cov[counter][counter]):.2}")

def save_figure(name):
    """Сохранение графика"""
    plt.savefig(f"./results/{name}")

def func(x, a):
    return a*x**(1.25)*np.log(x)

# Импорт данных
data = import_data('data.csv')
functions, collisions = get_columns(data)
x = [0, 1,2 ,3 ,4,5,6,7,8]

# Размер шрифта
mpl.rcParams['font.size'] = 16
# Размер холста
plt.figure(figsize=(12,7))
# Отображение сетки
plt.grid(visible=True, which='major', axis='both', alpha=1)
plt.grid(visible=True, which='minor', axis='both', alpha=0.5)

# Подписи к графику
plt.title(r"Hist of collisions for differrent hash-functions (log scale)")
plt.ylabel(r"collisions")
plt.xlabel(r"data size")
plt.yscale('log')
plt.bar(x, collisions, color = 'black', label = '')
#functions.value_counts().plot(kind = 'bar')
## Построение графика
ax = plt.gca()

xtick_labels = functions
xticks = [i for i in range(9)]
ax.set_xticks(xticks)
ax.set_xticklabels(xtick_labels, size=12)

## Сохранение графика
save_figure('graph')

# Отображение графика
plt.show()