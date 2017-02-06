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
#include "StrMap.hh"

namespace Data_StrMap {

  using StrMap = std::map<std::string, any>;

  // foreign import _copyEff :: forall a b h r. a -> Eff (st :: ST.ST h | r) b
  //
  auto _copyEff(const any& m) -> any {
    return [=]() {
      return make_managed<StrMap>(cast<StrMap>(m));
    };
  }

  // foreign import runST :: forall a r. (forall h. Eff (st :: ST.ST h | r) (SM.STStrMap h a)) -> Eff r (StrMap a)
  //
  auto runST(const any& f) -> any {
    return f;
  }

  // foreign import _fmapStrMap :: forall a b. Fn2 (StrMap a) (a -> b) (StrMap b)
  //
  auto _fmapStrMap(const any& m_, const any& f) -> any {
    const auto& m = cast<StrMap>(m_);
    auto r = make_managed<StrMap>();
    for (auto it = m.cbegin(), end = m.cend(); it != end; it++) {
      r->emplace(it->first, f(it->second));
    }
    return r;
  }

  // foreign import _foldM :: forall a m z. (m -> (z -> m) -> m) -> (z -> String -> a -> m) -> m -> StrMap a -> m
  //
  auto _foldM(const any& bind, const any& f, const any& mz, const any& m_) -> any {
    any acc = mz;
    const auto g = [f, m_](const any& k) {
      return [=](const any& z) {
        const auto& m = cast<StrMap>(m_);
        return f(z)(k)(m.at(k));
      };
    };
    const auto& m = cast<StrMap>(m_);
    for (auto it = m.cbegin(), end = m.cend(); it != end; it++) {
      const auto& k = it->first;
      acc = bind(acc)(g(k));
    }
    return acc;
  }

  // foreign import _foldSCStrMap :: forall a z. Fn4 (StrMap a) z (z -> String -> a -> Maybe z) (forall b. b -> Maybe b -> b) z
  //
  auto _foldSCStrMap(const any& m_, const any& z, const any& f, const any& fromMaybe) -> any {
    const auto& m = cast<StrMap>(m_);
    any zr = z;
    for (auto it = m.cbegin(), end = m.cend(); it != end; it++) {
      const auto maybeR = f(z)(it->first)(it->second);
      const auto r = fromMaybe(nullptr)(maybeR);
      if (cast<void*>(r) == nullptr) {
        return zr;
      } else {
        zr = r;
      }
    }
    return zr;
  }

  // foreign import all :: forall a. (String -> a -> Boolean) -> StrMap a -> Boolean
  //
  auto all(const any& f, const any& m_) -> bool {
    const auto& m = cast<StrMap>(m_);
    for (auto it = m.cbegin(), end = m.cend(); it != end; it++) {
      if (not f(it->first)(it->second)) {
        return false;
      }
    }
    return true;
  }

  // foreign import empty :: forall a. StrMap a
  //
  const any empty = make_managed<StrMap>();

  // foreign import size :: forall a. StrMap a -> Number
  //
  auto size(const any& m) -> double {
    return cast<StrMap>(m).size();
  }

  // foreign import _lookup :: forall a z. Fn4 z (a -> z) String (StrMap a) z
  //
  auto _lookup(const any& no, const any& yes, const string& k, const any& m_) -> any {
    const auto& m = cast<StrMap>(m_);
    const auto r = m.find(k);
    return r != m.cend() ? yes(r->second) : no;
  }

  // foreign import _unsafeDeleteStrMap :: forall a. Fn2 (StrMap a) String (StrMap a)
  //
  auto _unsafeDeleteStrMap(const any& m, const string& k) -> any {
    auto r = make_managed<StrMap>(cast<StrMap>(m));
    r->erase(k);
    return r;
  }

  // foreign import _lookupST :: forall a h r z. Fn4 z (a -> z) String (SM.STStrMap h a) (Eff (st :: ST.ST h | r) z)
  //
  auto _lookupST(const any& no, const any& yes, const string& k, const any& m) -> any {
    return [=]() {
      return _lookup(no, yes, k, m);
    };
  }

  // foreign import _collect :: forall a b . (String -> a -> b) -> StrMap a -> Array b
  //
  auto _collect(const any& f, const any& m_) -> any::array {
    const auto& m = cast<StrMap>(m_);
    any::array r;
    for (auto it = m.cbegin(), end = m.cend(); it != end; it++) {
      r.emplace_back(f(it->first)(it->second));
    }
    return r;
  }

  // foreign import keys :: forall a. StrMap a -> Array String
  //
  auto keys(const any& m_) -> any::array {
    const auto& m = cast<StrMap>(m_);
    any::array r;
    for (auto it = m.cbegin(), end = m.cend(); it != end; it++) {
      r.emplace_back(it->first);
    }
    return r;
  }

  // foreign import _mapWithKey :: forall a b. Fn2 (StrMap a) (String -> a -> b) (StrMap b)
  //
  auto _mapWithKey(const any& m_, const any& f) -> any {
    const auto& m = cast<StrMap>(m_);
    auto r = make_managed<StrMap>();
    for (auto it = m.cbegin(), end = m.cend(); it != end; it++) {
      r->emplace(it->first, f(it->first)(it->second));
    }
    return r;
  }

}
