# Algorytmy Sortowania

Została zaimplementowana struktura, która jest tablicą do przechowywania elementów.

Zostały zaimplementowane algorytmy:

*  Mergesort
*  Quicksort
*  Heapsort
*  Introsort

####  Struktura

Przedstawia sobą tablicę wskaźników na elementy do przechowywania, opisana jest klasą "Table". Jest szablonem, więc pozwala przechowywać róźne typy elementów.

Ponieważ kompilacja programu przeprowadzana jest częściami(plik "makefile"), typy możliwe typy danych muszą być zdefiniowane przed kompilacją programu, umiszczone na końcach plików .h.

####  Mergesort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
O(n log n)   | najgorszy

Algorytm zaimplementowany za pomocą struktury pomocniczej, która przechowuje tablice wskaźników. Ogólnie taki typ sortowania wymaga tablice pomocniczą co najmniej o takim samym rozmiarze. W tej implementacji na początku tablica początkowa jest kopiowana, dla tego pamięci zużywa się 2 razy więcej.

####  Quicksort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
Θ(n^2)   | najgorszy

Najszybszy algorytm sortowania, co prawda szybkość sortowania zależy od danych początkowych, zaimplementowany za pomocą metod Klasy "Table".

Szybkość działania algorytmu przede wszystkim zależy od wyboru pivota. W tym przypadku piwotem jest element znajdujący się na środku tablicy sortowanej.

####  Heapsort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
O(n log n)   | najgorszy

Jedno z najprostrzych sortowań, buduje kopiec typu max w niejawny sposób a następnie wyrzuca największy element z korzenia drzewa na koniec.

####  Introsort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
O(n log n)   | najgorszy

Algorytm używa do sortowania zmodyfikowaną metodę Quicksort i przechodzi na Heapsort po przekroczeniu głębi rekursji liczby log(n).

## Testy
* Wszystkie elementy posortowane:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_0.jpg)

* 25% początkowych elementów posortowanych:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_25.jpg)

* 50% początkowych elementów posortowanych:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_50.jpg)

* 75% początkowych elementów posortowanych:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_75.jpg)

* 95% początkowych elementów posortowanych:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_95.jpg)

* 99% początkowych elementów posortowanych:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_99.jpg)

* 99.7% początkowych elementów posortowanych:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_99.7.jpg)

* Wszystkie posortowane odwrotnie:

  ![Test 0](https://github.com/221349/PAMSI/blob/master/project2/analysis/sorted_-100.jpg)

Z przeprowadzonych testów wynika, że naszybszym algorytmem głównie jest Quicksort, natychmiast najwolniejszym jest Heapsort.

## Pliki

* makefile - instrukcja do kompilatora

* sort.out - skompilowany programu

* test.sh - plik testów

* analysis - skrypt do Matlaba dla generowania wykresów

## Błędy

  Pod czas pisania programu trafiłem na zjawisko, kiedy nie następuje zwolnienie pamięci po uruchomieniu "delete" wskaźnika na zmienną do sortowania.

  Chociaż pod czas pracy algorytmów zwolnienie pamięci dla zmiennych nie jest potrzebne (sortowanie odbywa się na tablicy wskaźników), wyjaśniono, dlaczego pamięć nie zwalnia się całkowicie.

  Ponieważ struktura ma postać tablicy wskaźników na elementy do przechowywania, każde dodanie nowego elementu przydziela pamięć dla jednego wskaźnika, obszar pamięci może się znajdować gdziekolwiek w pamięci systemu. Sfragmentowana pamięć programu może zająć dużo czasu na zwolnienie, w systemie Linux takie obszary dostają status "free". W systemie program wciąż może zajmować wcześniej wykorzystaną pamięć, ale zwolni za potrzebą.

## Materiały

  [Wprowadzenie do algorytmów, Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)

 [Wątek na Stackoverflow (pytanie o zwolnienie pamięci)](https://stackoverflow.com/questions/50026722/why-free-for-array-of-poiters-does-not-deallocate-memory)

 [Wikipedia: https://en.wikipedia.org/wiki/Sorting_algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
