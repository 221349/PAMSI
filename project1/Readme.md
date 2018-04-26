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

  Z kolei czas na dodawanie/usuwanie elementów ze względu na konieczność balansowania całego dzrewa wzrasta wraz z rośnięciem drzewa.

  Przeprowadzone testy pokazały sprawność programu na poziomie elementów 2^13 (większ illość węzłów zajmuje za dużo czasu na obliczenia).

  Działają opisane metody.

  Dzewo rzeczywiście jest zbalansowane według zasad drzewa AVL (nie jest to jednak dzrewo idealnie zbalansowane, kiedy wysokość dzrewa jest jaknajmniejsza).

## Błędy

  Wcześniej wykryte błędzy zostały poprawione w ostatniej wersji:
  > Zaimplementowane dzrewo nie posiada do końca sprawnego destruktora, pod czas usuwania węzła  jego klucz jest usuwany, jednak sam węzeł zostaje w pamięci, może groźić to wyciekami pamięci.
  > Praca z drzewem po usunięciu elementu root z drzewa o wysokości 1 powoduje SegFault.
