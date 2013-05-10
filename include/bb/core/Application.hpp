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
#ifndef BB_CORE_APPLICATION_HPP
#define BB_CORE_APPLICATION_HPP
#include <bb/IconBadge>
#include <QtCore/QCoreApplication>
#include "gmock/gmock.h"
#include <bb/core/applicationmock.h>
#include <bb/testing/proxybase.h>

namespace bb {
class ApplicationPrivate;
class Event;
class Application : public QObject, public bb::testing::ProxyBase<bb::ApplicationMock>
{
    Q_OBJECT
public:
    Application(int &argc, char **argv) {Q_UNUSED(argc); Q_UNUSED(argv);}
    virtual ~Application(){}

    bool setClosePrompt(const QString &title, const QString &message){return mock()->setClosePrompt(title, message);}
    bool clearClosePrompt(){return mock()->clearClosePrompt();}
    void setAutoExit(bool autoExit){mock()->setAutoExit(autoExit);}
    bool autoExit(){return mock()->autoExit();}
    bool extendTerminationTimeout(){return mock()->extendTerminationTimeout();}
    bool setIconBadge(bb::IconBadge::Type badge){return mock()->setIconBadge(badge);}
    void thumbnail(){mock()->thumbnail();}
    void fullscreen(){mock()->fullscreen();}
    void invisible(){mock()->invisible();}
    void swipeDown(){mock()->swipeDown();}
    void asleep(){mock()->asleep();}
    void awake(){mock()->awake();}
    void manualExit(){mock()->manualExit();}
    void autoExitChanged(bool newAutoExit){mock()->autoExitChanged(newAutoExit);}

    bool filterEvent(void *message, long *result) {return mock()->filterEvent(message, result);};
    virtual bool notify(QObject *receiver, QEvent *event) {return mock()->notify(receiver, event);};
    QCoreApplication::EventFilter setEventFilter(QCoreApplication::EventFilter filter) {return mock()->setEventFilter(filter);};

    static int exec() { return staticMock()->exec(); }
    static void installTranslator(QTranslator * messageFile) { staticMock()->installTranslator(messageFile); }
    static void removeTranslator(QTranslator * messageFile) { staticMock()->removeTranslator(messageFile); }

public Q_SLOTS:
    void quit() {return mock()->quit();};

Q_SIGNALS:
    void aboutToQuit();

};
} // namespace bb
#endif // BB_CORE_APPLICATION_HPP
