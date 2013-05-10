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
#ifndef cascades_multiselecthandler_h
#define cascades_multiselecthandler_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/resources/actionitem.h>
namespace bb {
    namespace cascades {
    class MultiSelectActionItem;
    class MultiSelectHandlerPrivate;
    class VisualNode;
    class MultiSelectHandler : public UIObject
    {
public:
        MultiSelectHandler(VisualNode* parent = 0);
        virtual ~MultiSelectHandler();
        MOCK_CONST_METHOD0(isActive, bool ());
        MOCK_METHOD1(setActive, void (bool active));
        MOCK_METHOD0(resetActive, void ());
        MOCK_CONST_METHOD0(actionCount, int ());
        MOCK_CONST_METHOD1(actionAt, bb::cascades::AbstractActionItem* (int index));
        MOCK_METHOD1(addAction, void (bb::cascades::AbstractActionItem* action));
        MOCK_METHOD1(removeAction, bool (bb::cascades::AbstractActionItem* action));
        MOCK_METHOD0(removeAllActions, void ());
        MOCK_CONST_METHOD0(status, QString ());
        MOCK_METHOD1(setStatus, void (const QString& status));
        MOCK_METHOD0(resetStatus, void ());
        MOCK_METHOD1(activeChanged, void (bool active));
        MOCK_METHOD1(actionAdded, void (bb::cascades::AbstractActionItem *action));
        MOCK_METHOD1(actionRemoved, void (bb::cascades::AbstractActionItem *action));
        MOCK_METHOD1(statusChanged, void (const QString& status));
        MOCK_METHOD0(canceled, void ());
public:
        typedef MultiSelectHandler ThisClass; 
        typedef UIObject BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> 
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
        public:
            BuilderType& addAction(AbstractActionItem *action)
            {
                this->instance().addAction(action);
                return this->builder();
            }
            BuilderType& status(const QString& status)
            {
                this->instance().setStatus(status);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, MultiSelectHandler>
        {
        public:
            Builder(VisualNode* target) : TBuilder<Builder, MultiSelectHandler>(new MultiSelectHandler(target)) {}
        };
      static Builder create(VisualNode* target)
        {
            return Builder(target);
        }
    }; 
  }
}
#endif 
