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
#ifndef cascades_page_h
#define cascades_page_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractpane.h>
#include <bb/cascades/controls/chromevisibility.h>
#include <bb/cascades/controls/pageresizebehavior.h>
#include <bb/cascades/controls/actionbarplacement.h>
namespace bb {
    namespace cascades {
    class PagePrivate;
    class Control;
    class AbstractActionItem;
    class TitleBar;
    class Page : public AbstractPane {
        Q_OBJECT
    public:
        MOCK_CONST_METHOD0(titleBar, bb::cascades::TitleBar* ());
        MOCK_METHOD1(setTitleBar, void (bb::cascades::TitleBar *titleBar));
        MOCK_METHOD0(resetTitleBar, void ());
        Page(QObject* parent = 0) {Q_UNUSED(parent)};
        virtual ~Page() {};
        void addAction(bb::cascades::AbstractActionItem* actionItem) {addAction(actionItem, bb::cascades::ActionBarPlacement::Default);}
        MOCK_METHOD2(addAction, void (bb::cascades::AbstractActionItem* actionItem, bb::cascades::ActionBarPlacement::Type placement));
        MOCK_METHOD1(removeAction, bool (bb::cascades::AbstractActionItem* actionItem));
        MOCK_METHOD0(removeAllActions, void ());
        MOCK_CONST_METHOD0(actionCount, int ());
        MOCK_CONST_METHOD1(actionAt, bb::cascades::AbstractActionItem* (int index));
        MOCK_METHOD1(setContent, void (bb::cascades::Control* content));
        MOCK_CONST_METHOD0(content, bb::cascades::Control* ());
        MOCK_CONST_METHOD0(resizeBehavior, bb::cascades::PageResizeBehavior::Type ());
        MOCK_METHOD1(setResizeBehavior, void (bb::cascades::PageResizeBehavior::Type resizeBehavior));
        MOCK_METHOD0(resetResizeBehavior, void ());
        MOCK_METHOD1(setActionBarVisibility, void (const bb::cascades::ChromeVisibility::Type visibility));
        MOCK_CONST_METHOD0(actionBarVisibility, bb::cascades::ChromeVisibility::Type ());
        MOCK_METHOD0(resetActionBarVisibility, void ());
        MOCK_METHOD1(actionBarVisibilityChanged, void (bb::cascades::ChromeVisibility::Type newVisibility));
        MOCK_METHOD1(resizeBehaviorChanged, void (bb::cascades::PageResizeBehavior::Type newResizeBehavior));
        MOCK_METHOD1(titleBarChanged, void (bb::cascades::TitleBar *titleBar));
        MOCK_METHOD1(contentChanged, void (bb::cascades::Control* content));
        MOCK_METHOD1(actionAdded, void (bb::cascades::AbstractActionItem *action));
        MOCK_METHOD1(actionRemoved, void (bb::cascades::AbstractActionItem *action));
        typedef Page ThisClass;
        typedef AbstractPane BaseClass;
    public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& addAction(AbstractActionItem *action,
              bb::cascades::ActionBarPlacement::Type placement = bb::cascades::ActionBarPlacement::Default)
            {
                this->instance().addAction(action, placement);
                return this->builder();
            }
            BuilderType& content(Control *control)
            {
                this->instance().setContent(control);
                return this->builder();
            }
            BuilderType& actionBarVisibility(bb::cascades::ChromeVisibility::Type newVisibility)
            {
                this->instance().setActionBarVisibility(newVisibility);
                return this->builder();
            }
            BuilderType& resizeBehavior(bb::cascades::PageResizeBehavior::Type resizeBehavior) {
                this->instance().setResizeBehavior(resizeBehavior);
                return this->builder();
            }
            BuilderType& titleBar(TitleBar* titleBar) {
                this->instance().setTitleBar(titleBar);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Page>
        {
        public:
            Builder() : TBuilder<Builder, Page>(new Page()) {
            }
        };
      static Builder create() {
            return Builder();
        }
    };
}
}
#endif
