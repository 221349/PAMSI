#ifndef HEAP_H
#define HEAP_H
using namespace std;

inline int parent(int i) {return i >> 1;}
inline int left(int i) {return i << 1;}
inline int right(int i) {return (i << 1) + 1;}
inline int index(int begin, int i) {return begin + i - 1;}

#endif
