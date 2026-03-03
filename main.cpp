#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList< T > * prev;
  BiList< T > * next;
};

template< class T >
BiList< T > * fake(BiList< T > * h)
{
  BiList< T > * r = static_cast< List< T > * >(::operator new (sizeof(List< T > *)));
  r->next = h;
  return h;
}

template< class T >
BiList< T > * rmfake(BiList< T > * h) noexcept
{
  BiList< T > * r = h->next;
  ::operator delete(h);
  return r;
}

template< class T >
BiList< T > * insert_before(BiList< T > * node, const T & d)
{
  if (!node) {
    return new BiList< T >{d, nullptr, nullptr};
  }
  BiList< T > * prev = node->prev;
  BiList< T > * r = new BiList< T >{d, prev, node};
  prev->next = r;
  node->prev = r;
  return r;
}

template< class T >
BiList< T > * insert_after(BiList< T > * node, const T & d)
{
  if (!node) {
    return new BiList< T >{d, nullptr, nullptr};
  }
  BiList< T > * next = node->next;
  BiList< T > * r = new BiList< T >{d, node, next};
  next->prev = r;
  node->next = r;
  return r;
}

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
