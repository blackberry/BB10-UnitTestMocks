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
#ifndef cascades_textarea_h
#define cascades_textarea_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QString>
#include <bb/cascades/controls/abstracttextcontrol.h>
#include <bb/cascades/resources/textareainputmode.h>
#include <bb/cascades/TextInputProperties>
namespace bb {
    namespace cascades {
    class TextAreaPrivate;
    class Container;
    class TextArea : public AbstractTextControl
    {
public:
        TextArea(Container* parent = 0);
        MOCK_CONST_METHOD0(isEditable, bool ());
        MOCK_METHOD1(setEditable, void (bool editable));
        MOCK_METHOD0(resetEditable, void ());
        MOCK_CONST_METHOD0(hintText, const QString ());
        MOCK_METHOD1(setHintText, void (const QString &hintText));
        MOCK_METHOD0(resetHintText, void ());
        MOCK_METHOD1(setInputMode, void (bb::cascades::TextAreaInputMode::Type inputMode));
        MOCK_CONST_METHOD0(inputMode, bb::cascades::TextAreaInputMode::Type ());
        MOCK_METHOD0(resetInputMode, void ());
        MOCK_CONST_METHOD0(isBackgroundVisible, bool ());
        MOCK_METHOD1(setBackgroundVisible, void (bool backgroundVisible));
        MOCK_METHOD0(resetBackgroundVisible, void ());
        MOCK_CONST_METHOD0(isFocusHighlightEnabled, bool ());
        MOCK_METHOD1(setFocusHighlightEnabled, void (bool focusHighlightEnabled));
        MOCK_METHOD0(resetFocusHighlightEnabled, void ());
        MOCK_CONST_METHOD0(input, bb::cascades::TextInputProperties* ());
        MOCK_METHOD1(textChanging, void (const QString text));
        MOCK_METHOD1(backgroundVisibleChanged, void (bool backgroundVisible));
        MOCK_METHOD1(focusHighlightEnabledChanged, void (bool focusHighlightEnabled));
        MOCK_METHOD1(hintTextChanged, void (const QString hintText));
        MOCK_METHOD1(editableChanged, void (bool editable));
        MOCK_METHOD1(inputModeChanged, void (bb::cascades::TextAreaInputMode::Type newInputMode));  
public:
        typedef TextArea ThisClass;
        typedef AbstractTextControl BaseClass;        
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {}
        public:            
            BuilderType& hintText(const QString &hintText)
            {
                this->instance().setHintText(hintText);
                return this->builder();
            }
            BuilderType& backgroundVisible(bool backgroundVisible)
            {
                this->instance().setBackgroundVisible(backgroundVisible);
                return this->builder();
            }
            BuilderType& focusHighlightEnabled(bool focusHighlightEnabled)
            {
                this->instance().setFocusHighlightEnabled(focusHighlightEnabled);
                return this->builder();
            }
            BuilderType& editable(bool editable)
            {
                this->instance().setEditable(editable);
                return this->builder();
            }
            BuilderType& inputMode(bb::cascades::TextAreaInputMode::Type inputMode)
            {
                this->instance().setInputMode(inputMode);
                return this->builder();
            }
            BuilderType& submitKey(bb::cascades::SubmitKey::Type submitKey)
            {
                this->instance().input()->setSubmitKey(submitKey);
                return this->builder();
            }
            BuilderType& onSubmitted(const QObject* receiver, const char *method)
            {
                if (receiver) {
                    bool res = receiver->connect(this->instance().input(), SIGNAL(submitted(bb::cascades::AbstractTextControl*)), method);
                }
                return this->builder();
            }
            BuilderType& inputFlags(bb::cascades::TextInputFlag::Types flags)
            {
              this->instance().input()->setFlags(flags);
              return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, TextArea>
        {
        public:
            Builder() : TBuilder<Builder, TextArea>(new TextArea())
            {}
        };
      static Builder create() {
            return Builder();
        }
    };
}
}
#endif 
