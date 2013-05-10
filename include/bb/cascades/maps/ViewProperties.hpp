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
#ifndef BB_CASCADES_MAPS_VIEW_PROPERTIES_HPP
#define BB_CASCADES_MAPS_VIEW_PROPERTIES_HPP
#include "gtest/gtest.h"
#include <bb/cascades/maps/Global>
#include <bb/platform/geo/Point>
#include <bb/platform/geo/BoundingBox>
#include <QSharedDataPointer>
#include <QPoint>
#include <QSize>
#include <QDebug>
namespace bb {
namespace cascades {
namespace maps {
class ViewPropertiesPrivate;
class QT_CASCADES_EXPORT BB_CASCADES_MAPS_EXPORT ViewProperties {
public:
        ViewProperties();
        ~ViewProperties();
        ViewProperties( const ViewProperties& src );
        ViewProperties& operator=( const ViewProperties& src );
        MOCK_CONST_METHOD0(altitude, double ());
        MOCK_METHOD1(setAltitude, bool ( double alt ));
        MOCK_CONST_METHOD0(altitudeMode, bb::platform::geo::AltitudeMode::Type ());
        MOCK_METHOD1(setAltitudeMode, bool ( bb::platform::geo::AltitudeMode::Type mode ));
        MOCK_CONST_METHOD0(heading, double ());
        MOCK_METHOD1(setHeading, bool ( double heading ));
        MOCK_CONST_METHOD0(latitude, double ());
        MOCK_METHOD1(setLatitude, bool ( double newLat ));
        MOCK_CONST_METHOD0(longitude, double ());
        MOCK_METHOD1(setLongitude, bool ( double newLon ));
        MOCK_CONST_METHOD0(center, bb::platform::geo::Point ());
        MOCK_CONST_METHOD0(tilt, int ());
        MOCK_METHOD1(setTilt, bool ( int newTilt ));
        MOCK_CONST_METHOD0(windowSize, QSize ());
        MOCK_METHOD1(setWindow, void ( const QRect& newDimensions ));
        MOCK_CONST_METHOD0(windowMidpoint, QPoint ());
        MOCK_CONST_METHOD0(boundingBox, bb::platform::geo::BoundingBox ());
        MOCK_METHOD1(setBoundingBox, void ( const bb::platform::geo::BoundingBox& box ));
};
} 
} 
} 
#endif 
