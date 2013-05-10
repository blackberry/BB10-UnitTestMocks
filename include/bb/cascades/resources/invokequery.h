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
#ifndef cascades_invokequery_h
#define cascades_invokequery_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/system/FileTransferMode>
#include <bb/system/SecurityPerimeter>
#include <QtCore/QByteArray>
#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtCore/QVariant>
#include <QtDeclarative/QtDeclarative>
#include <bb/cascades/BaseObject>
namespace bb {
  namespace cascades {
    class InvokeQueryPrivate;
    class InvokeQuery : public BaseObject
    {
public:
      InvokeQuery(QObject* pParent=0);
      ~InvokeQuery();
      MOCK_CONST_METHOD0(mimeType, QString ());
      MOCK_CONST_METHOD0(uri, QUrl ());
      MOCK_CONST_METHOD0(fileTransferMode, bb::system::FileTransferMode::Type ());
      MOCK_CONST_METHOD0(perimeter, bb::system::SecurityPerimeter::Type ());
      MOCK_CONST_METHOD0(data, QByteArray ());
      MOCK_CONST_METHOD0(invokeActionId, QString ());
      MOCK_CONST_METHOD0(invokeTargetId, QString ());
      typedef InvokeQuery ThisClass;
      typedef BaseObject BaseClass;
    protected:
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
      {
      protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
        {
        }
      public:
        BuilderType& mimeType(const QString& mimeType) {
          this->instance().setMimeType(mimeType);
          return this->builder();
        }
        BuilderType& uri(const QUrl& uri) {
          this->instance().setUri(uri);
          return this->builder();
        }
        BuilderType& uri(const QString& uri) {
          this->instance().setUri(uri);
          return this->builder();
        }
        BuilderType& fileTransferMode(bb::system::FileTransferMode::Type mode) {
          this->instance().setFileTransferMode(mode);
          return this->builder();
        }
        BuilderType& perimeter(bb::system::SecurityPerimeter::Type perimeter) {
          this->instance().setPerimeter(perimeter);
          return this->builder();
        }
        BuilderType& data(const QByteArray& data) {
          this->instance().setData(data);
          return this->builder();
        }
        BuilderType& invokeActionId(const QString& invokeActionId) {
          this->instance().setInvokeActionId(invokeActionId);
          return this->builder();
        }
        BuilderType& invokeTargetId(const QString& invokeTargetId) {
          this->instance().setInvokeTargetId(invokeTargetId);
          return this->builder();
        }
      };
    private:
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
