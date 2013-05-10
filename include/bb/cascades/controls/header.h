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
#ifndef cascades_header_h
#define cascades_header_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
namespace bb {
    namespace cascades {
    class HeaderPrivate;
    class Header : public Control
    {
public:
        Header();
        virtual ~Header();
        MOCK_CONST_METHOD0(title, const QString ());
        MOCK_METHOD1(setTitle, void (const QString & title));
        MOCK_METHOD0(resetTitle, void ());
        MOCK_CONST_METHOD0(subtitle, const QString ());
        MOCK_METHOD1(setSubtitle, void (const QString & subtitle));
        MOCK_METHOD0(resetSubtitle, void ());
        MOCK_METHOD1(titleChanged, void (QString title));
        MOCK_METHOD1(subtitleChanged, void (QString subtitle));
public:
        typedef Header ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) :
            BaseClass::TBuilder<BuilderType, BuiltType>(node)
            { }
        public:
            BuilderType& title(const QString &title)
            {
                this->instance().setTitle(title);
                return this->builder();
            }
            BuilderType& subtitle(const QString &subtitle)
            {
                this->instance().setSubtitle(subtitle);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Header>
        {
         public:
             Builder() : TBuilder<Builder, Header>(new Header())
             { }
        };
      static Builder create()
        {
            return Builder();
        }
    };
}
}
#endif 
