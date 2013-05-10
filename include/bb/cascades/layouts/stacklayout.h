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
#ifndef cascades_stacklayout_h
#define cascades_stacklayout_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/layouts/layout.h>
#include <bb/cascades/layouts/layoutorientation.h>
namespace bb {
    namespace cascades {
    class StackLayoutPrivate;
    class StackLayout : public Layout {
public:
        StackLayout() { }
        virtual ~StackLayout() { }
        MOCK_CONST_METHOD0(orientation, bb::cascades::LayoutOrientation::Type ());
        MOCK_METHOD1(setOrientation, void (bb::cascades::LayoutOrientation::Type orientation));
        MOCK_METHOD0(resetOrientation, void ());
        MOCK_METHOD1(orientationChanged, void (bb::cascades::LayoutOrientation::Type newOrientation));
public:
        typedef StackLayout ThisClass;  
        typedef Layout BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& orientation(bb::cascades::LayoutOrientation::Type orientation) {
                this->instance().setOrientation(orientation);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, StackLayout> 
        {
        public:
            Builder() : TBuilder<Builder, StackLayout>(new StackLayout()) {
            }
        };
        static Builder create() {
            return Builder();
        }
    }; 
} 
}
#endif	
