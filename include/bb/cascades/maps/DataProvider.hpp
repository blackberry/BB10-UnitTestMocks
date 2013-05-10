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
#ifndef BB_CASCADES_MAPS_DATAPROVIDER_HPP
#define BB_CASCADES_MAPS_DATAPROVIDER_HPP
#include "gtest/gtest.h"
#include <bb/cascades/maps/Global>
#include <bb/platform/geo/GeoList>
#include <bb/platform/geo/Point>
#include <QScopedPointer>
#include <QObject>
class QString;
namespace bb {
namespace cascades {
namespace maps {
class DataProviderPrivate;
class QT_CASCADES_EXPORT BB_CASCADES_MAPS_EXPORT DataProvider : public QObject {
        MOCK_METHOD2(geoAdded, void ( const QString& providerId, const QString& elementId ));
        MOCK_METHOD2(geoAddedBulk, void ( const QString& providerId, const QStringList& elementIds ));
        MOCK_METHOD2(geoRemoved, void ( const QString& providerId, const QString& elementId ));
        MOCK_METHOD2(geoRemovedBulk, void ( const QString& providerId, const QStringList& elementIds ));
        MOCK_METHOD2(visibilityChanged, void ( const QString& providerId, bool visible ));
public:
        DataProvider( const QString& id = "",
                QObject* parent = 0 );
        virtual ~DataProvider();
        MOCK_CONST_METHOD0(providerId, QString ());
        MOCK_METHOD1(setProviderId, void ( const QString& id ));
        MOCK_CONST_METHOD0(isVisible, bool ());
        MOCK_METHOD1(setVisible, void ( bool visible ));
        MOCK_CONST_METHOD0(toGeoList, bb::platform::geo::GeoList ());
        MOCK_METHOD1(add, bool ( bb::platform::geo::Geographic* element ));
        MOCK_METHOD1(add, int ( const bb::platform::geo::GeoList& elements ));
        MOCK_METHOD1(remove, bool ( const QString& elementId ));
        MOCK_METHOD1(remove, int ( const QStringList& elements ));
        MOCK_METHOD0(clear, void ());
        MOCK_CONST_METHOD1(find, bb::platform::geo::GeoList (
                const bb::platform::geo::BoundingBox& box ));
};
} 
} 
} 
#endif 
