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
// StrMap Unsafe FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include <map>
#include "Unsafe.hh"

namespace Data_StrMap_Unsafe {

  using StrMap = std::map<std::string, any>;

  // foreign import unsafeIndex :: forall a. StrMap a -> String -> a
  //
  auto unsafeIndex(const any& m, const string& k) -> any {
    return cast<StrMap>(m).at(k);
  }

}
