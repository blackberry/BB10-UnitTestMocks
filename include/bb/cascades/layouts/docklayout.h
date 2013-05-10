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
#ifndef cascades_docklayout_h
#define cascades_docklayout_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/layouts/layout.h>
namespace bb {
    namespace cascades {
    class DockLayoutPrivate;
    class DockLayout : public Layout {
public:
        DockLayout() { }
        virtual ~DockLayout() { }
public:
        typedef DockLayout ThisClass;  
        typedef Layout BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
        };
        class Builder : public TBuilder<Builder, DockLayout> 
        {
        public:
            Builder() : TBuilder<Builder, DockLayout>(new DockLayout()) {
            }
        };
        static Builder create() {
            return Builder();
        }
    }; 
} 
}
#endif	
