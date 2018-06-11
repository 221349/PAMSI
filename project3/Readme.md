# Gra Kółko i Krzyżyk

Gra pozwala grać przeciwko komputerowi

Do obliczenia ruchu wykorzystany jest algorytm MiniMax z alfa-beta cięciem

Program równierz korzysta z klasy <vector>

Do obliczenia ruchu tworzone jest drzewo gry, węzły którego są usuwane odrazu po użyciu, co minimalizuje użycie pamięci RAM, ale minimale zmniejsza czas obliczania.

Wyposażony program jest w tekstowy interfejs graficzny. Potrafi jednak wyświetlać pole do grania i wszystkie niezbędne informacje.

  Gra posiada dość elastyczne ustawienia "s - Setup" :
* dowolne wymiary tablicy (x,y>0, x,y<rozmiar int)
* długość linii dla wygrania
* tryby gry:
  * gracz-gracz
  * gracz-komputer
  * komputer-komputer
* który gracz jest pierwszy
* zmiana symboli grzczy
* ograniczenie głębokości wyszukiwania
* mnożnik dla wygrania (system oceny ruchów)
* włączenie/wyłaczenie optymalizacji alfa-Beta
* włączenie/wyłaczenie wyświetlania dodatkowej informacji

Dodatkowo można użyć gotowych szablonów konfiguracji 'p' - '`code`Presets'

## Testy

Optymalizacja alfa-beta pozwala znacznie przyspieszyć działanie algorytmu

Przeprowadzone testy na polu 4x4, długoś dla wygrania - 4

Pierwszy ruchc - ruch gracza:


<pre>
╔═══╦═══╦═══╦═══╦═══╗
║   ║ 0 ║ 1 ║ 2 ║ 3 ║
╠═══╬═══╬═══╬═══╬═══╣
║ 0 ║ X │   │   │   ║
╠═══╬───┼───┼───┼───╢
║ 1 ║   │ O │   │   ║
╠═══╬───┼───┼───┼───╢
║ 2 ║   │   │   │   ║
╠═══╬───┼───┼───┼───╢
║ 3 ║   │   │   │   ║
╚═══╩═══╧═══╧═══╧═══╝
  Last move: (1,1): O
    time: 203276 ms
    tree nodes: 43600003
    move value: 2
</pre>


Głębia  | Z alfa-beta | Bez alfa-beta
------------: | ------------ | -------------
1 | <pre>time: 0 ms, tree nodes: 16</pre>| <pre>time: 0 ms, tree nodes: 16</pre>
2 | <pre>time: 2 ms, tree nodes: 226</pre>| <pre>time: 2 ms, tree nodes: 226</pre>
3 | <pre>time: 21 ms, tree nodes: 2704</pre>| <pre>time: 12 ms, tree nodes: 2956</pre>
4 | <pre>time: 100 ms, tree nodes: 23981</pre>| <pre>time: 129 ms, tree nodes: 35716</pre>
5 | <pre>time: 616 ms, tree nodes: 156618</pre>| <pre>time: 1415 ms, tree nodes: 396076</pre>
6 | <pre>time: 3416 ms, tree nodes: 824852</pre>| <pre>time: 14444 ms, tree nodes: 3999676</pre>
7 | <pre>time: 12491 ms, tree nodes: 2859816</pre>| <pre>time: 141351 ms, tree nodes: 36218236</pre>
8 | <pre>time: 68219 ms, tree nodes: 14376028</pre>|  -
9 | <pre>time: 203276 ms, tree nodes: 43600003</pre>|  -

Brak pomiarów 8 i 9 dla 'Bez alfa-beta' ze względu na duży czas wykonania

Zaczynając od głębokości 3 alfa-beta cięcie zaczyna optymalizację

Cechą tej gry jest to, że czas wzrasta eksponencjalnie wraz z wzrostem głebokości przeszukiwania

## Błedy

Na chwilę obecną błędów nie odnaleziono

## Materiały

  [MIT OpenCourseWare. 6. Search: Games, Minimax, and Alpha-Beta](https://www.youtube.com/watch?v=STjW3eH0Cik)\

  [Francisco Iacobelli. alpha beta prunning](https://www.youtube.com/watch?v=d2maa6k2gYE)

  [Habr.com, TheHorse: Минимакс на примере игры в зайца и волков](https://habr.com/post/146088/)

  [cplusplus.com](http://www.cplusplus.com)

  [stackoverflow.com](https://stackoverflow.com)

  [cppreference.com](https://cppreference.com)

  [Wiki: Alpha–beta pruning](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning)

  [Wprowadzenie do algorytmów, Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)
