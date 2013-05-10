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
#ifndef cascades_visualnode_h
#define cascades_visualnode_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/visualnodemock.h>
#include <bb/cascades/core/uiobject.h>
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
    class VisualNode : public UIObject {
public:
        virtual ~VisualNode(){}
        float opacity() { return mock<VisualNodeMock>()->opacity(); }
        void setOpacity(float opacity) { mock<VisualNodeMock>()->setOpacity( opacity); }
        void resetOpacity() { mock<VisualNodeMock>()->resetOpacity(); }
        bool isVisible() { return mock<VisualNodeMock>()->isVisible(); }
        void setVisible(bool visible) { mock<VisualNodeMock>()->setVisible( visible); }
        void resetVisible() { mock<VisualNodeMock>()->resetVisible(); }
        float translationX() { return mock<VisualNodeMock>()->translationX(); }
        void setTranslationX(float translationX) { mock<VisualNodeMock>()->setTranslationX( translationX); }
        void resetTranslationX() { mock<VisualNodeMock>()->resetTranslationX(); }
        float translationY() { return mock<VisualNodeMock>()->translationY(); }
        void setTranslationY(float translationY) { mock<VisualNodeMock>()->setTranslationY( translationY); }
        void resetTranslationY() { mock<VisualNodeMock>()->resetTranslationY(); }
        void setTranslation(float translationX, float translationY) { mock<VisualNodeMock>()->setTranslation( translationX,  translationY); }
        void resetTranslation() { mock<VisualNodeMock>()->resetTranslation(); }
        float rotationZ() { return mock<VisualNodeMock>()->rotationZ(); }
        void setRotationZ(float rotationZ) { mock<VisualNodeMock>()->setRotationZ( rotationZ); }
        void resetRotationZ() { mock<VisualNodeMock>()->resetRotationZ(); }
        float scaleX() { return mock<VisualNodeMock>()->scaleX(); }
        void setScaleX(float scaleX) { mock<VisualNodeMock>()->setScaleX( scaleX); }
        void resetScaleX() { mock<VisualNodeMock>()->resetScaleX(); }
        float scaleY() { return mock<VisualNodeMock>()->scaleY(); }
        void setScaleY(float scaleY) { mock<VisualNodeMock>()->setScaleY( scaleY); }
        void resetScaleY() { mock<VisualNodeMock>()->resetScaleY(); }
        void setScale(float scaleX, float scaleY) { mock<VisualNodeMock>()->setScale( scaleX,  scaleY); }
        void setScale(float scaleXY) { mock<VisualNodeMock>()->setScale( scaleXY); }
        void resetScale() { mock<VisualNodeMock>()->resetScale(); }
        float pivotX() { return mock<VisualNodeMock>()->pivotX(); }
        void setPivotX(float pivotX) { mock<VisualNodeMock>()->setPivotX( pivotX); }
        void resetPivotX() { mock<VisualNodeMock>()->resetPivotX(); }
        float pivotY() { return mock<VisualNodeMock>()->pivotY(); }
        void setPivotY(float pivotY) { mock<VisualNodeMock>()->setPivotY( pivotY); }
        void resetPivotY() { mock<VisualNodeMock>()->resetPivotY(); }
        void setPivot(float pivotX, float pivotY) { mock<VisualNodeMock>()->setPivot( pivotX,  pivotY); }
        void resetPivot() { mock<VisualNodeMock>()->resetPivot(); }
        TouchPropagationMode::Type touchPropagationMode() { return mock<VisualNodeMock>()->touchPropagationMode(); }
        void setTouchPropagationMode(bb::cascades::TouchPropagationMode::Type mode) { mock<VisualNodeMock>()->setTouchPropagationMode( mode); }
        void resetTouchPropagationMode() { mock<VisualNodeMock>()->resetTouchPropagationMode(); }
        bb::cascades::OverlapTouchPolicy::Type overlapTouchPolicy() { return mock<VisualNodeMock>()->overlapTouchPolicy(); }
        void setOverlapTouchPolicy(bb::cascades::OverlapTouchPolicy::Type policy) { mock<VisualNodeMock>()->setOverlapTouchPolicy( policy); }
        void resetOverlapTouchPolicy() { mock<VisualNodeMock>()->resetOverlapTouchPolicy(); }
        void addTouchBehavior(TouchBehavior* touchBehavior) { mock<VisualNodeMock>()->addTouchBehavior( touchBehavior); }
        bool removeTouchBehavior(TouchBehavior* touchBehavior) { return mock<VisualNodeMock>()->removeTouchBehavior( touchBehavior); }
        void removeAllTouchBehaviors() { mock<VisualNodeMock>()->removeAllTouchBehaviors(); }
        void addGestureHandler(GestureHandler* gestureHandler) { mock<VisualNodeMock>()->addGestureHandler( gestureHandler); }
        bool removeGestureHandler(GestureHandler* gestureHandler) { return mock<VisualNodeMock>()->removeGestureHandler( gestureHandler); }
        void removeAllGestureHandlers() { mock<VisualNodeMock>()->removeAllGestureHandlers(); }
        void addAnimation(AbstractAnimation *animation) { mock<VisualNodeMock>()->addAnimation(animation); }
        bool removeAnimation(AbstractAnimation *animation) { return mock<VisualNodeMock>()->removeAnimation(animation); }
        void removeAllAnimations() { mock<VisualNodeMock>()->removeAllAnimations(); }
        int animationCount() { return mock<VisualNodeMock>()->animationCount(); }
        AbstractAnimation * animationAt(int index) { return mock<VisualNodeMock>()->animationAt( index); }
        void opacityChanged(float opacity) { mock<VisualNodeMock>()->opacityChanged( opacity); }
        void opacityChanging(float opacity) { mock<VisualNodeMock>()->opacityChanging( opacity); }
        void visibleChanged(bool visible) { mock<VisualNodeMock>()->visibleChanged( visible); }
        void translationXChanged(float translationX) { mock<VisualNodeMock>()->translationXChanged( translationX); }
        void translationYChanged(float translationY) { mock<VisualNodeMock>()->translationYChanged( translationY); }
        void translationXChanging(float translationX) { mock<VisualNodeMock>()->translationXChanging( translationX); }
        void translationYChanging(float translationY) { mock<VisualNodeMock>()->translationYChanging( translationY); }
        void rotationZChanging(float rotationZ) { mock<VisualNodeMock>()->rotationZChanging( rotationZ); }
        void rotationZChanged(float rotationZ) { mock<VisualNodeMock>()->rotationZChanged( rotationZ); }
        void scaleXChanged(float scaleX) { mock<VisualNodeMock>()->scaleXChanged( scaleX); }
        void scaleYChanged(float scaleY) { mock<VisualNodeMock>()->scaleYChanged( scaleY); }
        void scaleXChanging(float scaleX) { mock<VisualNodeMock>()->scaleXChanging( scaleX); }
        void scaleYChanging(float scaleY) { mock<VisualNodeMock>()->scaleYChanging( scaleY); }
        void pivotXChanged(float pivotX) { mock<VisualNodeMock>()->pivotXChanged( pivotX); }
        void pivotYChanged(float pivotY) { mock<VisualNodeMock>()->pivotYChanged( pivotY); }
        void touch(bb::cascades::TouchEvent *event) { mock<VisualNodeMock>()->touch(event); }
        void touchCapture(bb::cascades::TouchEvent *event) { mock<VisualNodeMock>()->touchCapture(event); }
        void touchEnter(bb::cascades::TouchEnterEvent *event) { mock<VisualNodeMock>()->touchEnter(event); }
        void touchExit(bb::cascades::TouchExitEvent *event) { mock<VisualNodeMock>()->touchExit(event); }
        void touchPropagationModeChanged(bb::cascades::TouchPropagationMode::Type newTouchPropagationMode) { mock<VisualNodeMock>()->touchPropagationModeChanged( newTouchPropagationMode); }
        void overlapTouchPolicyChanged(bb::cascades::OverlapTouchPolicy::Type newOverlapTouchPolicy) { mock<VisualNodeMock>()->overlapTouchPolicyChanged( newOverlapTouchPolicy); }
public:
        typedef VisualNode ThisClass;  
        typedef UIObject BaseClass; 
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
protected:
      VisualNode(QObject *parent = 0): UIObject(parent) {}

    };
}
}
#endif	
