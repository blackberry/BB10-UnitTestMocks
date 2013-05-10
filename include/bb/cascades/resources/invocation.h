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
#ifndef cascades_invocation_h
#define cascades_invocation_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/BaseObject>
#include <QtCore/QString>
#include <QtDeclarative/QtDeclarative>
namespace bb {
  namespace cascades {
    class InvocationPrivate;
    class InvokeQuery;
    class Invocation : public BaseObject
    {
public:
      virtual ~Invocation();
      MOCK_METHOD1(trigger, void (const QString& invokeActionId));
      MOCK_METHOD0(query, InvokeQuery* ());
      MOCK_METHOD0(armed, void ());
      typedef Invocation ThisClass;
      typedef BaseObject BaseClass;
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
      {
      protected:
        TBuilder(BuiltType* node, const bb::cascades::InvokeQuery* const pQuery)
          : BaseClass::TBuilder<BuilderType, BuiltType>(node)
        {
          this->instance().setQuery(pQuery);
        }
      };
      class Builder : public TBuilder<Builder, ThisClass>
      {
      public:
        Builder(const bb::cascades::InvokeQuery* const pQuery)
          : TBuilder<Builder, ThisClass>(new ThisClass(), pQuery) {
        }
      };
    public:
    static Builder create(const bb::cascades::InvokeQuery* const pQuery) {
        return Builder(pQuery);
      }
    };
  }
}
#endif  
