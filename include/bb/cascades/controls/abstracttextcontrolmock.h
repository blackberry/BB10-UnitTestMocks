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
#ifndef cascades_abstracttextcontrolmock_h
#define cascades_abstracttextcontrolmock_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/controlmock.h>
#include <bb/cascades/resources/color.h>
#include <bb/cascades/resources/textstyle.h>
#include <bb/cascades/resources/textstyledefinition.h>
#include <bb/cascades/resources/textalign.h>
#include <bb/cascades/controls/textcontentproperties.h>
namespace bb {
    namespace cascades {
    class AbstractTextControlPrivate;
    class Container;
    class ActiveTextHandler;
    class AbstractTextControlMock: public ControlMock
    {
public:
        virtual ~AbstractTextControlMock() { }
        MOCK_CONST_METHOD0(text, const QString ());
        MOCK_METHOD1(setText, void (const QString &text));
        MOCK_METHOD0(resetText, void ());       
        MOCK_METHOD0(textStyle, bb::cascades::TextStyleDefinition* ());
        MOCK_METHOD0(content, bb::cascades::TextContentProperties* ());
        MOCK_CONST_METHOD0(activeTextHandler, bb::cascades::ActiveTextHandler* ());
        MOCK_METHOD1(setActiveTextHandler, void (bb::cascades::ActiveTextHandler* activeTextHandler));
        MOCK_METHOD0(resetActiveTextHandler, void ());
        MOCK_METHOD1(textChanged, void (QString text));
        MOCK_METHOD1(activeTextHandlerChanged, void (bb::cascades::ActiveTextHandler* activeTextHandler));
public:
        typedef AbstractTextControlMock ThisClass;
        typedef ControlMock BaseClass;
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
