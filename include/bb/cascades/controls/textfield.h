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
#ifndef cascades_textfield_h
#define cascades_textfield_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QString>
#include <bb/cascades/controls/abstracttextcontrol.h>
#include <bb/cascades/resources/textfieldinputmode.h>
#include <bb/cascades/TextInputProperties>
#include <bb/cascades/TextAutoFit>
#include <bb/cascades/SubmitKeyFocusBehavior>
namespace bb {
    namespace cascades {
    class TextFieldPrivate;
    class Container;
    class TextField : public AbstractTextControl
    {
public:
        TextField(Container * parent = 0) { }
        MOCK_CONST_METHOD0(hintText, const QString ());
        MOCK_METHOD1(setHintText, void (const QString &hintText));
        MOCK_METHOD0(resetHintText, void ());
        MOCK_METHOD1(setInputMode, void (bb::cascades::TextFieldInputMode::Type inputMode));
        MOCK_CONST_METHOD0(inputMode, bb::cascades::TextFieldInputMode::Type ());
        MOCK_METHOD0(resetInputMode, void ());
        MOCK_CONST_METHOD0(isBackgroundVisible, bool ());
        MOCK_METHOD1(setBackgroundVisible, void (bool backgroundVisible));
        MOCK_METHOD0(resetBackgroundVisible, void ());
        MOCK_CONST_METHOD0(isClearButtonVisible, bool ());
        MOCK_METHOD1(setClearButtonVisible, void (bool clearButtonVisible));
        MOCK_METHOD0(resetClearButtonVisible, void ());       
        MOCK_CONST_METHOD0(isFocusHighlightEnabled, bool ());
        MOCK_METHOD1(setFocusHighlightEnabled, void (bool focusHighlightEnabled));
        MOCK_METHOD0(resetFocusHighlightEnabled, void ());
        MOCK_CONST_METHOD0(input, bb::cascades::TextInputProperties* ());
        MOCK_METHOD1(setAutoFit, void (bb::cascades::TextAutoFit::Type autoFit));
        MOCK_CONST_METHOD0(autoFit, bb::cascades::TextAutoFit::Type ());
        MOCK_METHOD0(resetAutoFit, void ());
        MOCK_METHOD1(textChanging, void (const QString text));
        MOCK_METHOD1(clearButtonVisibleChanged, void (bool clearButtonVisible));
        MOCK_METHOD1(backgroundVisibleChanged, void (bool backgroundVisible));
        MOCK_METHOD1(focusHighlightEnabledChanged, void (bool focusHighlightEnabled));
        MOCK_METHOD1(hintTextChanged, void (const QString hintText));   
        MOCK_METHOD1(inputModeChanged, void (bb::cascades::TextFieldInputMode::Type newInputMode));
        MOCK_METHOD1(autoFitChanged, void (bb::cascades::TextAutoFit::Type newAutoFit));
public:
        typedef TextField ThisClass;
        typedef AbstractTextControl BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:        
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
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
            BuilderType& clearButtonVisible(bool clearButtonVisible)
            {
                this->instance().setClearButtonVisible(clearButtonVisible);
                return this->builder();
            }
            BuilderType& focusHighlightEnabled(bool focusHighlightEnabled)
            {
                this->instance().setFocusHighlightEnabled(focusHighlightEnabled);
                return this->builder();
            }
            BuilderType& inputMode(bb::cascades::TextFieldInputMode::Type inputMode)
            {
                this->instance().setInputMode(inputMode);
                return this->builder();
            }
            BuilderType& submitKey(bb::cascades::SubmitKey::Type submitKey)
            {
                this->instance().input()->setSubmitKey(submitKey);            
                return this->builder();
            }
            BuilderType& submitKeyFocusBehavior(bb::cascades::SubmitKeyFocusBehavior::Type submitKeyFocusBehavior)
			{
				this->instance().input()->setSubmitKeyFocusBehavior(submitKeyFocusBehavior);
				return this->builder();
			}
            BuilderType& onSubmitted(const QObject* receiver, const char *method)
            {
                if (receiver) {
                    receiver->connect(this->instance().input(), SIGNAL(submitted(bb::cascades::AbstractTextControl*)), method);
                }
                return this->builder();
            }   
            BuilderType& inputFlags(bb::cascades::TextInputFlag::Types flags)
            {
              this->instance().input()->setFlags(flags);
              return this->builder();
            }
        };      
        class Builder : public TBuilder<Builder, TextField>
        {
        public:
            Builder(Container *parent = 0) : TBuilder<Builder, TextField>(new TextField(parent))
            {
            }
        };
        static Builder create(Container *parent = 0)
        {
            return Builder(parent);
        }
    };
}
}
#endif 
