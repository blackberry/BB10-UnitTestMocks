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
#ifndef cascades_datamodelmock_h
#define cascades_datamodelmock_h
#include "gmock/gmock.h"
#include <QtCore/QObject>
#include <QtDeclarative/QtDeclarative>
#include <QtCore/QList>
#include <QtCore/QVariant>
#include <QSharedPointer>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/databinding/indexmapper.h>

namespace bb {
namespace cascades {
    class DataModelMock : public QObject {
public:
        DataModelMock(QObject *parent = 0) { }
        virtual ~DataModelMock() { }
        MOCK_METHOD1(childCount, int (const QVariantList &indexPath));
        MOCK_METHOD1(hasChildren, bool (const QVariantList &indexPath));
        MOCK_METHOD1(itemType, QString (const QVariantList &indexPath));
        MOCK_METHOD1(data, QVariant (const QVariantList &indexPath));
        MOCK_METHOD1(itemAdded, void (QVariantList indexPath));
        MOCK_METHOD1(itemUpdated, void (QVariantList indexPath));
        MOCK_METHOD1(itemRemoved, void (QVariantList indexPath));

        MOCK_METHOD0(itemsChanged,
        		void());
        MOCK_METHOD1(itemsChanged,
        		void (QSharedPointer<bb::cascades::IndexMapperFake> indexMapper));
        MOCK_METHOD1(itemsChanged,
        		void (bb::cascades::DataModelChangeType::Type eChangeType));
        MOCK_METHOD2(itemsChanged,
        		void (bb::cascades::DataModelChangeType::Type eChangeType,
        		QSharedPointer<bb::cascades::IndexMapperFake> indexMapper));
    };
}
}

//Q_DECLARE_METATYPE(bb::cascades::DataModel*)

#endif 
