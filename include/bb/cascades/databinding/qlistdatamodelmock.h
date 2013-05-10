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
#ifndef cascades_qlistdatamodelmock_h
#define cascades_qlistdatamodelmock_h
#include "gmock/gmock.h"
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QSharedDataPointer>
#include <QtCore/QSharedPointer>
#include <QtCore/QVariant>
#include <bb/cascades/bbcascades_global.h>
namespace bb {
namespace cascades {
    template <class Item>
    class QListDataModelMock : public DataModelMock {
public:
    	QListDataModelMock() {
        }
    	QListDataModelMock(const QList<Item> &other)  {
        }
        virtual ~QListDataModelMock() {}
        MOCK_METHOD1(childCount, int (const QVariantList &indexPath));
        MOCK_METHOD1(hasChildren, bool (const QVariantList &indexPath));
        MOCK_METHOD1(itemType, QString (const QVariantList &indexPath));
        MOCK_METHOD1(data, QVariant (const QVariantList &indexPath));
        MOCK_CONST_METHOD1_T(append, void (const Item &value));
        MOCK_METHOD1_T(append, void (const QList<Item> &values));
        MOCK_METHOD0(clear, void ());
        MOCK_CONST_METHOD2_T(indexOf, int (const Item &value, int from));
        MOCK_CONST_METHOD1_T(indexOf, int (const Item &value));
        MOCK_METHOD2_T(insert, void (int i, const Item &value));
        MOCK_METHOD2_T(insert, void (int i, const QList<Item> &values));
        MOCK_CONST_METHOD0(isEmpty, bool ());
        MOCK_METHOD2(move, void (int from, int to));
        MOCK_METHOD1(removeAt, void (int i));
        MOCK_METHOD2_T(replace, void (int i, const Item &value));
        MOCK_CONST_METHOD0(size, int ());
        MOCK_METHOD2(swap, void (int i, int j));
        MOCK_CONST_METHOD1_T(value, Item (int i));
        MOCK_CONST_METHOD2_T(value, Item (int i, const Item &defaultValue));
        QListDataModelMock &operator<<(const Item & value)
        {
            return *this;
        }
};

//typedef QListDataModel<QVariant> QVariantListDataModel;

//typedef QListDataModel<QString> QStringListDataModel;

//typedef QListDataModel<QVariantMap> QMapListDataModel;

}
}
#endif 
