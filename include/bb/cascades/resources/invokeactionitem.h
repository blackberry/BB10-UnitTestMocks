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
#ifndef cascades_invokeactionitem_h
#define cascades_invokeactionitem_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/abstractactionitem.h>
#include <QtCore/QByteArray>
#include <QtCore/QObject>
#include <QtCore/QVariant>
namespace bb {
  namespace cascades {
    class InvokeActionItemPrivate;
    class InvokeQuery;
    class InvokeHandler;
    class InvokeActionItem : public AbstractActionItem
    {
public:
      InvokeActionItem(QObject* pParent=0);
      InvokeActionItem(const bb::cascades::InvokeQuery * query, QObject* pParent=0);
      virtual ~InvokeActionItem();
      MOCK_CONST_METHOD0(query, bb::cascades::InvokeQuery* ());
      MOCK_CONST_METHOD0(invocationData, QByteArray ());
      MOCK_METHOD1(setInvocationData, void (const QByteArray& invocationData));
      MOCK_METHOD0(resetInvocationData, void ());
      MOCK_CONST_METHOD0(metadata, QVariantMap ());
      MOCK_METHOD1(setMetadata, void (const QVariantMap& metadata));
      MOCK_METHOD0(resetMetadata, void ());
      MOCK_CONST_METHOD0(handler, bb::cascades::InvokeHandler* ());
      MOCK_METHOD1(setHandler, void (bb::cascades::InvokeHandler* pHandler));
      MOCK_METHOD0(resetHandler, void ());
      MOCK_METHOD1(dataChanged, void (const QByteArray& data));
      MOCK_METHOD1(dataChangedQml, void (const QVariant& data));
      MOCK_METHOD1(metadataChanged, void (const QVariantMap& metadata));
      MOCK_METHOD1(handlerChanged, void (const bb::cascades::InvokeHandler* handler));
      typedef InvokeActionItem ThisClass;
      typedef AbstractActionItem BaseClass;
      QVariant dataQml() const;
      void setDataQml(const QVariant& data);
      void setQuery(const bb::cascades::InvokeQuery* pQuery);
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
      {
      protected:
        TBuilder(BuiltType* node)
          : BaseClass::TBuilder<BuilderType, BuiltType>(node)
        {
        }
      public:
        BuilderType& handler(InvokeHandler* const pHandler) {
          this->instance().setHandler(pHandler);
          return this->builder();
        }
      };
      class Builder : public TBuilder<Builder, ThisClass>
      {
      public:
        Builder(bb::cascades::InvokeQuery* pQuery)
          : TBuilder<Builder, ThisClass>(new ThisClass(pQuery))
        {
        }
      };
    public:
    static Builder create(bb::cascades::InvokeQuery* pQuery) {
         return Builder(pQuery);
      }
    };
  }
}
#endif  
