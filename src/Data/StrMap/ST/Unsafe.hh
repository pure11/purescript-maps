///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unsafe.hh
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
#ifndef Data_StrMap_ST_Unsafe_FFI_HH
#define Data_StrMap_ST_Unsafe_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_StrMap_ST_Unsafe {
  using namespace PureScript;

  // foreign import unsafeGet :: forall a h r. STStrMap h a -> Eff (st :: ST h | r) (StrMap a)
  //
  auto unsafeGet(const any&) -> any;

}

#endif // Data_StrMap_ST_Unsafe_FFI_HH
