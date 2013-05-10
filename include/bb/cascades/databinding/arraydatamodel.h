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
#ifndef cascades_arraydatamodel_h
#define cascades_arraydatamodel_h
#include "gmock/gmock.h"
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtDeclarative/QtDeclarative>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/databinding/datamodel.h>
namespace bb {
namespace cascades {
  class ArrayDataModelPrivate;
  class ArrayDataModel : public DataModel {
public:
    ArrayDataModel(QObject *parent = 0);
    ArrayDataModel(const QList<QVariant> &other, QObject *parent = 0);
    virtual ~ArrayDataModel();
    MOCK_METHOD1(childCount, int (const QVariantList &indexPath));
    MOCK_METHOD1(hasChildren, bool (const QVariantList &indexPath));
    MOCK_METHOD1(itemType, QString (const QVariantList &indexPath));
    MOCK_METHOD1(data, QVariant (const QVariantList &indexPath));
    MOCK_METHOD1(append, void (const QVariantList &values));
    MOCK_METHOD1(append, void (const QVariant &value));
    MOCK_METHOD0(clear, void ());
    MOCK_CONST_METHOD2(indexOf, int (const QVariant &value, int from));
    MOCK_CONST_METHOD1(indexOf, int (const QVariant &value));
    MOCK_METHOD2(insert, void (int i, const QVariantList &values));
    MOCK_METHOD2(insert, void (int i, const QVariant &value));
    MOCK_CONST_METHOD0(isEmpty, bool ());
    MOCK_METHOD2(move, void (int from, int to));
    MOCK_METHOD1(removeAt, void (int i));
    MOCK_METHOD2(replace, void (int i, const QVariant &value));
    MOCK_CONST_METHOD0(size, int ());
    MOCK_METHOD2(swap, void (int i, int j));
    MOCK_CONST_METHOD1(value, QVariant (int i));
    MOCK_CONST_METHOD2(value, QVariant (int i, const QVariant &defaultValue));
  };
} 
} 
#endif 
