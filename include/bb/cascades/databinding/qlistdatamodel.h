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
#ifndef cascades_qlistdatamodel_h
#define cascades_qlistdatamodel_h
#include "gmock/gmock.h"
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QSharedDataPointer>
#include <QtCore/QSharedPointer>
#include <QtCore/QVariant>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/databinding/datamodel.h>
#include <bb/cascades/databinding/arraydatamodel.h>
#include <bb/cascades/databinding/qlistdatamodelmock.h>
namespace bb {
namespace cascades {
    template <class Item>
    class QListDataModel : public DataModel {
public:
    	QListDataModel(): DataModel() { }
		QListDataModel (const QList<Item> &other){ }
        virtual ~QListDataModel() {}
        int childCount(const QVariantList &indexPath){return mock<QListDataModelMock>()->childCount(indexPath);}
        bool hasChildren(const QVariantList &indexPath){return mock<QListDataModelMock>()->hasChildren(indexPath);}
        QString itemType(const QVariantList &indexPath){return mock<QListDataModelMock>()->itemType(indexPath);}
        QVariant data(const QVariantList &indexPath){return mock<QListDataModelMock>()->data(indexPath);}
        void append(const Item &value){mock<QListDataModelMock>()->append(value);}
        void append(const QList<Item> &values){mock<QListDataModelMock>()->append(values);}
        void clear(){mock<QListDataModelMock>()->clear();}
        int indexOf(const Item &value, int from){return mock<QListDataModelMock>()->indexOf(value, from);}
        int indexOf(const Item &value){return mock<QListDataModelMock>()->indexOf(value);}
        void insert(int i, const Item &value){mock<QListDataModelMock>()->insert(i, value);}
        void insert(int i, const QList<Item> &values){mock<QListDataModelMock>()->insert(i, values);}
        bool isEmpty(){return mock<QListDataModelMock>()->isEmpty();}
        void move(int from, int to){mock<QListDataModelMock>()->move(from, to);}
        void removeAt(int i){mock<QListDataModelMock>()->removeAt(i);}
        void replace(int i, const Item &value){mock<QListDataModelMock>()->replace(i, value);}
        int size(){return mock<QListDataModelMock>()->size();}
        void swap(int i, int j){mock<QListDataModelMock>()->swap(i, j);}
        Item value(int i){return mock<QListDataModelMock>()->value(i);}
        Item value(int i, const Item &defaultValue){return mock<QListDataModelMock>()->value(i, defaultValue);}
        QListDataModel &operator<<(const Item & value)
        {
        	append(value);
            return *this;
        }
};

typedef QListDataModel<QVariant> QVariantListDataModel;

typedef QListDataModel<QString> QStringListDataModel;

typedef QListDataModel<QVariantMap> QMapListDataModel;

}
}
#endif 
