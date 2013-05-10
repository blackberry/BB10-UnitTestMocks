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
#ifndef cascades_abstractdialog_h
#define cascades_abstractdialog_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
namespace bb {
    namespace cascades {
    class AbstractDialogPrivate;
    class AbstractDialog : public UIObject {
public:
        virtual ~AbstractDialog();
        MOCK_METHOD0(open, void ());
        MOCK_METHOD0(close, void ());
        MOCK_CONST_METHOD0(isOpened, bool ());
        MOCK_METHOD1(openedChanged, void (bool opened));
        MOCK_METHOD0(opened, void ());
        MOCK_METHOD0(closed, void ());
        typedef AbstractDialog ThisClass;
        typedef UIObject BaseClass;
    public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& open()
            {
                this->instance().open();
                return this->builder();
            }
            BuilderType& onOpened(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(opened()), receiver, method);
                return this->builder();
            }
            BuilderType& onClosed(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(closed()), receiver, method);
                return this->builder();
            }
        };
    };
}
}
#endif
