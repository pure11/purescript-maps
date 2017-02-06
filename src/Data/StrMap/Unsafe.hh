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
// StrMap Unsafe FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_StrMap_Unsafe_FFI_HH
#define Data_StrMap_Unsafe_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_StrMap_Unsafe {
  using namespace PureScript;

  // foreign import unsafeIndex :: forall a. StrMap a -> String -> a
  //
  auto unsafeIndex(const any&, const string&) -> any;

}

#endif // Data_StrMap_Unsafe_FFI_HH
