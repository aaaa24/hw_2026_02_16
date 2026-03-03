#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList< T > * next;
  BiList< T > * prev;
};

template< class T >
BiList< T > * fake(BiList< T > * h);

template< class T >
BiList< T > * rmfake(BiList< T > * h) noexcept;

template< class T >
BiList< T > * insert_before(BiList< T > * node, const T & d);

template< class T >
BiList< T > * insert_after(BiList< T > * node, const T & d);

template< class T >
BiList< T > * cut_fwd(BiList< T > * node);

template< class T >
BiList< T > * cut_bwd(BiList< T > * node);

template< class T >
BiList< T > * clear(BiList< T > * h, BiList< T > * e) noexcept;

template< class T >
BiList< T > * clear(BiList< T > * h) noexcept;

template< class T, class F >
F traverse(F f, BiList< T > * h, BiList< T > * e) noexcept;

template< class T, class F >
F traverse_reverse(F f, BiList< T > * h, BiList< T > * e) noexcept;

template< class T, class F >
F traverse(F f, BiList< T > * h) noexcept;

template< class T, class F >
F traverse_reverse(F f, BiList< T > * h) noexcept;

int main()
{}
