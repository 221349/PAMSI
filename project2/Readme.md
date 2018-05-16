# Algorytmy Sortowania

Została zaimplementowana struktura, która jest tablicą do przechowywania elementów.

Zostały zaimplementowane algorytmy:

*  Mergesort
*  Quicksort
*  Heapsort
*  Introsort

####  Mergesort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
O(n log n)   | najgorszy

####  Quicksort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
O(n^2)   | najgorszy

####  Heapsort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
O(n log n)   | najgorszy

####  Introsort

Złożoność: 	 |   Przypadek
------------ | -------------
O(n log n)   | średni
O(n log n)   | najgorszy


## Testy
* Wszystkie elementy posortowane:
  ![Test 0](/analysis/sorted_0.jpg)

* 25% początkowych elementów posortowanych:
  ![Test 0](/analysis/sorted_25.jpg)

* 50% początkowych elementów posortowanych:
  ![Test 0](/analysis/sorted_50.jpg)

* 75% początkowych elementów posortowanych:
  ![Test 0](/analysis/sorted_75.jpg)

* 95% początkowych elementów posortowanych:
  ![Test 0](/analysis/sorted_95.jpg)

* 99% początkowych elementów posortowanych:
  ![Test 0](/analysis/sorted_99.jpg)

* 99.7% początkowych elementów posortowanych:
  ![Test 0](/analysis/sorted_99.7.jpg)

* Wszystkie posortowane odwrotnie:
  ![Test 0](/analysis/sorted_-100.jpg)


## Błędy

  Pod czas pisania programu trafiłem na zjawisko, kiedy nie następuje zwolnienie pamięci po uruchomieniu "delete" wskaźnika na zmienną do sortowania.

  Chociaż pod czas pracy algorytmów zwolnienie pamięci dla zmiennych nie jest potrzebne (sortowanie odbywa się na tablicy wskaźników), wyjaśniono, dlaczego pamięć nie zwalnia się całkowicie.

  Ponieważ struktura ma postać tablicy wskaźników na elementy do przechowywania, każde dodanie nowego elementu przydziela pamięć dla jednego wskaźnika, obszar pamięci może się znajdować gdziekolwiek w pamięci systemu. Sfragmentowana pamięć programu może zająć dużo czasu na zwolnienie, w systemie Linux takie obszary dostają status "free". W systemie program wciąż może zajmować wcześniej wykorzystaną pamięć, ale zwolni za potrzebą.

## Materiały

  [Wprowadzenie do algorytmów, Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)

 [Wątek na Stackoverflow (pytanie o zwolnienie pamięci)](https://stackoverflow.com/questions/50026722/why-free-for-array-of-poiters-does-not-deallocate-memory)

 [Wikipedia: https://en.wikipedia.org/wiki/Sorting_algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
