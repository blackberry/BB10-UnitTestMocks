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
#ifndef cascades_actionset_h
#define cascades_actionset_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/resources/abstractactionitem.h>
namespace bb {
    namespace cascades {
    class ActionSetPrivate;
    class ActionSet : public UIObject
    {
public:
        ActionSet();
        virtual ~ActionSet();
        MOCK_METHOD1(add, void (bb::cascades::AbstractActionItem* action));
        MOCK_METHOD2(insert, void (int index, bb::cascades::AbstractActionItem* action));
        MOCK_CONST_METHOD0(count, int ());
        MOCK_CONST_METHOD1(at, bb::cascades::AbstractActionItem* (int index));
        MOCK_CONST_METHOD1(indexOf, int (bb::cascades::AbstractActionItem* action));
        MOCK_METHOD1(remove, bool (bb::cascades::AbstractActionItem* action));
        MOCK_METHOD0(removeAll, void ());
        MOCK_CONST_METHOD0(title, QString ());
        MOCK_METHOD1(setTitle, void (const QString& title));
        MOCK_METHOD0(resetTitle, void ());
        MOCK_CONST_METHOD0(subtitle, QString ());
        MOCK_METHOD1(setSubtitle, void (const QString& subtitle));
        MOCK_METHOD0(resetSubtitle, void ());
        MOCK_METHOD1(actionAdded, void (bb::cascades::AbstractActionItem *action));
        MOCK_METHOD1(actionRemoved, void (bb::cascades::AbstractActionItem *action));
        MOCK_METHOD1(titleChanged, void (const QString& title));
        MOCK_METHOD1(subtitleChanged, void (const QString& subtitle));
public:
        typedef ActionSet ThisClass; 
        typedef UIObject BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> 
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
        public:
            BuilderType& add(AbstractActionItem *action)
            {
                this->instance().add(action);
                return this->builder();
            }
            BuilderType& title(const QString & title)
            {
                this->instance().setTitle(title);
                return this->builder();
            }
            BuilderType& subtitle(const QString & subtitle)
            {
                this->instance().setSubtitle(subtitle);
                return this->builder();
            }          
        };
        class Builder : public TBuilder<Builder, ActionSet>
        {
        public:
            Builder() : TBuilder<Builder, ActionSet>(new ActionSet()) {}
        };
      static Builder create()
        {
            return Builder();
        }
    }; 
  }
}
#endif 
