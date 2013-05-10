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
#ifndef cascades_menu_h
#define cascades_menu_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
namespace bb {
    namespace cascades {
        class ActionItem;
        class HelpActionItem;
        class SettingsActionItem;
        class MenuPrivate;
        class Menu : public UIObject {
public:
            Menu(QObject* parent = 0);
            virtual ~Menu();
            MOCK_METHOD1(addAction, void (bb::cascades::ActionItem* actionItem));
            MOCK_METHOD1(removeAction, bool (bb::cascades::ActionItem* actionItem));
            MOCK_CONST_METHOD0(actionCount, int ());
            MOCK_CONST_METHOD1(actionAt, bb::cascades::ActionItem* (int index));
            MOCK_CONST_METHOD0(helpAction, bb::cascades::HelpActionItem* ());
            MOCK_METHOD1(setHelpAction, void (bb::cascades::HelpActionItem* helpAction));
            MOCK_METHOD0(resetHelpAction, void ());
            MOCK_CONST_METHOD0(settingsAction, bb::cascades::SettingsActionItem* ());
            MOCK_METHOD1(setSettingsAction, void (bb::cascades::SettingsActionItem* settingsAction));
            MOCK_METHOD0(resetSettingsAction, void ());
            MOCK_METHOD1(enabledChanged, void (bool enabled));  
            MOCK_METHOD1(actionAdded, void (bb::cascades::ActionItem *action));
            MOCK_METHOD1(actionRemoved, void (bb::cascades::ActionItem *action));
            MOCK_METHOD1(helpActionChanged, void (bb::cascades::HelpActionItem* helpAction));
            MOCK_METHOD1(settingsActionChanged, void (bb::cascades::SettingsActionItem* settingsAction));
            typedef Menu ThisClass;
            typedef UIObject BaseClass;
    public:
            template <typename BuilderType, typename BuiltType>
            class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
            protected:
                TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
                {
                }
            public:           
            BuilderType& addAction(ActionItem *action)
            {
                this->instance().addAction(action);
                return this->builder();
            }
            BuilderType& help(HelpActionItem* helpAction)
            {
                this->instance().setHelpAction(helpAction);
                return this->builder();
            }
            BuilderType& settings(SettingsActionItem* settingsAction)
            {
                this->instance().setSettingsAction(settingsAction);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Menu>
        {
        public:
            Builder() : TBuilder<Builder, Menu>(new Menu()) {
            }
        };
      static Builder create() {
            return Builder();
        }     
        };
    }
};
#endif 
