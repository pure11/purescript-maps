///////////////////////////////////////////////////////////////////////////////
//
// Module      :  StrMap.hh
// Copyright   :  (c) Andy Arvanitis 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// StrMap FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_StrMap_FFI_HH
#define Data_StrMap_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_StrMap {
  using namespace PureScript;

  // foreign import _copyEff :: forall a b h r. a -> Eff (st :: ST.ST h | r) b
  //
  auto _copyEff(const any&) -> any;

  // foreign import runST :: forall a r. (forall h. Eff (st :: ST.ST h | r) (SM.STStrMap h a)) -> Eff r (StrMap a)
  //
  auto runST(const any&) -> any;

  // foreign import _fmapStrMap :: forall a b. Fn2 (StrMap a) (a -> b) (StrMap b)
  //
  auto _fmapStrMap(const any&, const any&) -> any;

  // foreign import _foldM :: forall a m z. (m -> (z -> m) -> m) -> (z -> String -> a -> m) -> m -> StrMap a -> m
  //
  auto _foldM(const any&, const any&, const any&, const any&) -> any;

  // foreign import _foldSCStrMap :: forall a z. Fn4 (StrMap a) z (z -> String -> a -> Maybe z) (forall b. b -> Maybe b -> b) z
  //
  auto _foldSCStrMap(const any&, const any&, const any&, const any&) -> any;

  // foreign import all :: forall a. (String -> a -> Boolean) -> StrMap a -> Boolean
  //
  auto all(const any&, const any&) -> bool;

  // foreign import empty :: forall a. StrMap a
  //
  auto empty(any::as_thunk) -> const any&;

  // foreign import size :: forall a. StrMap a -> Number
  //
  auto size(const any&) -> double;

  // foreign import _lookup :: forall a z. Fn4 z (a -> z) String (StrMap a) z
  //
  auto _lookup(const any&, const any&, const string&, const any&) -> any;

  // foreign import _unsafeDeleteStrMap :: forall a. Fn2 (StrMap a) String (StrMap a)
  //
  auto _unsafeDeleteStrMap(const any&, const string&) -> any;

  // foreign import _lookupST :: forall a h r z. Fn4 z (a -> z) String (SM.STStrMap h a) (Eff (st :: ST.ST h | r) z)
  //
  auto _lookupST(const any&, const any&, const string&, const any&) -> any;

  // foreign import _collect :: forall a b . (String -> a -> b) -> StrMap a -> Array b
  //
  auto _collect(const any&, const any&) -> any::array;

  // foreign import keys :: forall a. StrMap a -> Array String
  //
  auto keys(const any&) -> any::array;

  // foreign import _mapWithKey :: forall a b. Fn2 (StrMap a) (String -> a -> b) (StrMap b)
  //
  auto _mapWithKey(const any&, const any&) -> any;

}

#endif // Data_StrMap_FFI_HH
