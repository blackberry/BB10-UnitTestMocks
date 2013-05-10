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
#ifndef BB_CASCADES_MAPS_RENDERENGINE_HPP
#define BB_CASCADES_MAPS_RENDERENGINE_HPP
#include "gtest/gtest.h"
#include <bb/cascades/maps/Global>
#include <bb/platform/geo/Point>
#include <bb/cascades/maps/RenderEngineInfo>
#include <bb/ImageData>
#include <QPoint>
#include <QObject>
namespace bb {
namespace cascades {
namespace maps {
class ViewProperties;
class RenderEngineConfiguration;
class MapData;
class QT_CASCADES_EXPORT BB_CASCADES_MAPS_EXPORT RenderEngine : public QObject {
public:
        MOCK_METHOD0(render, void ());
        MOCK_METHOD0(renderCompleted, void ());
        MOCK_METHOD0(coverageUnavailable, void ());
public:
        RenderEngine( QObject* parent = 0 );
        virtual ~RenderEngine();
        MOCK_CONST_METHOD0(newInstance, RenderEngine* ());
        MOCK_CONST_METHOD1(elementIdAt, QString ( const QPoint& windowCoord ));
        MOCK_METHOD1(initialize, void ( RenderEngineConfiguration config ));
        MOCK_CONST_METHOD0(isBaseMapVisible, bool ());
        MOCK_CONST_METHOD1(windowToWorld, bb::platform::geo::Point (
                const QPoint& windowCoord ));
        MOCK_CONST_METHOD1(worldToWindow, QPoint ( const bb::platform::geo::Point&
                worldCoord ));
        MOCK_CONST_METHOD1(calculateBoundingBox, bb::platform::geo::BoundingBox (
                const ViewProperties& view ));
        MOCK_METHOD1(setViewport, void ( const ViewProperties& view ));
        MOCK_METHOD1(setMapData, void ( MapData* data ));
        MOCK_METHOD1(setBaseMapVisible, void ( bool visible ));
        MOCK_METHOD0(teardown, void ());
        MOCK_CONST_METHOD0(characteristics, RenderEngineInfo ());
        MOCK_CONST_METHOD0(generateMapImage, bb::ImageData ());
        bool coverageSupported( const ViewProperties& region )
            const = 0;
        MOCK_CONST_METHOD0(coveragePriority, int ());
};
} 
} 
} 
#endif 
