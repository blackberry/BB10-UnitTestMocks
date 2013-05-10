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
#ifndef cascades_xmldatamodel_h
#define cascades_xmldatamodel_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/databinding/datamodel.h>
namespace bb {
namespace cascades {
    class XmlDataModelPrivate;
    class XmlDataModel : public DataModel {
public:
        XmlDataModel(QObject *parent = 0);
        virtual ~XmlDataModel();
        MOCK_METHOD1(childCount, int (const QVariantList &indexPath));
        MOCK_METHOD1(hasChildren, bool (const QVariantList &indexPath));
        MOCK_METHOD1(data, QVariant (const QVariantList &indexPath));
        MOCK_METHOD1(itemType, QString (const QVariantList &indexPath));
        MOCK_METHOD1(setSource, void (const QUrl &newSource));
        MOCK_CONST_METHOD0(source, QUrl ());
        MOCK_METHOD1(sourceChanged, void (QUrl source));
    };
}
}
#endif 
