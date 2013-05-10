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
#ifndef cascades_sheet_h
#define cascades_sheet_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractdialog.h>
namespace bb {
    namespace cascades {
    class AbstractPane;
    class SheetPrivate;
    class Sheet : public AbstractDialog {
public:
        Sheet(UIObject *parent = 0);
        virtual ~Sheet();
        MOCK_METHOD1(setContent, void (bb::cascades::AbstractPane* content));
        MOCK_CONST_METHOD0(content, bb::cascades::AbstractPane* ());
        MOCK_METHOD0(resetContent, void ());
        MOCK_METHOD1(setPeekEnabled, void (bool enabled));
        MOCK_METHOD0(resetPeekEnabled, void ());
        MOCK_CONST_METHOD0(isPeekEnabled, bool ());
        MOCK_METHOD1(contentChanged, void (bb::cascades::AbstractPane* content));
        MOCK_METHOD1(peekEnabledChanged, void (bool enabled));
        typedef Sheet ThisClass;
        typedef AbstractDialog BaseClass;
    public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& content(AbstractPane *content)
            {
                this->instance().setContent(content);
                return this->builder();
            }
            BuilderType& peek(bool enabled) {
                this->instance().setPeekEnabled(enabled);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Sheet>
        {
        public:
            Builder() : TBuilder<Builder, Sheet>(new Sheet())
            {
            }
        };
      static Builder create()
        {
            return Builder();
        }
    };
}
}
#endif
