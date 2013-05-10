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
#ifndef cascades_applicationmock_h
#define cascades_applicationmock_h
#include "gmock/gmock.h"
#include "bbcascades_global.h"
#include <bb/Application>

namespace bb {
  namespace cascades {
    class ApplicationPrivate;
    class AbstractPane;
    class AbstractCover;
    class Menu;
    class Window;
    class ThemeSupport;
    class ApplicationMock : public bb::ApplicationMock {
public:
    	ApplicationMock(){}
        virtual ~ApplicationMock(){}

        MOCK_METHOD2(notify, bool (QObject *receiver, QEvent *event));
        MOCK_METHOD1(setScene, void (bb::cascades::AbstractPane* scene));
        MOCK_METHOD1(setCover, void (bb::cascades::AbstractCover* cover));
        MOCK_CONST_METHOD0(scene, bb::cascades::AbstractPane *());
        MOCK_CONST_METHOD0(cover, bb::cascades::AbstractCover *());
        MOCK_METHOD0(resetScene, void ());
        MOCK_METHOD0(resetCover, void ());
        MOCK_METHOD1(setMenu, void (bb::cascades::Menu* menu));
        MOCK_CONST_METHOD0(menu, bb::cascades::Menu* ());
        MOCK_METHOD0(resetMenu, void ());
        MOCK_METHOD1(setMenuEnabled, void (bool enabled));
        MOCK_CONST_METHOD0(isMenuEnabled, bool ());
        MOCK_METHOD0(resetMenuEnabled, void ());
        MOCK_CONST_METHOD0(mainWindow, bb::cascades::Window * ());
        MOCK_CONST_METHOD0(themeSupport, bb::cascades::ThemeSupport* ());
        MOCK_METHOD1(menuChanged, void (bb::cascades::Menu *menu));
        MOCK_METHOD1(sceneChanged, void (bb::cascades::AbstractPane *scene));
        MOCK_METHOD1(coverChanged, void (bb::cascades::AbstractCover *cover));
        MOCK_METHOD1(menuEnabledChanged, void (bool menuEnabledChanged));
    };
  } 
}
#endif 
