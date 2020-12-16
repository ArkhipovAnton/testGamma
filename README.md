Задание:

Есть последовательность идентификаторов, строящаяся по особым правилам:

1. Первый идентификатор последовательности имеет вид "A1". Второй - "A2", третий - "A3" и так далее.

    За "A9" следующий - "B1". Следующий после "Z9" имеет вид "A1-A1", потом "A1-A2" и так далее. После "A1-Z9"

     следующим идет "A2-A1".

2. Максимальная длина идентификатора - десять групп по два символа.

3. В идентификаторах никогда не должны присутствовать буквы "D", "F", "G", "J", "M", "Q", "V", и цифра "0".

  Нужно: на C написать библиотечный модуль, предназначенный для использования другими программистами.

  Функция модуля должна получать в качестве входного параметра строку с идентификатором из описанной последовательности,

  и генерировать на выходе строку, содержащую следующий идентификатор последовательности.

  Например, функция получает "A1-Z9" и возвращает "A2-A1".

  Особенности реализации задания:
  1. Строка символов заканчивается '\0'
  2. После элемента "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9\n" следует элемент "А1", незаполненные символы выделенной для ответа строки заполняются '\0'
  3. Модуль проверяется на несколько типовых правильных ответов и для тестирования написан скрипт на Python3, который можно легко автоматизировать
  4. Обрабатываемые исключения:
    - неправильная исходная последовательность, функция возвращает -1 (тесты на это не написаны, проверено вручную);
    - неправильный размер входной строки, функция возвращает -2 (тесты на это не написаны, проверено вручную);
  5. В случае штатного завершения работы функция возвращает количество символов, записанных в строку (тесты на это не написаны, проверено вручную)
  
