import numpy as np                   # работа с массивами и линейной алгеброй
import matplotlib.pyplot as plt      # для отрисовки графиков
import pandas as pd                  # для чтения и работы с данными
import math                          # для работы с мат. функциями
import matplotlib as mpl             # для управления стилем рисунков 
from scipy.optimize import curve_fit # фитирующая процедура

def import_data(name, separator = ','):
    """Возвращает данные из файла
    
    name: имя файла в формате 'data.csv' или
          путь к файлу в формате './data/Our.csv'
    sep: разделитель значений ('\s+' - для пробелов)
    """
    data = pd.read_csv(name, sep = separator)
    return data

def line(x, k, b):
    """Параметрическая прямая"""
    return k*x + b

def approximation(function, x, y):
    """Аппроксимация функцией function"""
    return curve_fit(f = function, xdata = x, ydata = y)

def print_params(params):
    """Печать параметров"""
    for counter, param in enumerate(params):
        print(f"{counter}: {param:.3} \u00B1 {np.sqrt(cov[counter][counter]):.2}")

# Импорт данных
data = import_data('../data/containers.csv')
vector = data['vector']
array = data['array']
deque = data['deque']
list = data['list']
forward_list = data['forward_list']
size = data['size']

# Аппроксимация
function = line
v_params, v_cov = approximation(function, size, vector)
a_params, a_cov = approximation(function, size, array)
d_params, d_cov = approximation(function, size, deque)
l_params, l_cov = approximation(function, size, list)
fl_params, fl_cov = approximation(function, size, forward_list)

mpl.rcParams['font.size'] = 16 # Размер шрифта
plt.figure(figsize=(12,7)) # Размер холста

# Подписи к графику
plt.title(r"Graph of sorting time versus container size")
plt.ylabel(r"Time, sec")
plt.xlabel(r"Size of container")

# Выбор масштаба
ax = plt.gca()
#ax.set_xlim([-0, 1])
#ax.set_ylim([0, 1])

# Построение графика
plt.plot(size, line(size, *v_params), label = 'vector')
plt.plot(size, line(size, *a_params), label = 'array')
plt.plot(size, line(size, *d_params), label = 'deque')
plt.plot(size, line(size, *l_params), label = 'list')
plt.plot(size, line(size, *fl_params), label = 'forward_list')

plt.plot(size, vector, 'o')
plt.plot(size, array, 'o')
plt.plot(size, deque, 'o')
plt.plot(size, list, 'o')
plt.plot(size, forward_list, 'o')


#plt.errorbar(x, y, xerr, yerr, label, color, marker, markersize, linewidth) # график с погрешностями

# Отображение сетки
plt.grid(visible=True, which='major', axis='both', alpha=1)
plt.grid(visible=True, which='minor', axis='both', alpha=0.5)
# Отображение легенды
plt.legend();

## Сохранение результатов
#f = open('voltage.txt', 'w')
#for index in voltage1:
#    f.write(str(index) + ' ')
#f.close()


# Сохранение графика
plt.savefig('example.png')

# Отображение графика
plt.show()