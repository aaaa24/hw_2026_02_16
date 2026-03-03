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
BiList< T > * create(const T & d)
{
  BiList< T > * r = new BiList< T >{d, nullptr, nullptr};
  r->prev = r;
  r->next = r;
  return r;
}

template< class T >
BiList< T > * insert_before(BiList< T > * node, const T & d)
{
  BiList< T > * prev = node->prev;
  BiList< T > * r = new BiList< T >{d, prev, node};
  prev->next = r;
  node->prev = r;
  return r;
}

template< class T >
BiList< T > * insert_after(BiList< T > * node, const T & d)
{
  BiList< T > * next = node->next;
  BiList< T > * r = new BiList< T >{d, node, next};
  next->prev = r;
  node->next = r;
  return r;
}

template< class T >
void cut(BiList< T > * node) noexcept
{
  BiList< T > * prev = node->prev;
  BiList< T > * next = node->next;
  prev->next = next;
  next->prev = prev;
  delete node;
}

template< class T >
BiList< T > * cut_fwd(BiList< T > * node)
{
  BiList< T > * r = node->next;
  if (r == node) {
    delete node;
    return nullptr;
  }
  cut(node);
  return r;
}

template< class T >
BiList< T > * cut_bwd(BiList< T > * node)
{
  BiList< T > * r = node->prev;
  if (r == node) {
    delete node;
    return nullptr;
  }
  cut(node);
  return r;
}

template< class T >
BiList< T > * clear(BiList< T > * h, BiList< T > * e) noexcept
{
  do {
    h = cut_fwd(h);
  } while (h != e);
  return h;
}

template< class T >
BiList< T > * clear_all(BiList< T > * h) noexcept
{
  return clear(h, h);
}

template< class T, class F >
F traverse(F f, BiList< T > * h, BiList< T > * e)
{
  do {
    f(v->val);
    h = h->next;
  } while (h != e);
  return f;
}

template< class T, class F >
F traverse_reverse(F f, BiList< T > * h, BiList< T > * e)
{
  do {
    f(v->val);
    h = h->prev;
  } while (h != e);
  return f;
}

template< class T, class F >
F traverse_all(F f, BiList< T > * h)
{
  return traverse(f, h, h);
}

template< class T, class F >
F traverse_reverse_all(F f, BiList< T > * h)
{
  return traverse_reverse(f, h, h);
}

int main()
{}
