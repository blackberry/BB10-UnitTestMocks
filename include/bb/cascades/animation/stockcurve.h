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
#ifndef cascades_stockcurve_h
#define cascades_stockcurve_h
#include "gmock/gmock.h"
#include <QMetaType>
#include <QSharedDataPointer>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/animation/easingcurve.h>
namespace bb {
    namespace cascades {
    class StockCurveDataPrivate;
    class StockCurve : public EasingCurve {
public:
        static const StockCurve Linear;
        static const StockCurve SineOut;
        static const StockCurve QuadraticOut;
        static const StockCurve CubicOut;
        static const StockCurve ExponentialOut;
        static const StockCurve QuarticOut;
        static const StockCurve QuinticOut;
        static const StockCurve CircularOut;
        static const StockCurve BackOut;
        static const StockCurve ElasticOut;
        static const StockCurve DoubleElasticOut;
        static const StockCurve BounceOut;
        static const StockCurve DoubleBounceOut;
        static const StockCurve SineInOut;
        static const StockCurve QuadraticInOut;
        static const StockCurve CubicInOut;
        static const StockCurve ExponentialInOut;
        static const StockCurve QuarticInOut;
        static const StockCurve QuinticInOut;
        static const StockCurve CircularInOut;
        static const StockCurve BackInOut;
        static const StockCurve ElasticInOut;
        static const StockCurve DoubleElasticInOut;
        static const StockCurve BounceInOut;
        static const StockCurve DoubleBounceInOut;
        static const StockCurve SineIn;
        static const StockCurve QuadraticIn;
        static const StockCurve CubicIn;
        static const StockCurve ExponentialIn;
        static const StockCurve QuarticIn;
        static const StockCurve QuinticIn;
        static const StockCurve CircularIn;
        static const StockCurve BackIn;
        static const StockCurve ElasticIn;
        static const StockCurve DoubleElasticIn;
        static const StockCurve BounceIn;
        static const StockCurve DoubleBounceIn;
        StockCurve() { }
        StockCurve(const StockCurve& orig);
        StockCurve& operator=(const StockCurve& other);
        bool operator==(const EasingCurve &other) const;
        bool operator!=(const EasingCurve &other) const;
        virtual ~StockCurve() { }
    };
}
}
#endif	
