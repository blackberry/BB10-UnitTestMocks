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
#ifndef cascades_titlebar_h
#define cascades_titlebar_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/resources/image.h>
#include <bb/cascades/resources/titlebarkind.h>
#include <bb/cascades/controls/chromevisibility.h>
#include <bb/cascades/controls/option.h>
namespace bb {
    namespace cascades {
    class TitleBarPrivate;
    class ActionItem;
    class Option;
    class TitleBar : public UIObject {
public:
      const int SelectedIndexNone;
      TitleBar(TitleBarKind::Type kind = TitleBarKind::Default);
      virtual ~TitleBar();
      MOCK_CONST_METHOD0(kind, bb::cascades::TitleBarKind::Type ());
      MOCK_CONST_METHOD0(visibility, bb::cascades::ChromeVisibility::Type ());
      MOCK_METHOD1(setVisibility, void (bb::cascades::ChromeVisibility::Type visibility));
      MOCK_METHOD0(resetVisibility, void ());
      MOCK_METHOD1(setTitle, void (const QString& title));
      MOCK_METHOD0(resetTitle, void ());
      MOCK_CONST_METHOD0(title, QString ());
      MOCK_CONST_METHOD0(acceptAction, bb::cascades::ActionItem* ());
      MOCK_METHOD1(setAcceptAction, void (bb::cascades::ActionItem* acceptAction));
      MOCK_METHOD0(resetAcceptAction, void ());
      MOCK_CONST_METHOD0(dismissAction, bb::cascades::ActionItem* ());
      MOCK_METHOD1(setDismissAction, void (bb::cascades::ActionItem* dismissAction));
      MOCK_METHOD0(resetDismissAction, void ());
      MOCK_CONST_METHOD0(selectedIndex, int ());
      MOCK_METHOD1(setSelectedIndex, void (int index));
      MOCK_METHOD0(resetSelectedIndex, void ());
      MOCK_CONST_METHOD0(selectedOption, bb::cascades::Option* ());
      MOCK_METHOD1(setSelectedOption, void (bb::cascades::Option* option));
      MOCK_METHOD0(resetSelectedOption, void ());
      MOCK_CONST_METHOD0(isSelectedOptionSet, bool ());
      MOCK_CONST_METHOD0(selectedValue, QVariant ());
      MOCK_METHOD1(addOption, void (bb::cascades::Option* option));
      MOCK_METHOD2(insertOption, void (int index, bb::cascades::Option* option));
      MOCK_METHOD1(removeOption, bool (bb::cascades::Option* option));
      MOCK_METHOD0(removeAllOptions, void ());
      MOCK_CONST_METHOD1(optionAt, bb::cascades::Option* (int index));
      MOCK_CONST_METHOD1(indexOfOption, int (bb::cascades::Option* option));
      MOCK_CONST_METHOD0(optionCount, int ());
        MOCK_METHOD1(visibilityChanged, void (bb::cascades::ChromeVisibility::Type newVisibility));
        MOCK_METHOD1(titleChanged, void (const QString &title));
        MOCK_METHOD1(acceptActionChanged, void (bb::cascades::ActionItem* acceptAction));
        MOCK_METHOD1(dismissActionChanged, void (bb::cascades::ActionItem* dismissAction));
        MOCK_METHOD1(selectedIndexChanged, void (int selectedIndex));
        MOCK_METHOD1(selectedOptionChanged, void (bb::cascades::Option* selectedOption));
        MOCK_METHOD1(selectedOptionSetChanged, void (bool selectedOptionSet));
        MOCK_METHOD1(selectedValueChanged, void (const QVariant& selectedValue));
        MOCK_METHOD1(optionAdded, void (bb::cascades::Option *option));
        MOCK_METHOD1(optionRemoved, void (bb::cascades::Option *option));
        typedef TitleBar ThisClass;
        typedef UIObject BaseClass;
    public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& visibility(ChromeVisibility::Type visibility) {
                this->instance().setVisibility(visibility);
                return this->builder();
            }
            BuilderType& title(const QString &title) {
                this->instance().setTitle(title);
                return this->builder();
            }
            BuilderType& acceptAction(ActionItem* acceptAction)
            {
                this->instance().setAcceptAction(acceptAction);
                return this->builder();
            }
            BuilderType& dismissAction(ActionItem* dismissAction)
            {
                this->instance().setDismissAction(dismissAction);
                return this->builder();
            }
            BuilderType& addOption(Option* option)
            {
                this->instance().addOption(option);
                return this->builder();
            }
            BuilderType& addOption(const QString &optionText, const QVariant &value = QVariant(), bool selected = false)
            {
                this->instance().addOption(Option::create().text(optionText).value(value).selected(selected));
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, TitleBar>
        {
        public:
            Builder(TitleBarKind::Type kind) : TBuilder<Builder, TitleBar>(new TitleBar(kind)) {}
        };
      static Builder create(TitleBarKind::Type kind = TitleBarKind::Default) {
            return Builder(kind);
        }
    };
}
}
#endif    
