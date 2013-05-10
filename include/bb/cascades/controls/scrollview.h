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
#ifndef cascades_scrollview_h
#define cascades_scrollview_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/resources/scrollanimation.h>
#include <bb/cascades/resources/scrollviewproperties.h>
namespace bb {
    namespace cascades {
    class Container;
    class ScrollViewPrivate;
    class ScrollView : public Control
    {
public:
        ScrollView(bb::cascades::Container * parent = 0);
        virtual ~ScrollView();
        MOCK_METHOD1(setContent, void (bb::cascades::Control* content));
        MOCK_CONST_METHOD0(content, bb::cascades::Control* ());
        MOCK_CONST_METHOD0(viewableArea, QRectF ());
        MOCK_CONST_METHOD0(contentScale, float ());
        MOCK_CONST_METHOD0(scrollViewProperties, bb::cascades::ScrollViewProperties* ());
        MOCK_METHOD3(scrollToPoint, void (float x, float y, bb::cascades::ScrollAnimation::Type scrollAnimation = bb::cascades::ScrollAnimation::Default ));
        MOCK_METHOD1(resetViewableArea, void ( bb::cascades::ScrollAnimation::Type scrollAnimation = bb::cascades::ScrollAnimation::Default ));
        MOCK_METHOD4(zoomToPoint, void ( float x, float y, float contentScale, bb::cascades::ScrollAnimation::Type scrollAnimation = bb::cascades::ScrollAnimation::Default ));
        MOCK_METHOD2(zoomToRect, void ( const QRectF& rect, bb::cascades::ScrollAnimation::Type scrollAnimation = bb::cascades::ScrollAnimation::Default ));
        MOCK_METHOD1(contentChanged, void (bb::cascades::Control* content));
        MOCK_METHOD2(viewableAreaChanging, void (const QRectF &viewableArea, float contentScale));
        MOCK_METHOD2(viewableAreaChanged, void (const QRectF &viewableArea, float contentScale));
         MOCK_METHOD1(contentScaleChanged, void ( float scale ));
        typedef ScrollView ThisClass;
        typedef Control BaseClass;
    public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
        public:
            BuilderType& content(bb::cascades::Control* control) {
                this->instance().setContent(control);
                return this->builder();
            }
            BuilderType& overScrollEffectMode(bb::cascades::OverScrollEffectMode::Type overScrollEffectMode) {
                this->instance().scrollViewProperties()->setOverScrollEffectMode(overScrollEffectMode);
                return this->builder();
            }
            BuilderType& scrollMode(bb::cascades::ScrollMode::Type mode) {
                this->instance().scrollViewProperties()->setScrollMode(mode);
                return this->builder();
            }
            BuilderType& initialScalingMethod(bb::cascades::ScalingMethod::Type scalingMethod) {
                this->instance().scrollViewProperties()->setInitialScalingMethod(scalingMethod);
                return this->builder();
            }
            BuilderType& pinchToZoomEnabled(bool enabled) {
                this->instance().scrollViewProperties()->setPinchToZoomEnabled(enabled);
                return this->builder();
            }
            BuilderType& minContentScale(float minScale) {
                this->instance().scrollViewProperties()->setMinContentScale(minScale);
                return this->builder();
            }
            BuilderType& maxContentScale(float maxScale) {
                this->instance().scrollViewProperties()->setMaxContentScale(maxScale);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, ScrollView> {
        public:
            Builder() : TBuilder<Builder, ScrollView>(new ScrollView()) {}
        };
      static Builder create() {
            return Builder();
        }
      static Builder create(bb::cascades::Control* content) {
            return Builder().content(content);
        }
    };
  } 
} 
#endif 
