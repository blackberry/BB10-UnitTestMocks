/*
   Copyright 2013 Research In Motion Limited

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef BB_CASCADES_PLACES_GLOBAL_HPP
#define BB_CASCADES_PLACES_GLOBAL_HPP
#include "gtest/gtest.h"
#include <qglobal.h>
#if defined(BB_STATIC_BB_CASCADES_PLACES_LIB)
#   define BB_STATIC_BB_CASCADES_PLACES_LIB
#else
#   if defined(BB_BUILD_BB_CASCADES_PLACES_LIB)
#       define BB_CASCADES_PLACES_EXPORT    Q_DECL_EXPORT
#   else
#       define BB_CASCADES_PLACES_EXPORT    Q_DECL_IMPORT
#   endif
#endif
#endif 
