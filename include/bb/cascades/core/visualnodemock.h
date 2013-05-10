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
#ifndef cascades_visualnodemock_h
#define cascades_visualnodemock_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobjectmock.h>
#include <bb/cascades/core/touchevent.h>
#include <bb/cascades/core/touchpropagation.h>
#include <bb/cascades/core/overlaptouchpolicy.h>
namespace bb {
    namespace cascades {
    class VisualNodePrivate;
    class AbstractAnimation;
    class TouchEvent;
    class TouchBehavior;
    class TouchEnterEvent;
    class TouchExitEvent;
    class GestureHandler;
    class VisualNodeMock : public UIObjectMock {
public:
    	VisualNodeMock(){}
        virtual ~VisualNodeMock() { }
        MOCK_CONST_METHOD0(opacity, float ());
        MOCK_METHOD1(setOpacity, void (float opacity));
        MOCK_METHOD0(resetOpacity, void ());
        MOCK_CONST_METHOD0(isVisible, bool ());
        MOCK_METHOD1(setVisible, void (bool visible));
        MOCK_METHOD0(resetVisible, void ());        
        MOCK_CONST_METHOD0(translationX, float ());
        MOCK_METHOD1(setTranslationX, void (float translationX));
        MOCK_METHOD0(resetTranslationX, void ());
        MOCK_CONST_METHOD0(translationY, float ());
        MOCK_METHOD1(setTranslationY, void (float translationY));
        MOCK_METHOD0(resetTranslationY, void ());
        MOCK_METHOD2(setTranslation, void (float translationX, float translationY));
        MOCK_METHOD0(resetTranslation, void ());
        MOCK_CONST_METHOD0(rotationZ, float ());
        MOCK_METHOD1(setRotationZ, void (float rotationZ));
        MOCK_METHOD0(resetRotationZ, void ());
        MOCK_CONST_METHOD0(scaleX, float ());
        MOCK_METHOD1(setScaleX, void (float scaleX));
        MOCK_METHOD0(resetScaleX, void ());
        MOCK_CONST_METHOD0(scaleY, float ());
        MOCK_METHOD1(setScaleY, void (float scaleY));
        MOCK_METHOD0(resetScaleY, void ());
        MOCK_METHOD2(setScale, void (float scaleX, float scaleY));
        MOCK_METHOD1(setScale, void (float scaleXY));
        MOCK_METHOD0(resetScale, void ());
        MOCK_CONST_METHOD0(pivotX, float ());
        MOCK_METHOD1(setPivotX, void (float pivotX));
        MOCK_METHOD0(resetPivotX, void ());
        MOCK_CONST_METHOD0(pivotY, float ());
        MOCK_METHOD1(setPivotY, void (float pivotY));
        MOCK_METHOD0(resetPivotY, void ());
        MOCK_METHOD2(setPivot, void (float pivotX, float pivotY));
        MOCK_METHOD0(resetPivot, void ());
        MOCK_CONST_METHOD0(touchPropagationMode, TouchPropagationMode::Type ());
        MOCK_METHOD1(setTouchPropagationMode, void (bb::cascades::TouchPropagationMode::Type mode));
        MOCK_METHOD0(resetTouchPropagationMode, void ());
        MOCK_CONST_METHOD0(overlapTouchPolicy, bb::cascades::OverlapTouchPolicy::Type ());
        MOCK_METHOD1(setOverlapTouchPolicy, void (bb::cascades::OverlapTouchPolicy::Type policy));
        MOCK_METHOD0(resetOverlapTouchPolicy, void ());
        MOCK_METHOD1(addTouchBehavior, void (TouchBehavior* touchBehavior));
        MOCK_METHOD1(removeTouchBehavior, bool (TouchBehavior* touchBehavior));
        MOCK_METHOD0(removeAllTouchBehaviors, void ());
        MOCK_METHOD1(addGestureHandler, void (GestureHandler* gestureHandler));
        MOCK_METHOD1(removeGestureHandler, bool (GestureHandler* gestureHandler));
        MOCK_METHOD0(removeAllGestureHandlers, void ());
        MOCK_METHOD1(addAnimation, void (AbstractAnimation *animation));
        MOCK_METHOD1(removeAnimation, bool (AbstractAnimation *animation));
        MOCK_METHOD0(removeAllAnimations, void ());
        MOCK_CONST_METHOD0(animationCount, int ());
        MOCK_CONST_METHOD1(animationAt, AbstractAnimation * (int index));
        MOCK_METHOD1(opacityChanged, void (float opacity));
        MOCK_METHOD1(opacityChanging, void (float opacity));     
        MOCK_METHOD1(visibleChanged, void (bool visible));
        MOCK_METHOD1(translationXChanged, void (float translationX));
        MOCK_METHOD1(translationYChanged, void (float translationY));
        MOCK_METHOD1(translationXChanging, void (float translationX));
        MOCK_METHOD1(translationYChanging, void (float translationY));
        MOCK_METHOD1(rotationZChanging, void (float rotationZ));
        MOCK_METHOD1(rotationZChanged, void (float rotationZ));
        MOCK_METHOD1(scaleXChanged, void (float scaleX));
        MOCK_METHOD1(scaleYChanged, void (float scaleY));
        MOCK_METHOD1(scaleXChanging, void (float scaleX));
        MOCK_METHOD1(scaleYChanging, void (float scaleY));
        MOCK_METHOD1(pivotXChanged, void (float pivotX));
        MOCK_METHOD1(pivotYChanged, void (float pivotY));
        MOCK_METHOD1(touch, void (bb::cascades::TouchEvent *event));
        MOCK_METHOD1(touchCapture, void (bb::cascades::TouchEvent *event));
        MOCK_METHOD1(touchEnter, void (bb::cascades::TouchEnterEvent *event));
        MOCK_METHOD1(touchExit, void (bb::cascades::TouchExitEvent *event));
        MOCK_METHOD1(touchPropagationModeChanged, void (bb::cascades::TouchPropagationMode::Type newTouchPropagationMode));
        MOCK_METHOD1(overlapTouchPolicyChanged, void (bb::cascades::OverlapTouchPolicy::Type newOverlapTouchPolicy));
public:
        typedef VisualNodeMock ThisClass;
        typedef UIObjectMock BaseClass;
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
      protected:
          TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
          }
      public:
          BuilderType& tx(float translationX) {
              this->instance().setTranslationX(translationX);
              return this->builder();
          }
          BuilderType& ty(float translationY) {
              this->instance().setTranslationY(translationY);
              return this->builder();
          }
          BuilderType& translate(float translationX, float translationY) {
              this->instance().setTranslation(translationX, translationY);
              return  this->builder();
          }
          BuilderType& rz(float rotationZ) {
              this->instance().setRotationZ(rotationZ);
              return this->builder();
          }
          BuilderType& sx(float scaleX) {
              this->instance().setScaleX(scaleX);
              return this->builder();
          }
          BuilderType& sy(float scaleY) {
              this->instance().setScaleY(scaleY);
              return this->builder();
          }
          BuilderType& scale(float scaleX, float scaleY) {
              this->instance().setScale(scaleX, scaleY);
              return this->builder();
          }
          BuilderType& scale(float scaleXY) {
              this->instance().setScale(scaleXY);
              return this->builder();
          }
          BuilderType& pivotX(float pivotX) {
              this->instance().setPivotX(pivotX);
              return this->builder();
          }
          BuilderType& pivotY(float pivotY) {
              this->instance().setPivotY(pivotY);
              return this->builder();
          }
          BuilderType& pivot(float pivotX, float pivotY) {
              this->instance().setPivot(pivotX, pivotY);
              return this->builder();
          }
          BuilderType& opacity(float opacity) {
              this->instance().setOpacity(opacity);
              return  this->builder();
          }
          BuilderType& visible(bool visible) {
              this->instance().setVisible(visible);
              return  this->builder();
          }
          BuilderType& addGestureHandler(GestureHandler* gestureHandler) {
              this->instance().addGestureHandler(gestureHandler);
              return this->builder();
          }
            BuilderType& onTouch(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(touch(bb::cascades::TouchEvent*)), receiver, method);
                return this->builder();
            }
            BuilderType& onTouchCapture(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(touchCapture(bb::cascades::TouchEvent*)), receiver, method);
                return this->builder();
            }
      };
    };
}
}
#endif	
