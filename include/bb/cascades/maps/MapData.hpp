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
#ifndef BB_CASCADES_MAPS_MAPDATA_HPP
#define BB_CASCADES_MAPS_MAPDATA_HPP
#include "gtest/gtest.h"
#include <bb/cascades/maps/Global>
#include <bb/platform/geo/GeoList>
#include <QString>
#include <QObject>
namespace bb {
namespace platform {
namespace geo {
class Geographic;
}
}
}
namespace bb {
namespace cascades {
namespace maps {
class DataProvider;
class MapDataPrivate;
class QT_CASCADES_EXPORT BB_CASCADES_MAPS_EXPORT MapData : public QObject {
        MOCK_METHOD1(focusedIdChanged, void ( const QString& focusedId ));
        MOCK_METHOD2(geoAdded, void ( const QString& providerId, const QString& elementId ));
        MOCK_METHOD2(geoAddedBulk, void ( const QString& providerId, const QStringList& elementIds ));
        MOCK_METHOD2(geoRemoved, void ( const QString& providerId, const QString& elementId ));
        MOCK_METHOD2(geoRemovedBulk, void ( const QString& providerId, const QStringList& elementIds ));
        MOCK_METHOD2(visibilityChanged, void ( const QString& providerId, bool visible ));
public:
        MapData( QObject* parent = 0 );
        virtual ~MapData();
        MOCK_METHOD1(addProvider, bool ( DataProvider* provider ));
        MOCK_METHOD1(removeProvider, bool ( const QString& providerId ));
        MOCK_CONST_METHOD0(providerCount, int ());
        MOCK_CONST_METHOD0(providerIds, QList<QString> ());
        MOCK_CONST_METHOD0(defaultProvider, DataProvider* ());
        MOCK_CONST_METHOD1(provider, DataProvider* ( const QString& providerId ));
        MOCK_CONST_METHOD1(find, bb::platform::geo::GeoList (
                const bb::platform::geo::BoundingBox& box ));
        MOCK_CONST_METHOD0(focusedId, QString ());
        MOCK_METHOD1(setFocusedId, bool ( const QString& newId ));
        MOCK_METHOD0(resetFocusedId, void ());
        MOCK_METHOD0(focusedGeographic, bb::platform::geo::Geographic* ());
        MOCK_METHOD1(add, bool ( bb::platform::geo::Geographic* geo ));
        MOCK_METHOD1(add, int ( const bb::platform::geo::GeoList& elements ));
        MOCK_METHOD1(remove, bool ( const QString& id ));
        MOCK_METHOD1(remove, int ( const QStringList& elements ));
        MOCK_METHOD1(geographic, bb::platform::geo::Geographic* ( const QString& id ));
        MOCK_METHOD0(clear, void ());
};
} 
} 
} 
#endif 
