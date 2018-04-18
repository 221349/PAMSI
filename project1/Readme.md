# Drzewo AVL

Zostało zaimplementowane dzewo binarne AVL

Drzewo opisane jest strukturą AVLTree, węzły - Node

Dzewo posiada metody:

*  dodawanie
*  usuwanie
*  poszukiwanie
*  wyświetlanie
*  wyświetlania metodami Pre/In/Post-inOrder

## Testy

  Wyszukiwanie elementów rzeczywiście jest bardzo szybkie.
  
  Z kolei dodawanie/usuwanie elementów ze względu na konieczność balansowania całego dzrewa zajmuje dość dużo czasu na obliczenia.

  Przeprowadzone testy pokazały sprawność programu na poziomie elementów 2^12 (większ illość węzłów zajmuje za dużo czasu na obliczenia).

  Działają opisane metody.

  Dzewo rzeczywiście jest zbalansowane według zasad drzewa AVL (nie jest to jednak dzrewo idealnie zbalansowane, kiedy wysokość dzrewa jest jaknajmniejsza).

## Błędy

  Zaimplementowane dzrewo nie posiada do końca sprawnego destruktora, pod czas usuwania węzła  jego klucz jest usuwany, jednak sam węzeł zostaje w pamięci, może groźić to wyciekami pamięci.
