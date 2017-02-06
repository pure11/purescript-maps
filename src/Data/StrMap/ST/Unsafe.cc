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
// Data.StrMap.ST Unsafe FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Unsafe.hh"

namespace Data_StrMap_ST_Unsafe {

  // foreign import unsafeGet :: forall a h r. STStrMap h a -> Eff (st :: ST h | r) (StrMap a)
  //
  auto unsafeGet(const any& m) -> any {
    return [=]() {
      return m;
    };
  }

}
