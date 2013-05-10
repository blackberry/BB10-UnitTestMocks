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
#ifndef cascades_window_h
#define cascades_window_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QObject>
#include <QString>
#include <QVariant>
#include <QtDeclarative/QtDeclarative>
#include <bb/cascades/BaseObject>
#include <bb/cascades/WindowState>
#include <bb/cascades/ScreenIdleMode>
#include <screen/screen.h>
namespace bb {
    namespace cascades {
    class WindowPrivate;
    class Window : public BaseObject
    {
public:
        virtual ~Window();
        MOCK_CONST_METHOD0(handle, screen_window_t ());
        MOCK_CONST_METHOD0(groupId, QString ());
        MOCK_CONST_METHOD0(state, bb::cascades::WindowState::Type ());
        MOCK_CONST_METHOD0(screenIdleMode, bb::cascades::ScreenIdleMode::Type ());
public:
        MOCK_METHOD1(setScreenIdleMode, void ( bb::cascades::ScreenIdleMode::Type newScreenIdleMode ));
        MOCK_METHOD0(posted, void ());
        MOCK_METHOD1(stateChanged, void (bb::cascades::WindowState::Type newState));
        MOCK_METHOD1(screenIdleModeChanged, void (bb::cascades::ScreenIdleMode::Type newScreenIdleMode ));
    };
}
}
#endif
