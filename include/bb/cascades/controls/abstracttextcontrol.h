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
#ifndef cascades_abstracttextcontrol_h
#define cascades_abstracttextcontrol_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstracttextcontrolmock.h>
#include <bb/cascades/controls/container.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/resources/color.h>
#include <bb/cascades/resources/textstyle.h>
#include <bb/cascades/resources/textstyledefinition.h>
namespace bb {
    namespace cascades {
    class AbstractTextControlPrivate;
    class AbstractTextControl: public Control
    {
public:
    	AbstractTextControl(Container *parent = 0): Control(parent) {}
        virtual ~AbstractTextControl(){}
        const QString text() { return mock<AbstractTextControlMock>()->text(); }
        void setText(const QString &text) { mock<AbstractTextControlMock>()->setText(text); }
        void resetText() { mock<AbstractTextControlMock>()->resetText(); }
        bb::cascades::TextStyleDefinition* textStyle() { return mock<AbstractTextControlMock>()->textStyle(); }
        bb::cascades::TextContentProperties* content(){ return mock<AbstractTextControlMock>()->content(); }
		bb::cascades::ActiveTextHandler* activeTextHandler() { return mock<AbstractTextControlMock>()->activeTextHandler(); }
		void setActiveTextHandler(bb::cascades::ActiveTextHandler* activeTextHandler) { mock<AbstractTextControlMock>()->setActiveTextHandler(activeTextHandler); }
		void resetActiveTextHandler() { mock<AbstractTextControlMock>()->resetActiveTextHandler(); }
        void textChanged(QString text) { mock<AbstractTextControlMock>()->textChanged( text); }
        void activeTextHandlerChanged(bb::cascades::ActiveTextHandler* activeTextHandler) { mock<AbstractTextControlMock>()->activeTextHandlerChanged(activeTextHandler); }
public:
        typedef AbstractTextControl ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
		{
		protected:
			TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
			{
			}
		public:
			BuilderType& text(const QString &text)
			{
				this->instance().setText(text);
				return this->builder();
			}
			BuilderType& activeTextHandler(bb::cascades::ActiveTextHandler* activeTextHandler)
			{
				this->instance().setActiveTextHandler(activeTextHandler);
				return this->builder();
			}
			BuilderType& textStyle(const TextStyle &textStyle)
			{
				this->instance().textStyle()->setBase(textStyle);
				return this->builder();
			}
			BuilderType& contentFlags(bb::cascades::TextContentFlag::Types flags)
			{
				this->instance().content()->setFlags(flags);
				return this->builder();
			}
		};
    };
}
}
#endif	
