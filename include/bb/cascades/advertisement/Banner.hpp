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
#ifndef RIM_AD_BANNER_H
#define RIM_AD_BANNER_H
#include "gtest/gtest.h"
#include <bb/cascades/Color>
#include <bb/cascades/CustomControl>
namespace bb {
namespace cascades {
namespace advertisement {
class BannerPrivate;
class QT_CASCADES_EXPORT Banner: public bb::cascades::CustomControl
{
public:
	Banner(bb::cascades::Container *container = 0);
	virtual ~Banner();
	MOCK_CONST_METHOD0(zoneId, int ());
	MOCK_METHOD1(setZoneId, void (int zoneId));
	MOCK_CONST_METHOD0(refreshRate, unsigned int ());
	MOCK_METHOD1(setRefreshRate, void (unsigned int frequency));
	MOCK_CONST_METHOD0(placeHolderURL, QUrl ());
	MOCK_METHOD1(setPlaceHolderURL, void (const QUrl &url));
	MOCK_CONST_METHOD0(backgroundColor, QVariant ());
	MOCK_METHOD1(setBackgroundColor, void (const bb::cascades::Color &color));
	MOCK_CONST_METHOD0(isTransitionsEnabled, bool ());
	MOCK_METHOD1(setTransitionsEnabled, void (bool transitionsEnabled));
	MOCK_CONST_METHOD0(borderWidth, unsigned int ());
	MOCK_METHOD1(setBorderWidth, void (unsigned int borderWidth));
	MOCK_CONST_METHOD0(borderColor, QVariant ());
	MOCK_METHOD1(setBorderColor, void (const bb::cascades::Color &borderColor));
	MOCK_METHOD0(zoneIdChanged, void ());
	MOCK_METHOD0(refreshRateChanged, void ());
	MOCK_METHOD0(placeHolderURLChanged, void ());
	MOCK_METHOD0(backgroundColorChanged, void ());
	MOCK_METHOD0(transitionsEnabledChanged, void ());
	MOCK_METHOD0(borderWidthChanged, void ());
	MOCK_METHOD0(borderColorChanged, void ());
};
} 
} 
} 
#endif 
