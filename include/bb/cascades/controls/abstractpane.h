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
#ifndef cascades_abstractpane_h
#define cascades_abstractpane_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
namespace bb {
    namespace cascades {
    class AbstractPanePrivate;
    class PaneProperties;
    class AbstractPane : public UIObject {
    	Q_OBJECT
public:
        virtual ~AbstractPane() {};
        MOCK_CONST_METHOD0(paneProperties, bb::cascades::PaneProperties* ());
        MOCK_METHOD1(setPaneProperties, void (bb::cascades::PaneProperties *paneProperties));
        MOCK_METHOD0(resetPaneProperties, void ());
        MOCK_CONST_METHOD0(isPeekedAt, bool ());
        MOCK_METHOD1(panePropertiesChanged, void (bb::cascades::PaneProperties *paneProperties));
        MOCK_METHOD1(peekedAtChanged, void (bool peekedAt));
        MOCK_METHOD0(peekStarted, void ());
        MOCK_METHOD0(peekEnded, void ());
        typedef AbstractPane ThisClass;
        typedef UIObject BaseClass;
   public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
        public:
            BuilderType& paneProperties(PaneProperties* paneProperties) {
                this->instance().setPaneProperties(paneProperties);
                return this->builder();
            }
        };
    };
}
}
#endif
