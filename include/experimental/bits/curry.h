//
// curry.h
// ~~~~~~~
// Create a function object from a list of tokens.
//
// Copyright (c) 2014 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EXECUTORS_EXPERIMENTAL_BITS_CURRY_H
#define EXECUTORS_EXPERIMENTAL_BITS_CURRY_H

#include <experimental/bits/invoker.h>

namespace std {
namespace experimental {

template <class... _CompletionTokens>
auto curry(_CompletionTokens&&... __tokens)
{
  static_assert(sizeof...(_CompletionTokens) > 0,
    "curry() must be called with one or more completion tokens");

  return __invoker_tail<void(), _CompletionTokens...>(__tokens...);
}

template <class _Signature, class... _CompletionTokens>
auto curry(_CompletionTokens&&... __tokens)
{
  static_assert(sizeof...(_CompletionTokens) > 0,
    "curry() must be called with one or more completion tokens");

  return __invoker_tail<_Signature, _CompletionTokens...>(__tokens...);
}

} // namespace experimental
} // namespace std

#endif
