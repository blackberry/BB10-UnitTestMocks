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
#ifndef cascades_controlmock_h
#define cascades_controlmock_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/visualnodemock.h>
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
    class ControlMock : public VisualNodeMock {
public:
        virtual ~ControlMock() { }
        MOCK_CONST_METHOD0(horizontalAlignment, bb::cascades::HorizontalAlignment::Type ());
        MOCK_METHOD1(setHorizontalAlignment, void (bb::cascades::HorizontalAlignment::Type horizontalAlignment));
        MOCK_METHOD0(resetHorizontalAlignment, void ());
        MOCK_CONST_METHOD0(verticalAlignment, bb::cascades::VerticalAlignment::Type ());
        MOCK_METHOD1(setVerticalAlignment, void (bb::cascades::VerticalAlignment::Type verticalAlignment));
        MOCK_METHOD0(resetVerticalAlignment, void ());
        MOCK_CONST_METHOD0(preferredWidth, float ());
        MOCK_METHOD1(setPreferredWidth, void (float preferredWidth));
        MOCK_METHOD0(resetPreferredWidth, void ());
        MOCK_METHOD1(setFocusRetentionPolicyFlags, void (bb::cascades::FocusRetentionPolicy::Types policy));
        MOCK_METHOD1(setFocusRetentionPolicy, void (bb::cascades::FocusRetentionPolicy::Type policy));
        MOCK_METHOD0(focusRetentionPolicyFlags, bb::cascades::FocusRetentionPolicy::Types ());
        MOCK_METHOD0(focusRetentionPolicy, bb::cascades::FocusRetentionPolicy::Type ());
        MOCK_METHOD0(resetFocusRetentionPolicyFlags, void ());
        MOCK_METHOD0(resetFocusRetentionPolicy, void ());
        MOCK_CONST_METHOD0(isPreferredWidthSet, bool ());
        MOCK_CONST_METHOD0(preferredHeight, float ());
        MOCK_METHOD1(setPreferredHeight, void (float preferredHeight));
        MOCK_METHOD0(resetPreferredHeight, void ());
        MOCK_CONST_METHOD0(isPreferredHeightSet, bool ());
        MOCK_METHOD2(setPreferredSize, void (float preferredWidth, float preferredHeight));
        MOCK_METHOD0(resetPreferredSize, void ());
        MOCK_CONST_METHOD0(leftPadding, float ());
        MOCK_METHOD1(setLeftPadding, void (float leftPadding));
        MOCK_METHOD0(resetLeftPadding, void ());
        MOCK_CONST_METHOD0(rightPadding, float ());
        MOCK_METHOD1(setRightPadding, void (float rightPadding));
        MOCK_METHOD0(resetRightPadding, void ());
        MOCK_CONST_METHOD0(topPadding, float ());
        MOCK_METHOD1(setTopPadding, void (float topPadding));
        MOCK_METHOD0(resetTopPadding, void ());
        MOCK_CONST_METHOD0(bottomPadding, float ());
        MOCK_METHOD1(setBottomPadding, void (float bottomPadding));
        MOCK_METHOD0(resetBottomPadding, void ());
        MOCK_CONST_METHOD0(isEnabled, bool ());
        MOCK_CONST_METHOD0(focusPolicy, bb::cascades::FocusPolicy::Type ());
        MOCK_METHOD1(setFocusPolicy, void (const bb::cascades::FocusPolicy::Type focusPolicy));
        MOCK_METHOD0(resetFocusPolicy, void ());
        MOCK_CONST_METHOD0(isFocused, bool ());
        MOCK_METHOD1(setEnabled, void (bool enabled));
        MOCK_METHOD0(resetEnabled, void ());
        MOCK_CONST_METHOD0(layoutProperties, bb::cascades::LayoutProperties* ());
        MOCK_METHOD1(setLayoutProperties, void (bb::cascades::LayoutProperties *layoutProperties));
        MOCK_METHOD0(resetLayoutProperties, void ());
        MOCK_CONST_METHOD0(leftMargin, float ());
        MOCK_METHOD1(setLeftMargin, void (float leftMargin));
        MOCK_METHOD0(resetLeftMargin, void ());
        MOCK_CONST_METHOD0(isLeftMarginSet, bool ());
        MOCK_CONST_METHOD0(rightMargin, float ());
        MOCK_METHOD1(setRightMargin, void (float rightMargin));
        MOCK_METHOD0(resetRightMargin, void ());
        MOCK_CONST_METHOD0(isRightMarginSet, bool ());
        MOCK_CONST_METHOD0(topMargin, float ());
        MOCK_METHOD1(setTopMargin, void (float topMargin));
        MOCK_METHOD0(resetTopMargin, void ());
        MOCK_CONST_METHOD0(isTopMarginSet, bool ());
        MOCK_CONST_METHOD0(bottomMargin, float ());
        MOCK_METHOD1(setBottomMargin, void (float bottomMargin));
        MOCK_METHOD0(resetBottomMargin, void ());
        MOCK_CONST_METHOD0(isBottomMarginSet, bool ());
        MOCK_CONST_METHOD0(minWidth, float ());
        MOCK_METHOD1(setMinWidth, void (float minWidth));
        MOCK_METHOD0(resetMinWidth, void ());
        MOCK_CONST_METHOD0(maxWidth, float ());
        MOCK_METHOD1(setMaxWidth, void (float maxWidth));
        MOCK_METHOD0(resetMaxWidth, void ());
        MOCK_CONST_METHOD0(minHeight, float ());
        MOCK_METHOD1(setMinHeight, void (float minHeight));
        MOCK_METHOD0(resetMinHeight, void ());
        MOCK_CONST_METHOD0(maxHeight, float ());
        MOCK_METHOD1(setMaxHeight, void (float maxHeight));
        MOCK_METHOD0(resetMaxHeight, void ());
        MOCK_METHOD1(addActionSet, void (bb::cascades::ActionSet* actionSet));
        MOCK_CONST_METHOD0(actionSetCount, int ());
        MOCK_CONST_METHOD1(actionSetAt, ActionSet* (int index));
        MOCK_METHOD1(removeActionSet, bool (bb::cascades::ActionSet* actionSet));
        MOCK_METHOD0(removeAllActionSets, void ());
        MOCK_METHOD0(requestFocus, void ());
        MOCK_METHOD0(loseFocus, void ());
        MOCK_CONST_METHOD0(contextMenuHandler, bb::cascades::ContextMenuHandler* ());
        MOCK_METHOD1(setContextMenuHandler, void (bb::cascades::ContextMenuHandler* contextMenuHandler));
        MOCK_METHOD0(resetContextMenuHandler, void ());
        MOCK_METHOD1(horizontalAlignmentChanged, void (bb::cascades::HorizontalAlignment::Type newHorizontalAlignment));
        MOCK_METHOD1(verticalAlignmentChanged, void (bb::cascades::VerticalAlignment::Type newVerticalAlignment));
        MOCK_METHOD1(preferredWidthChanged, void (float preferredWidth));
        MOCK_METHOD1(preferredWidthSetChanged, void (bool isSet));
        MOCK_METHOD1(preferredHeightChanged, void (float preferredHeight));
        MOCK_METHOD1(preferredHeightSetChanged, void (bool isSet));
        MOCK_METHOD1(leftPaddingChanged, void (float leftPadding));
        MOCK_METHOD1(rightPaddingChanged, void (float rightPadding));
        MOCK_METHOD1(topPaddingChanged, void (float topPadding));
        MOCK_METHOD1(bottomPaddingChanged, void (float bottomPadding));
        MOCK_METHOD1(enabledChanged, void (bool enabled));
        MOCK_METHOD1(focusedChanged, void (bool focused));
        MOCK_METHOD1(focusPolicyChanged, void (bb::cascades::FocusPolicy::Type newFocusPolicy));
        MOCK_METHOD1(layoutPropertiesChanged, void (bb::cascades::LayoutProperties *layoutProperties));
        MOCK_METHOD1(leftMarginChanged, void (float leftMargin));
        MOCK_METHOD1(leftMarginSetChanged, void (bool isSet));
        MOCK_METHOD1(topMarginChanged, void (float topMargin));
        MOCK_METHOD1(topMarginSetChanged, void (bool isSet));
        MOCK_METHOD1(bottomMarginChanged, void (float bottomMargin));
        MOCK_METHOD1(bottomMarginSetChanged, void (bool isSet));
        MOCK_METHOD1(rightMarginChanged, void (float rightMargin));
        MOCK_METHOD1(rightMarginSetChanged, void (bool isSet));
        MOCK_METHOD1(minWidthChanged, void (float minWidth));
        MOCK_METHOD1(maxWidthChanged, void (float maxWidth));
        MOCK_METHOD1(minHeightChanged, void (float minHeight));
        MOCK_METHOD1(maxHeightChanged, void (float maxHeight));
        MOCK_METHOD1(actionSetAdded, void (bb::cascades::ActionSet *actionSet));
        MOCK_METHOD1(actionSetRemoved, void (bb::cascades::ActionSet *actionSet));
        MOCK_METHOD1(contextMenuHandlerChanged, void (bb::cascades::ContextMenuHandler* contextMenuHandler));
        MOCK_METHOD1(focusRetentionPolicyFlagsChanged, void (bb::cascades::FocusRetentionPolicy::Types policy));
        MOCK_METHOD1(focusRetentionPolicyChanged, void (bb::cascades::FocusRetentionPolicy::Type policy));
public:
        typedef ControlMock ThisClass;
        typedef VisualNodeMock BaseClass;
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
    };
}
}
#endif	
