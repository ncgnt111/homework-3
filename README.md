# homework-3
Написать программу, которая в качестве аргумента командной строки принимает имя текстового файла, содержащего элементы трёх видов:
\+ <слово>
\- <слово>
\? <слово>
Элементы отделяются друг от друга одним или несколькими разделителями – пробелами, табуляциями, символами новой строки.
Слово с предшествующим плюсом добавляется в двоичное дерево поиска, если его там ещё нет (ключом при построении дерева должно являться само слово, в качестве функции сравнения слов использовать лексикографическое сравнение). Если числу предшествует минус, то это слово удаляется из дерева (если оно было в нём). Если перед словом стоит вопрос, то оно печатается в выходной поток в отдельной строке вместе со словом Yes или No в зависимости от того, присутствует ли это слово в построенном на тот момент дереве поиска.
