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
#ifndef BB_CASCADES_MAPS_MAPFACTORY_HPP
#define BB_CASCADES_MAPS_MAPFACTORY_HPP
#include "gtest/gtest.h"
#include <bb/cascades/maps/Global>
#include <bb/platform/geo/GeoList>
#include <bb/cascades/maps/ViewProperties>
#include <bb/ImageData>
namespace bb {
namespace cascades {
namespace maps {
BB_CASCADES_MAPS_EXPORT bb::ImageData generateStaticMapImage( const bb::cascades::maps::ViewProperties&
        viewProperties );
BB_CASCADES_MAPS_EXPORT bb::ImageData generateStaticMapImage( const bb::cascades::maps::ViewProperties&
        viewProperties, const bb::platform::geo::GeoList& data);
BB_CASCADES_MAPS_EXPORT QString generateMapUrl(
        const bb::cascades::maps::ViewProperties& viewProperties,
        const QString& label );
};
} 
} 
} 
#endif 
