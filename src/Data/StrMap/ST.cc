///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unsafe.cc
// Copyright   :  (c) Andy Arvanitis 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Data.StrMap FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include <map>
#include "ST.hh"

namespace Data_StrMap_ST {

  using StrMap = std::map<std::string, any>;

  // foreign import new :: forall a h r. Eff (st :: ST h | r) (STStrMap h a)
  //
  auto new$() -> any {
    return make_managed<StrMap>();
  }

  // foreign import peekImpl :: forall a b h r. (a -> b) -> b -> STStrMap h a -> String -> Eff (st :: ST h | r) b
  //
  auto peekImpl(const any& nothing, const any& just, const any& m_, const string& k) -> any {
    return [=]() {
      const auto& m = cast<StrMap>(m_);
      const auto r = m.find(k);
      return r != m.cend() ? just(r->second) : nothing;
    };
  }

  // foreign import poke :: forall a h r. STStrMap h a -> String -> a -> Eff (st :: ST h | r) (STStrMap h a)
  //
  auto poke(const any& m, const string& k, const any& v) -> any {
    return [=]() {
      auto& mm = cast<StrMap>(m);
      mm.erase(k);
      mm.emplace(k, v);
      return m;
    };
  }

  // foreign import delete :: forall a h r. STStrMap h a -> String -> Eff (st :: ST h | r) (STStrMap h a)
  //
  auto delete$(const any& m, const string& k) -> any {
    return [=]() {
      cast<StrMap>(m).erase(k);
      return m;
    };
  }
}
