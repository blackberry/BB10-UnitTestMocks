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
#ifndef cascades_contextmenuhandler_h
#define cascades_contextmenuhandler_h
#include "gmock/gmock.h"
#include <bb/cascades/core/gesturehandler.h>
namespace bb {
    namespace cascades {
    class ContextMenuHandlerPrivate;
    class ContextMenuShowingEvent;
    class ContextMenuHandler : public UIObject 
    {
public:
      ContextMenuHandler(UIObject* parent = 0);
      virtual ~ContextMenuHandler();
      MOCK_METHOD1(showing, void (bb::cascades::ContextMenuShowingEvent *event));
      MOCK_METHOD0(hiding, void ());
public:
        typedef UIObject BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& onShowing(const QObject* receiver, const char *method) {
                bool res = QObject::connect(&this->instance(), SIGNAL(showing(bb::cascades::ContextMenuShowingEvent*)), receiver, method);
                return this->builder();
            }
            BuilderType& onHiding(const QObject* receiver, const char *method) {
                bool res = QObject::connect(&this->instance(), SIGNAL(hiding()), receiver, method);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, ContextMenuHandler> {
        public:
            Builder() : TBuilder<Builder, ContextMenuHandler>(new ContextMenuHandler()) {}
        };
      static Builder create() {
            return Builder();
        }
    };
  }
}
#endif 
