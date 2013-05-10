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
#ifndef cascades_tabbedpane_h
#define cascades_tabbedpane_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractpane.h>
#include <bb/cascades/controls/sidebarstate.h>
#include <bb/cascades/resources/tab.h>
namespace bb {
    namespace cascades {
        class ActionItem;
        class TabbedPanePrivate;
        class TabbedPane : public AbstractPane
        {
public:
            TabbedPane(QObject* parent = 0);
            virtual ~TabbedPane();
            MOCK_CONST_METHOD0(sidebarState, bb::cascades::SidebarState::Type ());
            MOCK_METHOD1(setSidebarState, void (bb::cascades::SidebarState::Type sidebarState));
            MOCK_METHOD0(resetSidebarState, void ());
            MOCK_CONST_METHOD0(activeTab, bb::cascades::Tab* ());
            MOCK_METHOD1(setActiveTab, void (bb::cascades::Tab* activeTab));
            MOCK_CONST_METHOD0(activePane, bb::cascades::AbstractPane* ());
            MOCK_METHOD1(setActivePane, void (bb::cascades::AbstractPane* activePane));
            MOCK_METHOD1(add, void (bb::cascades::Tab* tab));
            MOCK_METHOD2(insert, void (int index, bb::cascades::Tab* tab));
            MOCK_CONST_METHOD1(at, bb::cascades::Tab* (int index));
            MOCK_CONST_METHOD1(indexOf, int (bb::cascades::Tab *tab));
            MOCK_CONST_METHOD0(count, int ());
            MOCK_METHOD1(remove, bool (bb::cascades::Tab* tab));
            MOCK_METHOD0(removeAll, void ());
            MOCK_CONST_METHOD0(showTabsOnActionBar, bool ());
            MOCK_METHOD1(setShowTabsOnActionBar, void (bool showTabsOnActionBar));
            MOCK_METHOD0(resetShowTabsOnActionBar, void ());
            MOCK_CONST_METHOD0(isPeekEnabled, bool ());
            MOCK_METHOD1(setPeekEnabled, void (bool enabled));
            MOCK_METHOD0(resetPeekEnabled, void ());
            MOCK_METHOD1(activeTabChanged, void (bb::cascades::Tab* activeTab));
            MOCK_METHOD1(activePaneChanged, void (bb::cascades::AbstractPane* activePane));
            MOCK_METHOD1(activePaneTransitionEnded, void (bb::cascades::AbstractPane* activePane));
            MOCK_METHOD1(tabAdded, void (bb::cascades::Tab* tab));
            MOCK_METHOD1(tabRemoved, void (bb::cascades::Tab* tab));
            MOCK_METHOD1(showTabsOnActionBarChanged, void (bool showTabsOnActionBar));
            MOCK_METHOD1(sidebarStateChanged, void (bb::cascades::SidebarState::Type newSidebarState));
            MOCK_METHOD1(peekEnabledChanged, void (bool enabled));
public:
            typedef TabbedPane ThisClass; 
            typedef AbstractPane BaseClass;
            template <typename BuilderType, typename BuiltType>
            class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> 
            {
            protected:
                TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
            public:
                BuilderType& add(bb::cascades::Tab* tab)
                {
                    this->instance().add(tab);
                    return this->builder();
                }
                BuilderType& activePane(bb::cascades::AbstractPane* activePane)
                {
                    this->instance().setActivePane(activePane);
                    return this->builder();
                }
                BuilderType& showTabsOnActionBar(bool showTabsOnActionBar)
                {
                    this->instance().setShowTabsOnActionBar(showTabsOnActionBar);
                    return this->builder();
                }
                BuilderType& sidebarState(bb::cascades::SidebarState::Type sidebarState)
                {
                    this->instance().setSidebarState(sidebarState);
                    return this->builder();
                }
                BuilderType& peek(bool enabled)
                {
                    this->instance().setPeekEnabled(enabled);
                    return this->builder();
                }
            };
            class Builder : public TBuilder<Builder, TabbedPane>
            {
            public:
                Builder() : TBuilder<Builder, TabbedPane>(new TabbedPane()) {}
            };
          static Builder create()
            {
                return Builder();
            }
        };
    }
}
#endif 
