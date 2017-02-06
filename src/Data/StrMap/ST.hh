///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Data_StrMap_ST.hh
// Copyright   :  (c) Andy Arvanitis 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Data.StrMap.ST FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_StrMap_ST_FFI_HH
#define Data_StrMap_ST_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_StrMap_ST {
  using namespace PureScript;

  // foreign import new :: forall a h r. Eff (st :: ST h | r) (STStrMap h a)
  //
  auto new$() -> any;

  // foreign import peekImpl :: forall a b h r. (a -> b) -> b -> STStrMap h a -> String -> Eff (st :: ST h | r) b
  //
  auto peekImpl(const any&, const any&, const any&, const string&) -> any;

  // foreign import poke :: forall a h r. STStrMap h a -> String -> a -> Eff (st :: ST h | r) (STStrMap h a)
  //
  //
  auto poke(const any&, const string&, const any&) -> any;

  // foreign import delete :: forall a h r. STStrMap h a -> String -> Eff (st :: ST h | r) (STStrMap h a)
  //
  auto delete$(const any&, const string&) -> any;

}

#endif // Data_StrMap_ST_FFI_HH
