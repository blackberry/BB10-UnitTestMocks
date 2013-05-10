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
#ifndef cascades_groupdatamodel_h
#define cascades_groupdatamodel_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/databinding/datamodel.h>
#include <bb/cascades/databinding/itemgrouping.h>
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QVariantMap>
namespace bb {
namespace cascades {
    class GroupDataModelPrivate;
    class GroupDataModel : public DataModel {
public:
        const QString Item;
        const QString Header;
        GroupDataModel(QObject *parent = 0);
        GroupDataModel(const QStringList &keys, QObject *parent = 0);
        GroupDataModel(const QList<QVariantMap> &initialItems, const QStringList &keys, QObject *parent = 0);
        virtual ~GroupDataModel();
        MOCK_METHOD1(childCount, int (const QVariantList &indexPath));
        MOCK_METHOD1(hasChildren, bool (const QVariantList &indexPath));
        MOCK_METHOD1(data, QVariant (const QVariantList &indexPath));
        MOCK_METHOD1(itemType, QString (const QVariantList &indexPath));
        MOCK_CONST_METHOD0(grouping, bb::cascades::ItemGrouping::Type ());
        MOCK_METHOD1(setGrouping, void (bb::cascades::ItemGrouping::Type itemGrouping));
        MOCK_CONST_METHOD0(isSortedAscending, bool ());
        MOCK_METHOD1(setSortedAscending, void (bool ascending));
        MOCK_CONST_METHOD0(sortingKeys, QStringList ());
        MOCK_METHOD1(setSortingKeys, void (const QStringList &keys));
        MOCK_METHOD1(insert, void (QObject *object));
        MOCK_METHOD1(insert, void (const QVariantMap &item));
        MOCK_METHOD1(insertList, void (const QVariantList &items));
        MOCK_METHOD1(insertList, void (const QList<QVariantMap> &items));
        MOCK_METHOD1(insertList, void (const QList<QObject*> &items));
        MOCK_METHOD1(removeAt, bool (const QVariantList &indexPath));
        MOCK_METHOD1(remove, bool (QObject *object));
        MOCK_METHOD1(remove, bool (const QVariantMap &item));
        MOCK_METHOD2(updateItem, bool (const QVariantList &indexPath, QObject *object));
        MOCK_METHOD2(updateItem, bool (const QVariantList &indexPath, const QVariantMap &item));
        MOCK_METHOD0(clear, void ());
        MOCK_CONST_METHOD0(isEmpty, bool ());
        MOCK_CONST_METHOD0(size, int ());
        MOCK_CONST_METHOD0(first, QVariantList ());
        MOCK_CONST_METHOD0(last, QVariantList ());
        MOCK_CONST_METHOD1(before, QVariantList (const QVariantList &indexPath));
        MOCK_CONST_METHOD1(after, QVariantList (const QVariantList &indexPath));
        MOCK_CONST_METHOD1(find, QVariantList (const QVariantList &values));
        MOCK_CONST_METHOD1(find, QVariantList (QObject *object));
        MOCK_CONST_METHOD1(find, QVariantList (const QVariantMap &matchMap));
        MOCK_CONST_METHOD1(findExact, QVariantList (QObject *object));
        MOCK_CONST_METHOD1(findExact, QVariantList (const QVariantMap &matchMap));
        MOCK_CONST_METHOD1(lowerBound, QVariantList (const QVariantList &values));
        MOCK_CONST_METHOD1(lowerBound, QVariantList (QObject *object));
        MOCK_CONST_METHOD1(lowerBound, QVariantList (const QVariantMap &matchMap));
        MOCK_CONST_METHOD1(upperBound, QVariantList (const QVariantList &values));
        MOCK_CONST_METHOD1(upperBound, QVariantList (QObject *object));
        MOCK_CONST_METHOD1(upperBound, QVariantList (const QVariantMap &matchMap));
        MOCK_CONST_METHOD0(toListOfMaps, QList<QVariantMap> ());
        QList<QObject*> toListOfObjects() const;
        MOCK_METHOD1(groupingChanged, void (bb::cascades::ItemGrouping::Type newGrouping));
        MOCK_METHOD1(sortedAscendingChanged, void (bool sortedAscending));
        MOCK_METHOD1(sortingKeysChanged, void (QStringList sortingKeys));
    };
}
}
#endif 
