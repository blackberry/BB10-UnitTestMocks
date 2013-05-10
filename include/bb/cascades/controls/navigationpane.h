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
#ifndef cascades_navigationpane_h
#define cascades_navigationpane_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractpane.h>
#include <bb/cascades/controls/page.h>
namespace bb {
    namespace cascades {
        class NavigationPanePrivate;
        class NavigationPane : public AbstractPane {
public:
            NavigationPane(QObject* parent = 0);
            virtual ~NavigationPane();
            MOCK_CONST_METHOD0(top, bb::cascades::Page* ());
            MOCK_METHOD1(push, void (bb::cascades::Page* child));
            MOCK_METHOD0(pop, bb::cascades::Page* ());
            MOCK_METHOD1(navigateTo, QVariantList (bb::cascades::Page* targetPage));
            MOCK_CONST_METHOD0(backButtonsVisible, bool ());
            MOCK_METHOD1(setBackButtonsVisible, void (bool visible));
            MOCK_METHOD0(resetBackButtonsVisible, void ());
            MOCK_CONST_METHOD0(count, int ());
            MOCK_CONST_METHOD1(at, bb::cascades::Page* (int index));
            MOCK_CONST_METHOD1(indexOf, int (bb::cascades::Page* page));
            MOCK_METHOD2(insert, void (int index, bb::cascades::Page *page));
            MOCK_METHOD1(remove, bool (bb::cascades::Page *page));
            MOCK_CONST_METHOD0(isPeekEnabled, bool ());
            MOCK_METHOD1(setPeekEnabled, void (bool enabled));
            MOCK_METHOD0(resetPeekEnabled, void ());
            MOCK_METHOD1(topChanged, void (bb::cascades::Page* page));
            MOCK_METHOD1(pushTransitionEnded, void (bb::cascades::Page* page));
            MOCK_METHOD1(popTransitionEnded, void (bb::cascades::Page* page));
            MOCK_METHOD1(navigateToTransitionEnded, void (QVariantList pages));
            MOCK_METHOD1(backButtonsVisibleChanged, void (bool visible));
            MOCK_METHOD1(peekEnabledChanged, void (bool enabled));
            typedef NavigationPane ThisClass; 
            typedef AbstractPane BaseClass;
        public:
            template <typename BuilderType, typename BuiltType>
            class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> 
            {
            protected:
                TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
            public:
                BuilderType& add(bb::cascades::Page* page)
                {
                    this->instance().push(page);
                    return this->builder();
                }
                BuilderType& backButtons(bool visible)
                {
                    this->instance().setBackButtonsVisible(visible);
                    return this->builder();
                }
                BuilderType& peek(bool enabled)
                {
                    this->instance().setPeekEnabled(enabled);
                    return this->builder();
                }
            };
            class Builder : public TBuilder<Builder, NavigationPane> {
            public:
                Builder() : TBuilder<Builder, NavigationPane>(new NavigationPane()) {}
            };
          static Builder create() {
                return Builder();
            }
        };
    }
}
#endif 
