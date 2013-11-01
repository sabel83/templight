
template <int N>
struct int_
{
  typedef int_ type;
  static const int value;
};

template <int N>
const int int_<N>::value = N;




template <bool B>
struct bool_
{
  typedef bool_ type;
  static const bool value;
};

template <bool B>
const bool bool_<B>::value = B;




template <class A, class B>
struct plus
{
  typedef int_<A::type::value + B::type::value> type;
};

template <class A, class B>
struct minus
{
  typedef int_<A::type::value - B::type::value> type;
};

template <class A, class B>
struct less
{
  typedef bool_<(A::type::value < B::type::value)> type;
};



template <bool C, class T, class F>
struct if_c
{
  typedef T type;
};

template <class T, class F>
struct if_c<false, T, F>
{
  typedef F type;
};

template <class C, class T, class F>
struct eval_if : if_c<C::type::value, T, F>::type {};


template <class N>
struct lazy_fib :
  eval_if<
    less<N, int_<2> >,
    int_<1>,
    plus<
      lazy_fib<minus<N, int_<1> > >,
      lazy_fib<minus<N, int_<2> > >
    >
  >
{};

template <class N>
struct strict_fib;

template <class N>
struct strict_fib_impl :
  plus<
    typename strict_fib<typename minus<N, int_<1> >::type>::type,
    typename strict_fib<typename minus<N, int_<2> >::type>::type
  >
{};

template <class N>
struct strict_fib :
  eval_if<
    typename less<N, int_<2> >::type,
    int_<1>,
    strict_fib_impl<N>
  >
{};



