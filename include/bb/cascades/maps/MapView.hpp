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
#ifndef BB_CASCADES_MAPS_MAPVIEW_HPP
#define BB_CASCADES_MAPS_MAPVIEW_HPP
#include "gtest/gtest.h"
#include <bb/cascades/maps/Global>
#include <bb/platform/geo/Point>
#include <bb/platform/geo/AltitudeMode>
#include <bb/cascades/CustomControl>
#include <bb/ImageData>
namespace bb {
namespace cascades {
class TapEvent;
}
}
namespace bb {
namespace cascades {
namespace maps {
class MapData;
class ViewProperties;
class DataProvider;
class RenderEngine;
class MapViewPrivate;
class QT_CASCADES_EXPORT BB_CASCADES_MAPS_EXPORT MapView : public bb::cascades::CustomControl {
public:
        MapView( bb::cascades::Container* parent = 0 );
        virtual ~MapView();
        MOCK_CONST_METHOD0(altitude, double ());
        MOCK_METHOD1(setAltitude, void ( double newAlt ));
        MOCK_METHOD0(resetAltitude, void ());
        MOCK_CONST_METHOD0(altitudeMode, bb::platform::geo::AltitudeMode::Type ());
        MOCK_METHOD1(setAltitudeMode, void ( bb::platform::geo::AltitudeMode::Type newAlt ));
        MOCK_METHOD0(resetAltitudeMode, void ());
        MOCK_CONST_METHOD0(heading, double ());
        MOCK_METHOD1(setHeading, void ( double newHeading ));
        MOCK_METHOD0(resetHeading, void ());
        MOCK_CONST_METHOD0(latitude, double ());
        MOCK_METHOD1(setLatitude, void ( double newLat ));
        MOCK_METHOD0(resetLatitude, void ());
        MOCK_CONST_METHOD0(longitude, double ());
        MOCK_METHOD1(setLongitude, void ( double newLon ));
        MOCK_METHOD0(resetLongitude, void ());
        MOCK_CONST_METHOD0(tilt, int ());
        MOCK_METHOD1(setTilt, void ( int newTilt ));
        MOCK_METHOD0(resetTilt, void ());
        MOCK_CONST_METHOD0(focusedId, QString ());
        MOCK_METHOD1(setFocusedId, void ( const QString& newFocusedId ));
        MOCK_METHOD0(resetFocusedId, void ());
        MOCK_METHOD0(setLocationOnFocused, void ());
        MOCK_METHOD0(mapData, MapData* ());
        MOCK_CONST_METHOD0(mapData, const MapData* ());
        MOCK_METHOD1(setMapData, void ( MapData* data ));
        MOCK_METHOD1(setLocation, bool ( const bb::platform::geo::Point& loc ));
        MOCK_METHOD2(setLocationWindowAbsolute, bool ( int x, int y ));
        MOCK_METHOD1(setLocationWindowAbsolute, bool ( const QPoint& pixelLocation ));
        MOCK_METHOD2(setLocationWindowDelta, bool ( int deltaX, int deltaY ));
        MOCK_METHOD1(setLocationWindowDelta, bool ( const QPoint& deltaPixelLocation));
        MOCK_CONST_METHOD0(viewProperties, ViewProperties ());
        MOCK_METHOD1(setRenderEngine, void ( RenderEngine* newEngine ));
        MOCK_METHOD1(setRenderEngine, bool ( const QString& pluginName ));
        MOCK_METHOD0(generateStaticMapImage, bb::ImageData ());
        MOCK_CONST_METHOD0(boundingBox, bb::platform::geo::BoundingBox ());
        MOCK_CONST_METHOD0(url, QString ());
        MOCK_METHOD1(altitudeChanged, void ( double newAlt ));
        MOCK_METHOD1(altitudeModeChanged, void ( bb::platform::geo::AltitudeMode::Type mode ));
        MOCK_METHOD1(headingChanged, void ( double newHeading ));
        MOCK_METHOD1(latitudeChanged, void ( double newLat ));
        MOCK_METHOD1(longitudeChanged, void ( double newLon ));
        MOCK_METHOD1(tiltChanged, void ( int newTilt ));
        MOCK_METHOD1(focusedIdChanged, void ( const QString& idWithFocus ));
        MOCK_METHOD0(requestRender, void ());
        MOCK_CONST_METHOD1(locationTapped, void ( const QString& id ));
        MOCK_CONST_METHOD1(locationLongPressed, void ( const QString& id ));
        MOCK_CONST_METHOD1(mapLongPressed, void ( const bb::platform::geo::Point& coordinates ));
        MOCK_CONST_METHOD0(captionButtonClicked, void ());
        MOCK_CONST_METHOD1(captionLabelTapped, void ( bb::cascades::TapEvent* tapEvent ));
};
} 
} 
} 
#endif 
