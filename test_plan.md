# План тестирования

### Введение

Данный план описывает тестирование приложения "Restorer" для востановления удалённых файлов.
Требования, предъявляемые тестировщику:
*умение пользоваться персональным компьютером под операционной системой Windows.
Атрибуты качества приложения по ISO 25010:
* функциональность
  * функциональная полнота: приложение должно выполнять все возложенные на нее функции
  * функциональная корректность: приложение должно выполнять все возложенные на нее функции корректно
* производительность
  * временная характеристика: приложение должно открываться не медленнее чем за 30 секунд
* практичность
  * защита от ошибок пользователей: приложение должно выводить сообщения об ошибках если пользователь произвел некорректное действие
* надежность


### Риски

При преждевременном закрытии данные не востановятся.
### Аспекты тестирования
*Выбор места, где проводить поиск
  -Всего раздела
  -Папки в определённом разделе
*Проверка файловой системы на соответсвие программе(является ли NTFS)
*Выбор места, куда восстанавливать
  -Выбор места
  -Проверка на совпадение с местом поиска(не должны совпадать)
*Выбор форматов файлов, которые будут искаться
*возможность выбора файлов из списка
*Сохранение найденных файлов в место назначения
### Подход к тестированию
Для тестирования необходим компьютер необходим персональный компьютер под операционной системой Windows версии 8.1
и выше, а также носители информации с файловыми системами NTFS и любой другой, поддерживаемой Windows.
### Представление результатов

Предоставление результатов требуется описать в следующем виде:

1. Идентификатор
2. Назначение / название
3. Сценарий
4. Ожидаемый результат
5. Фактический результат (заполняется на этапе тестирования)
6. Оценка (заполняется на этапе тестирования)
Тестовые сценарии:

#### Возможность добавления доходов в определенные разделы

1. 001

2. Проверка возможности выбор места, где проводить поиск

3. Произведите следующие шаги:

   1. Запустите приложение.

   2. Нажмите на кнопку "Выбрать путь".

   3. В появившемся окне выберите папку.

   4. Нажмите "Продолжить".

4. В приложении появится следующее окно, в котором будет указан выбраный путь

#### Возможность проверки файловой системы на соответсвие программе(является ли NTFS)

1. 002

2. Проверка возможности проверки файловой системы на соответсвие программе

3. Произведите следующие шаги:

   1. Запустите приложение.

   2. Нажмите на кнопку "Выбрать диск".

   3. Выберите диск с файловой системой, не совпадающей с файловой системой NTFS.

   4. Нажмите "Продолжить".

4. В приложении появится окно предупреждения о несовпадении файловой системы

#### Выбор места, куда восстанавливать

1. 003

2. Проверка возможности выбора места, куда восстанавливать

3. Произведите следующие шаги:

   1. Запустите приложение.
   
   2. Выберите место поиска файлов.

   3. Нажмите на кнопку "Выбрать место".

   3. Выберите папку в которую хотите сохранить данные.

   4. Нажмите "Сохранитьь".

4. В приложении появится следующее окно с выбором параметром и указаным местом сохранения


#### Выбор места, куда восстанавливать(с совпадающим разделом диска с местом поиска)

1. 004

2. Проверка возможности выбора места, куда восстанавливать

3. Произведите следующие шаги:

   1. Запустите приложение.
   
   2. Выберите место поиска файлов.

   3. Нажмите на кнопку "Выбрать место".

   3. Выберите папку в которую хотите сохранить данные и раздел которой совпадает с разделом места поиска.

   4. Нажмите "Сохранить".

4. В приложении появится окно с предупреждением о возможной потере данных

#### Выбор форматов файлов, которые будут искаться

1. 005

2. Проверка возможности выбора форматов файлов

3. Произведите следующие шаги:

   1. Запустите приложение.
   
   2. Выберите место путь поиска.

   3. Выберите место сохранения.

   3. Введите в поле формат.

   4. Нажмите "➕".
    

4. В поле слева должен появиться введённый формат


#### Возможность выбора файлов из списка

1. 006

2. Проверка возможности выбора файлов из списка

3. Произведите следующие шаги:

   1. Запустите приложение.
   
   2. Выберите место путь поиска.

   3. Выберите место сохранения.

   3. Введите укажите форматы.

   4. Нажмите "Продолжить".
   
   5. Нажмите "Начать".
   
   6. Укажите в списке чекбоксы напротив файлов, которые хотите восстановить

4. Должны появиться галочки напротив выбраных файлов



#### Возмость сохранения файлов

1. 007

2. Проверка возможности сохранения файлов

3. Произведите следующие шаги:

   1. Запустите приложение.
   
   2. Выберите место путь поиска.

   3. Выберите место сохранения.

   3. Введите укажите форматы.

   4. Выберите файлы.
   
   5. Нажмите "Восстановить".
   

4. Должны сохраниться файлы в указаном ранее месте


### Вывод


Данные тесты показывают выполнение функциональных требований. Соответствие функциональных требований и тестов:

| Функциональные требования                | ID теста |
| ---------------------------------------- | :------: |
| Функция выбор места, где проводить поиск |    001 - 002    |
| Функция Проверка файловой системы на соответсвие программе(является ли NTFS) |    002-005    |
| Функция выбор места, куда восстанавливать |   003 - 004   |
| Функция выбора форматов файлов  |    005    |
| Функция выбора файлов из списка |    006    |
| Функция сохранение найденных файлов|    007    |






  