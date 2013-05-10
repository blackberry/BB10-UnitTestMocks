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
#ifndef cascades_absolutelayout_h
#define cascades_absolutelayout_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/layouts/layout.h>
namespace bb {
    namespace cascades {
    class AbsoluteLayoutPrivate;
    class AbsoluteLayout : public Layout {
public:
        AbsoluteLayout() { }
        virtual ~AbsoluteLayout() { }
public:
        typedef AbsoluteLayout ThisClass;  
        typedef Layout BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        };
        class Builder : public TBuilder<Builder, AbsoluteLayout> 
        {
        public:
            Builder() : TBuilder<Builder, AbsoluteLayout>(new AbsoluteLayout()) {
            }
        };
      static Builder create() {
            return Builder();
        }
    }; 
} 
}
#endif	
