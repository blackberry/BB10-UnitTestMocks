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
#ifndef cascades_application_h
#define cascades_application_h
#include "gmock/gmock.h"
#include "bbcascades_global.h"
#include <bb/Application>
#include <bb/cascades/applicationmock.h>

namespace bb {
  namespace cascades {
    class ApplicationPrivate;
    class AbstractPane;
    class AbstractCover;
    class Menu;
    class Window;
    class ThemeSupport;
    class Application : public bb::Application {
public:
        Application(int argc, char **argv) : bb::Application(argc, argv){}
        virtual ~Application(){}

        bool notify(QObject* receiver, QEvent* event){return mock<bb::cascades::ApplicationMock>()->notify(receiver, event);}
        void setScene(bb::cascades::AbstractPane* scene){mock<bb::cascades::ApplicationMock>()->setScene(scene);}
        void setCover(bb::cascades::AbstractCover* cover){mock<bb::cascades::ApplicationMock>()->setCover(cover);}
        bb::cascades::AbstractPane* scene(){return mock<bb::cascades::ApplicationMock>()->scene();}
        bb::cascades::AbstractCover* cover(){return mock<bb::cascades::ApplicationMock>()->cover();}
        void resetScene(){mock<bb::cascades::ApplicationMock>()->resetScene();}
        void resetCover(){mock<bb::cascades::ApplicationMock>()->resetCover();}
        void setMenu(bb::cascades::Menu* menu){mock<bb::cascades::ApplicationMock>()->setMenu(menu);}
        bb::cascades::Menu* menu(){return mock<bb::cascades::ApplicationMock>()->menu();}
        void resetMenu(){mock<bb::cascades::ApplicationMock>()->resetMenu();}
        void setMenuEnabled(bool enabled){mock<bb::cascades::ApplicationMock>()->setMenuEnabled(enabled);}
        bool isMenuEnabled(){return mock<bb::cascades::ApplicationMock>()->isMenuEnabled();}
        void resetMenuEnabled(){mock<bb::cascades::ApplicationMock>()->resetMenuEnabled();}
        bb::cascades::Window* mainWindow(){return mock<bb::cascades::ApplicationMock>()->mainWindow();}
        bb::cascades::ThemeSupport* themeSupport(){return mock<bb::cascades::ApplicationMock>()->themeSupport();}
        void menuChanged(bb::cascades::Menu* menu){mock<bb::cascades::ApplicationMock>()->menuChanged(menu);}
        void sceneChanged(bb::cascades::AbstractPane* scene){mock<bb::cascades::ApplicationMock>()->sceneChanged(scene);}
        void coverChanged(bb::cascades::AbstractCover* cover){mock<bb::cascades::ApplicationMock>()->coverChanged(cover);}
        void menuEnabledChagned(bool menuEnabledChanged){mock<bb::cascades::ApplicationMock>()->menuEnabledChanged(menuEnabledChanged);}
    };
  } 
}
#endif 
