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
#ifndef cascades_datamodel_h
#define cascades_datamodel_h
#include "gmock/gmock.h"
#include <QtCore/QObject>
#include <QtDeclarative/QtDeclarative>
#include <QtCore/QList>
#include <QtCore/QVariant>
#include <QSharedPointer>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/databinding/datamodelchangetype.h>
#include <bb/testing/proxybase.h>
#include <bb/cascades/databinding/datamodelmock.h>
namespace bb {
namespace cascades {
    class DataModel : public QObject, public bb::testing::ProxyBase<DataModelMock> {
public:
    	/*
        class IndexMapper {
        public:
        	virtual ~IndexMapper() { }
			MOCK_CONST_METHOD3(newIndexPath, bool (QVariantList *pOutIndexPath, int *pOutReplacementIndex,
				const QVariantList &oldIndexPath));
        };
        */

        DataModel(QObject* parent = 0): QObject(parent), bb::testing::ProxyBase<DataModelMock>() { }
        virtual ~DataModel() { }
        int childCount(const QVariantList &indexPath){return mock()->childCount(indexPath);}
        bool hasChildren(const QVariantList &indexPath){return mock()->hasChildren(indexPath);}
        QString itemType(const QVariantList &indexPath){return mock()->itemType(indexPath);}
        QVariant data(const QVariantList &indexPath){return mock()->data(indexPath);}
        void itemAdded(QVariantList indexPath){mock()->itemAdded(indexPath);}
        void itemUpdated(QVariantList indexPath){mock()->itemUpdated(indexPath);}
        void itemRemoved(QVariantList indexPath){mock()->itemRemoved(indexPath);}
        /*
        void itemsChanged(bb::cascades::DataModelChangeType::Type eChangeType = bb::cascades::DataModelChangeType::Init,
            QSharedPointer<bb::cascades::DataModel::IndexMapper> indexMapper = QSharedPointer<bb::cascades::DataModel::IndexMapper>(0))
        	{mock()->itemsChanged(eChangeType, indexMapper);}
        	*/
    };
}
}

Q_DECLARE_METATYPE(bb::cascades::DataModel*)

#endif 
