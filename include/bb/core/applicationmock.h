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
#ifndef BB_CORE_APPLICATIONMOCK_HPP
#define BB_CORE_APPLICATIONMOCK_HPP
#include <bb/IconBadge>
#include <QtCore/QCoreApplication>
#include "gmock/gmock.h"
namespace bb {
class ApplicationPrivate;
class Event;
class ApplicationMock
{
public:
    ApplicationMock(){}
    virtual ~ApplicationMock(){}

    MOCK_METHOD2(setClosePrompt, bool(const QString &title, const QString &message));
    MOCK_METHOD0(clearClosePrompt, bool());
    MOCK_METHOD1(setAutoExit, void(bool autoExit));
    MOCK_CONST_METHOD0(autoExit, bool());
    MOCK_METHOD0(extendTerminationTimeout, bool());
    MOCK_METHOD1(setIconBadge, bool(bb::IconBadge::Type badge));
    MOCK_METHOD0(thumbnail, void());
    MOCK_METHOD0(fullscreen, void());
    MOCK_METHOD0(invisible, void());
    MOCK_METHOD0(swipeDown, void());
    MOCK_METHOD0(asleep, void());
    MOCK_METHOD0(awake, void());
    MOCK_METHOD0(manualExit, void());
    MOCK_METHOD1(autoExitChanged, void(bool newAutoExit));

    MOCK_METHOD2(filterEvent, bool(void *message, long *result));
    MOCK_METHOD2(notify, bool(QObject *receiver, QEvent *event));
    MOCK_METHOD1(setEventFilter, QCoreApplication::EventFilter(QCoreApplication::EventFilter filter));

    MOCK_METHOD0(quit, void());

    // "static" methods
    MOCK_METHOD0(exec, int());
	MOCK_METHOD1(installTranslator, void(QTranslator *));
	MOCK_METHOD1(removeTranslator, void(QTranslator *));
};
} // namespace bb
#endif // BB_CORE_APPLICATION_HPP
