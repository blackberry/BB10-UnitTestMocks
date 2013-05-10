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
#ifndef cascades_navigationpaneproperties_h
#define cascades_navigationpaneproperties_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/paneproperties.h>
namespace bb {
    namespace cascades {
    class NavigationPanePropertiesPrivate;
    class ActionItem;
    class NavigationPaneProperties : public PaneProperties
    {
public:
        NavigationPaneProperties();
        virtual ~NavigationPaneProperties();
        MOCK_METHOD1(setBackButton, void (bb::cascades::ActionItem* backButton));
        MOCK_METHOD0(resetBackButton, void ());
        MOCK_CONST_METHOD0(backButton, bb::cascades::ActionItem* ());
        MOCK_METHOD1(backButtonChanged, void (bb::cascades::ActionItem* backButton));
public:
        typedef NavigationPaneProperties ThisClass;
        typedef PaneProperties BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& backButton(bb::cascades::ActionItem* backButton) {
                this->instance().setBackButton(backButton);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, NavigationPaneProperties>
        {
        public:
            Builder() : TBuilder<Builder, NavigationPaneProperties>(new NavigationPaneProperties()) {}
        };
      static Builder create() {
            return Builder();
        }
    };
    }
}
#endif 
