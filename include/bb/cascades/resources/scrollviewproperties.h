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
#ifndef cascades_scrollviewproperties_h
#define cascades_scrollviewproperties_h
#include "gmock/gmock.h"
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/scrollmode.h>
#include <bb/cascades/controls/scalingmethod.h>
#include <bb/cascades/resources/overscrolleffectmode.h>
namespace bb {
    namespace cascades {
        class ScrollViewPropertiesPrivate;
        class ScrollViewProperties : public UIObject {
public:
            ScrollViewProperties();
            virtual ~ScrollViewProperties();
            MOCK_METHOD1(setOverScrollEffectMode, void (bb::cascades::OverScrollEffectMode::Type overScrollEffectMode));
            MOCK_CONST_METHOD0(overScrollEffectMode, bb::cascades::OverScrollEffectMode::Type ());
            MOCK_METHOD0(resetOverScrollEffectMode, void ());
            MOCK_METHOD1(setScrollMode, void (bb::cascades::ScrollMode::Type scrollMode));
            MOCK_CONST_METHOD0(scrollMode, bb::cascades::ScrollMode::Type ());
            MOCK_METHOD0(resetScrollMode, void ());
            MOCK_METHOD1(setInitialScalingMethod, void ( bb::cascades::ScalingMethod::Type scalingMethod ));
            MOCK_CONST_METHOD0(initialScalingMethod, bb::cascades::ScalingMethod::Type ());
            MOCK_METHOD0(resetInitialScalingMethod, void ());
            MOCK_METHOD1(setPinchToZoomEnabled, void (bool enabled));
            MOCK_CONST_METHOD0(pinchToZoomEnabled, bool ());
            MOCK_METHOD1(setMaxContentScale, void (float scale));
            MOCK_CONST_METHOD0(maxContentScale, float ());
            MOCK_CONST_METHOD0(minContentScale, float ());
            MOCK_METHOD1(setMinContentScale, void (float scale));
            MOCK_METHOD1(overScrollEffectModeChanged, void (bb::cascades::OverScrollEffectMode::Type newOverScrollEffectMode));
            MOCK_METHOD1(scrollModeChanged, void (bb::cascades::ScrollMode::Type newScrollMode));
            MOCK_METHOD1(initialScalingMethodChanged, void (bb::cascades::ScalingMethod::Type newInitialScalingMethod));
            MOCK_METHOD1(pinchToZoomEnabledChanged, void (bool enabled));
            MOCK_METHOD1(minContentScaleChanged, void (float scale));
            MOCK_METHOD1(maxContentScaleChanged, void (float scale));
            typedef ScrollViewProperties ThisClass;
            typedef UIObject BaseClass;
        };
    }
}
#endif 
