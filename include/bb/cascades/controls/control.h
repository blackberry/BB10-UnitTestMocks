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
#ifndef cascades_control_h
#define cascades_control_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/visualnode.h>
#include <bb/cascades/controls/controlmock.h>
#include "bb/cascades/controls/focuspolicy.h"
#include <bb/cascades/layouts/horizontalalignment.h>
#include <bb/cascades/layouts/verticalalignment.h>
#include <bb/cascades/controls/focusretentionpolicy.h>
namespace bb {
    namespace cascades {
    class ActionSet;
    class ControlPrivate;
    class ContextMenuHandler;
    class LayoutProperties;
    class Control : public VisualNode {
public:
        virtual ~Control(){}
        bb::cascades::HorizontalAlignment::Type horizontalAlignment() { return mock<ControlMock>()->horizontalAlignment(); }
        void setHorizontalAlignment(bb::cascades::HorizontalAlignment::Type horizontalAlignment) { mock<ControlMock>()->setHorizontalAlignment( horizontalAlignment); }
        void resetHorizontalAlignment() { mock<ControlMock>()->resetHorizontalAlignment(); }
        bb::cascades::VerticalAlignment::Type verticalAlignment() { return mock<ControlMock>()->verticalAlignment(); }
        void setVerticalAlignment(bb::cascades::VerticalAlignment::Type verticalAlignment) { mock<ControlMock>()->setVerticalAlignment( verticalAlignment); }
        void resetVerticalAlignment() { mock<ControlMock>()->resetVerticalAlignment(); }
        float preferredWidth() { return mock<ControlMock>()->preferredWidth(); }
        void setPreferredWidth(float preferredWidth) { mock<ControlMock>()->setPreferredWidth( preferredWidth); }
        void resetPreferredWidth() { mock<ControlMock>()->resetPreferredWidth(); }
        void setFocusRetentionPolicyFlags(bb::cascades::FocusRetentionPolicy::Types policy) { mock<ControlMock>()->setFocusRetentionPolicyFlags(policy); }
        void setFocusRetentionPolicy(bb::cascades::FocusRetentionPolicy::Type policy) { mock<ControlMock>()->setFocusRetentionPolicy( policy); }
        bb::cascades::FocusRetentionPolicy::Types focusRetentionPolicyFlags() { return mock<ControlMock>()->focusRetentionPolicyFlags(); }
        bb::cascades::FocusRetentionPolicy::Type focusRetentionPolicy() { return mock<ControlMock>()->focusRetentionPolicy(); }
        void resetFocusRetentionPolicyFlags() { mock<ControlMock>()->resetFocusRetentionPolicyFlags(); }
        void resetFocusRetentionPolicy() { mock<ControlMock>()->resetFocusRetentionPolicy(); }
        bool isPreferredWidthSet() { return mock<ControlMock>()->isPreferredWidthSet(); }
        float preferredHeight() { return mock<ControlMock>()->preferredHeight(); }
        void setPreferredHeight(float preferredHeight) { mock<ControlMock>()->setPreferredHeight( preferredHeight); }
        void resetPreferredHeight() { mock<ControlMock>()->resetPreferredHeight(); }
        bool isPreferredHeightSet() { return mock<ControlMock>()->isPreferredHeightSet(); }
        void setPreferredSize(float preferredWidth, float preferredHeight) {  mock<ControlMock>()->setPreferredSize( preferredWidth,  preferredHeight); }
        void resetPreferredSize() { mock<ControlMock>()->resetPreferredSize(); }
        float leftPadding() { return mock<ControlMock>()->leftPadding(); }
        void setLeftPadding(float leftPadding) { mock<ControlMock>()->setLeftPadding( leftPadding); }
        void resetLeftPadding() { mock<ControlMock>()->resetLeftPadding(); }
        float rightPadding() { return mock<ControlMock>()->rightPadding(); }
        void setRightPadding(float rightPadding) { mock<ControlMock>()->setRightPadding( rightPadding); }
        void resetRightPadding() { mock<ControlMock>()->resetRightPadding(); }
        float topPadding() { return mock<ControlMock>()->topPadding(); }
        void setTopPadding(float topPadding) { mock<ControlMock>()->setTopPadding( topPadding); }
        void resetTopPadding() { mock<ControlMock>()->resetTopPadding(); }
        float bottomPadding() { return mock<ControlMock>()->bottomPadding(); }
        void setBottomPadding(float bottomPadding) { mock<ControlMock>()->setBottomPadding( bottomPadding); }
        void resetBottomPadding() { mock<ControlMock>()->resetBottomPadding(); }
        bool isEnabled() { return mock<ControlMock>()->isEnabled(); }
        bb::cascades::FocusPolicy::Type focusPolicy() { return mock<ControlMock>()->focusPolicy(); }
        void setFocusPolicy(const bb::cascades::FocusPolicy::Type focusable) { mock<ControlMock>()->setFocusPolicy( focusable); }
        void resetFocusPolicy() { mock<ControlMock>()->resetFocusPolicy(); }
        bool isFocused() { return mock<ControlMock>()->isFocused(); }
        void setEnabled(bool enabled) { mock<ControlMock>()->setEnabled( enabled); }
        void resetEnabled() { mock<ControlMock>()->resetEnabled(); }
        bb::cascades::LayoutProperties* layoutProperties() { return mock<ControlMock>()->layoutProperties(); }
        void setLayoutProperties(bb::cascades::LayoutProperties *layoutProperties) { mock<ControlMock>()->setLayoutProperties(layoutProperties); }
        void resetLayoutProperties() { mock<ControlMock>()->resetLayoutProperties(); }
        float leftMargin() { return mock<ControlMock>()->leftMargin(); }
        void setLeftMargin(float leftMargin) { mock<ControlMock>()->setLeftMargin( leftMargin); }
        void resetLeftMargin() { mock<ControlMock>()->resetLeftMargin(); }
        bool isLeftMarginSet() { return mock<ControlMock>()->isLeftMarginSet(); }
        float rightMargin() { return mock<ControlMock>()->rightMargin(); }
        void setRightMargin(float rightMargin) { mock<ControlMock>()->setRightMargin( rightMargin); }
        void resetRightMargin() { mock<ControlMock>()->resetRightMargin(); }
        bool isRightMarginSet() { return mock<ControlMock>()->isRightMarginSet(); }
        float topMargin() { return mock<ControlMock>()->topMargin(); }
        void setTopMargin(float topMargin) { mock<ControlMock>()->setTopMargin( topMargin); }
        void resetTopMargin() { mock<ControlMock>()->resetTopMargin(); }
        bool isTopMarginSet() { return mock<ControlMock>()->isTopMarginSet(); }
        float bottomMargin() { return mock<ControlMock>()->bottomMargin(); }
        void setBottomMargin(float bottomMargin) { mock<ControlMock>()->setBottomMargin( bottomMargin); }
        void resetBottomMargin() { mock<ControlMock>()->resetBottomMargin(); }
        bool isBottomMarginSet() { return mock<ControlMock>()->isBottomMarginSet(); }
        float minWidth() { return mock<ControlMock>()->minWidth(); }
        void setMinWidth(float minWidth) { mock<ControlMock>()->setMinWidth( minWidth); }
        void resetMinWidth() { mock<ControlMock>()->resetMinWidth(); }
        float maxWidth() { return mock<ControlMock>()->maxWidth(); }
        void setMaxWidth(float maxWidth) { mock<ControlMock>()->setMaxWidth( maxWidth); }
        void resetMaxWidth() { mock<ControlMock>()->resetMaxWidth(); }
        float minHeight() { return mock<ControlMock>()->minHeight(); }
        void setMinHeight(float minHeight) { mock<ControlMock>()->setMinHeight( minHeight); }
        void resetMinHeight() { mock<ControlMock>()->resetMinHeight(); }
        float maxHeight() { return mock<ControlMock>()->maxHeight(); }
        void setMaxHeight(float maxHeight) { mock<ControlMock>()->setMaxHeight( maxHeight); }
        void resetMaxHeight() { mock<ControlMock>()->resetMaxHeight(); }
        void addActionSet(bb::cascades::ActionSet* actionSet) { mock<ControlMock>()->addActionSet( actionSet); }
        int actionSetCount() { return mock<ControlMock>()->actionSetCount(); }
        ActionSet* actionSetAt(int index) { return mock<ControlMock>()->actionSetAt( index); }
        bool removeActionSet(bb::cascades::ActionSet* actionSet) { return mock<ControlMock>()->removeActionSet( actionSet); }
        void removeAllActionSets() { mock<ControlMock>()->removeAllActionSets(); }
        void requestFocus() { mock<ControlMock>()->requestFocus(); }
        void loseFocus() { mock<ControlMock>()->loseFocus(); }
        bb::cascades::ContextMenuHandler* contextMenuHandler() { return mock<ControlMock>()->contextMenuHandler(); }
        void setContextMenuHandler(bb::cascades::ContextMenuHandler* contextMenuHandler) { mock<ControlMock>()->setContextMenuHandler( contextMenuHandler); }
        void resetContextMenuHandler() { mock<ControlMock>()->resetContextMenuHandler(); }
        void horizontalAlignmentChanged(bb::cascades::HorizontalAlignment::Type newHorizontalAlignment) { mock<ControlMock>()->horizontalAlignmentChanged( newHorizontalAlignment); }
        void verticalAlignmentChanged(bb::cascades::VerticalAlignment::Type newVerticalAlignment) { mock<ControlMock>()->verticalAlignmentChanged( newVerticalAlignment); }
        void preferredWidthChanged(float preferredWidth) { mock<ControlMock>()->preferredWidthChanged( preferredWidth); }
        void preferredWidthSetChanged(bool isSet) { mock<ControlMock>()->preferredWidthSetChanged( isSet); }
        void preferredHeightChanged(float preferredHeight) { mock<ControlMock>()->preferredHeightChanged( preferredHeight); }
        void preferredHeightSetChanged(bool isSet) { mock<ControlMock>()->preferredHeightSetChanged( isSet); }
        void leftPaddingChanged(float leftPadding) { mock<ControlMock>()->leftPaddingChanged( leftPadding); }
        void rightPaddingChanged(float rightPadding) { mock<ControlMock>()->rightPaddingChanged( rightPadding); }
        void topPaddingChanged(float topPadding) { mock<ControlMock>()->topPaddingChanged( topPadding); }
        void bottomPaddingChanged(float bottomPadding) { mock<ControlMock>()->bottomPaddingChanged( bottomPadding); }
        void enabledChanged(bool enabled) { mock<ControlMock>()->enabledChanged( enabled); }
        void focusedChanged(bool focused) { mock<ControlMock>()->focusedChanged( focused); }
        void layoutPropertiesChanged(bb::cascades::LayoutProperties *layoutProperties) { mock<ControlMock>()->layoutPropertiesChanged(layoutProperties); }
        void leftMarginChanged(float leftMargin) { mock<ControlMock>()->leftMarginChanged( leftMargin); }
        void leftMarginSetChanged(bool isSet) { mock<ControlMock>()->leftMarginSetChanged( isSet); }
        void topMarginChanged(float topMargin) { mock<ControlMock>()->topMarginChanged( topMargin); }
        void topMarginSetChanged(bool isSet) { mock<ControlMock>()->topMarginSetChanged( isSet); }
        void bottomMarginChanged(float bottomMargin) { mock<ControlMock>()->bottomMarginChanged( bottomMargin); }
        void bottomMarginSetChanged(bool isSet) { mock<ControlMock>()->bottomMarginSetChanged( isSet); }
        void rightMarginChanged(float rightMargin) { mock<ControlMock>()->rightMarginChanged( rightMargin); }
        void rightMarginSetChanged(bool isSet) { mock<ControlMock>()->rightMarginSetChanged( isSet); }
        void minWidthChanged(float minWidth) { mock<ControlMock>()->minWidthChanged( minWidth); }
        void maxWidthChanged(float maxWidth) { mock<ControlMock>()->maxWidthChanged( maxWidth); }
        void minHeightChanged(float minHeight) { mock<ControlMock>()->minHeightChanged( minHeight); }
        void maxHeightChanged(float maxHeight) { mock<ControlMock>()->maxHeightChanged( maxHeight); }
        void actionSetAdded(bb::cascades::ActionSet *actionSet) { mock<ControlMock>()->actionSetAdded(actionSet); }
        void actionSetRemoved(bb::cascades::ActionSet *actionSet) { mock<ControlMock>()->actionSetRemoved(actionSet); }
        void contextMenuHandlerChanged(bb::cascades::ContextMenuHandler* contextMenuHandler) { mock<ControlMock>()->contextMenuHandlerChanged( contextMenuHandler); }
        void focusRetentionPolicyFlagsChanged(bb::cascades::FocusRetentionPolicy::Types policy) { mock<ControlMock>()->focusRetentionPolicyFlagsChanged(policy); }
        void focusRetentionPolicyChanged(bb::cascades::FocusRetentionPolicy::Type policy) { mock<ControlMock>()->focusRetentionPolicyChanged( policy); }
public:
        typedef Control ThisClass;  
        typedef VisualNode BaseClass; 
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& horizontal(HorizontalAlignment::Type horizontalAlignment) {
                this->instance().setHorizontalAlignment(horizontalAlignment);
                return this->builder();
            }
            BuilderType& vertical(VerticalAlignment::Type verticalAlignment) {
                this->instance().setVerticalAlignment(verticalAlignment);
                return this->builder();
            }
            BuilderType& focusPolicy(FocusPolicy::Type _focusPolicy) {
                this->instance().setFocusPolicy(_focusPolicy);
                return this->builder();
            }
            BuilderType& preferredWidth(float _preferredWidth) {
                this->instance().setPreferredWidth(_preferredWidth);
                return this->builder();
            }
            BuilderType& preferredHeight(float _preferredHeight) {
                this->instance().setPreferredHeight(_preferredHeight);
                return this->builder();
            }
            BuilderType& preferredSize(float _preferredWidth, float _preferredHeight) {
                this->instance().setPreferredSize(_preferredWidth, _preferredHeight);
                return this->builder();
            }
            BuilderType &leftMargin(float _leftMargin) {
                this->instance().setLeftMargin(_leftMargin);
                return this->builder();
            }
            BuilderType &rightMargin(float _rightMargin) {
                this->instance().setRightMargin(_rightMargin);
                return this->builder();
            }
            BuilderType &topMargin(float _topMargin) {
                this->instance().setTopMargin(_topMargin);
                return this->builder();
            }
            BuilderType &bottomMargin(float _bottomMargin) {
                this->instance().setBottomMargin(_bottomMargin);
                return this->builder();
            }
            BuilderType &margins(float _topMargin, float _rightMargin, float _bottomMargin, float _leftMargin) {
                this->instance().setTopMargin(_topMargin);
                this->instance().setRightMargin(_rightMargin);
                this->instance().setBottomMargin(_bottomMargin);
                this->instance().setLeftMargin(_leftMargin);
                return this->builder();
            }
            BuilderType& top(float topPadding) {
              this->instance().setTopPadding(topPadding);
              return this->builder();
            }
            BuilderType& bottom(float bottomPadding) {
              this->instance().setBottomPadding(bottomPadding);
              return this->builder();
            }
            BuilderType& left(float leftPadding) {
              this->instance().setLeftPadding(leftPadding);
              return this->builder();
            }
            BuilderType& right(float rightPadding) {
              this->instance().setRightPadding(rightPadding);
              return this->builder();
            }
            BuilderType& enabled(bool _enabled) {
                this->instance().setEnabled(_enabled);
                return this->builder();
            }
            BuilderType& layoutProperties(LayoutProperties* layoutProperties) {
                this->instance().setLayoutProperties(layoutProperties);
                return this->builder();
            }           
            BuilderType& actionSet(ActionSet* actionSet) {
                this->instance().addActionSet(actionSet);
                return this->builder();
            }
            BuilderType& contextMenuHandler(ContextMenuHandler* contextMenuHandler) {
              this->instance().setContextMenuHandler(contextMenuHandler);
              return this->builder();
            }        
        };
protected:
        Control(QObject *parent = 0): VisualNode(parent) {}
    };
}
}
#endif	
