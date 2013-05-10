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
#ifndef cascades_invokehandler_h
#define cascades_invokehandler_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QString>
#include <bb/cascades/BaseObject>
namespace bb {
  namespace cascades {
    class InvokeHandlerPrivate;
    class InvokeHandlerPrivateSender;
    class InvokeHandler : public BaseObject
    {
public:
      ~InvokeHandler();
      MOCK_METHOD0(confirm, void ());
      MOCK_METHOD0(cancel, void ());
      MOCK_METHOD0(invoking, void ());
      typedef InvokeHandler ThisClass;
      typedef BaseObject BaseClass;
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
      {
      protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
      public:
        BuilderType& onInvoking(const QObject* receiver, const char *method) {
            this->connect(SIGNAL(invoking()), receiver, method);
            return this->builder();
        }
      };
      class Builder : public TBuilder<Builder, ThisClass>
      {
      public:
        Builder()
          : TBuilder<Builder, ThisClass>(new ThisClass()) {
        }
      };
    public:
    static Builder create() {
         return Builder();
      }
    };
  }
}
#endif  
