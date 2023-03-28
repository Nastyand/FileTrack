Постановка задачи
Написать программу для слежения за состоянием выбранного файла.

Ограничимся  двумя характеристиками:
1. Существует файл или нет;
2. Каков размер файла.

Программа будет выводить на консоль уведомление о произошедших изменениях в файле.
Существует несколько ситуаций для наблюдаемого файла

1. Файл существует , файл не  пустой - на экран выводится факт существования файла и его  размер.
2. Файл существует, файл был изменен - на экран выводится факт существования файла, сообщение о том что файл был изменен и его размер.  
3. Файл не существует - на экран выводится информация о том что файл не существует.

Предлагаемое решение
Задача решается с помощью трех сущностей:
1.class StateFile-класс,хранящий состояние 1 файла
2.class FileMonitor-класс, следящий за состояниями всех файлов
3.class FilePrinter-класс, выводящий сообщения на консоль
