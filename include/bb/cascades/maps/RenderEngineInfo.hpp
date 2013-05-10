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
#ifndef BB_CASCADES_MAPS_RENDER_ENGINE_INFO_HPP
#define BB_CASCADES_MAPS_RENDER_ENGINE_INFO_HPP
#include "gtest/gtest.h"
#include <bb/platform/geo/Global>
#include <QSharedDataPointer>
namespace bb {
namespace cascades {
namespace maps {
class RenderEngineInfoPrivate;
class QT_CASCADES_EXPORT BB_PLATFORM_GEO_EXPORT RenderEngineInfo {
public:
        RenderEngineInfo();
        RenderEngineInfo( const RenderEngineInfo& src );
        ~RenderEngineInfo();
        RenderEngineInfo& operator=( const RenderEngineInfo& src );
        MOCK_CONST_METHOD0(minimumAltitude, int ());
        MOCK_METHOD1(setMinimumAltitude, void ( int minimunAltitude ));
        MOCK_CONST_METHOD0(maximumAltitude, int ());
        MOCK_METHOD1(setMaximumAltitude, void ( int maximumAltitude ));
#endif 
