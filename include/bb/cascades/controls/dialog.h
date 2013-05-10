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
#ifndef cascades_dialog_h
#define cascades_dialog_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractdialog.h>
namespace bb {
    namespace cascades {
    class Control;
    class DialogPrivate;
    class Dialog : public AbstractDialog {
public:
        Dialog(UIObject *parent = 0);
        virtual ~Dialog();
        MOCK_METHOD1(setContent, void (bb::cascades::Control* content));
        MOCK_CONST_METHOD0(content, bb::cascades::Control* ());
        MOCK_METHOD0(resetContent, void ());
        MOCK_METHOD1(contentChanged, void (bb::cascades::Control* content));
        typedef Dialog ThisClass;
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
            BuilderType& content(Control *content)
            {
                this->instance().setContent(content);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Dialog>
        {
        public:
            Builder() : TBuilder<Builder, Dialog>(new Dialog())
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
