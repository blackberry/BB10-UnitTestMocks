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
#ifndef BB_CASCADES_FOREIGNWINDOWCONTROL_H
#define BB_CASCADES_FOREIGNWINDOWCONTROL_H
#include "gmock/gmock.h"
#include <QString>
#include <QRectF>
#include <QVariant>
#include <screen/screen.h>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/Control>
#include <bb/cascades/WindowProperty>
namespace bb {
namespace cascades {
class ForeignWindowControlPrivate;
class Container;
class ForeignWindowControl : public Control
{
public:
    ForeignWindowControl(Container * parent = 0);
    virtual ~ForeignWindowControl();
    MOCK_CONST_METHOD0(windowHandle, screen_window_t ());
    MOCK_CONST_METHOD0(windowGroup, QString ());
    MOCK_CONST_METHOD0(windowId, QString ());
    MOCK_CONST_METHOD0(isBoundToWindow, bool ());
    MOCK_CONST_METHOD0(updatedProperties, bb::cascades::WindowProperty::Types ());
    MOCK_CONST_METHOD0(isKeyInputForwardingEnabled, bool ());
    MOCK_METHOD1(setWindowGroup, void (const QString &windowGroup));
    MOCK_METHOD1(setWindowId, void (const QString &windowId));
    MOCK_METHOD1(setWindowHandle, void (screen_window_t handle));
    MOCK_METHOD1(setUpdatedProperties, void (bb::cascades::WindowProperty::Types updatedProperties));
    MOCK_METHOD1(setKeyInputForwardingEnabled, void (bool keyInputForwardingEnabled));
    MOCK_METHOD0(resetUpdatedProperties, void ());
    MOCK_METHOD0(resetKeyInputForwardingEnabled, void ());
    MOCK_METHOD3(bindToWindow, void (screen_window_t windowHandle,
                      const QString &windowGroup,
                      const QString &windowId));
    MOCK_METHOD0(unbindFromWindow, void ());
    MOCK_METHOD0(showContextMenu, void ());
    MOCK_METHOD3(windowAttached, void (screen_window_t windowHandle,
                        const QString &windowGroup,
                        const QString &windowId));
    MOCK_METHOD3(windowAttached, void (const QVariant &windowHandle,
                        const QString &windowGroup,
                        const QString &windowId));
    MOCK_METHOD0(windowDetached, void ());
    MOCK_METHOD1(windowHandleChanged, void (screen_window_t windowHandle));
    MOCK_METHOD1(windowHandleChanged, void (const QVariant & windowHandle));
    MOCK_METHOD1(windowGroupChanged, void (const QString& windowGroup));
    MOCK_METHOD1(windowIdChanged, void (const QString& windowId));
    MOCK_METHOD1(boundToWindowChanged, void (bool boundToWindow));
    MOCK_METHOD1(updatedPropertiesChanged, void (bb::cascades::WindowProperty::Types newUpdatedProperties));
    MOCK_METHOD1(keyInputForwardingEnabledChanged, void (bool keyInputForwardingEnabled));
    MOCK_METHOD1(controlFrameChanged, void (const QRectF & frame));
    typedef ForeignWindowControl ThisClass;
    typedef Control BaseClass;
public:
    template <typename BuilderType, typename BuiltType>
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
    {
    protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
    public:
        BuilderType& windowId(const QString& windowId) {
            this->instance().setWindowId(windowId);
            return this->builder();
        }
        BuilderType& windowGroup(const QString& windowGroup) {
            this->instance().setWindowGroup(windowGroup);
            return this->builder();
        }
        BuilderType& windowHandle(screen_window_t handle) {
            this->instance().setWindowHandle(handle);
            return this->builder();
        }
        BuilderType& updatedProperties(bb::cascades::WindowProperty::Types updatedProperties) {
            this->instance().setUpdatedProperties(updatedProperties);
            return this->builder();
        }
        BuilderType& keyInputForwardingEnabled(bool keyInputForwardingEnabled) {
            this->instance().setKeyInputForwardingEnabled(keyInputForwardingEnabled);
            return this->builder();
        }
    };
    class Builder : public TBuilder<Builder, ForeignWindowControl>
    {
     public:
        Builder() : TBuilder<Builder, ForeignWindowControl>(new ForeignWindowControl()) {}
     };
  static Builder create()
    {
        return Builder();
    }
};
}
}
#endif
