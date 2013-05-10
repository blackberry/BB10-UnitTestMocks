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
#ifndef cascades_orientationsupport_h
#define cascades_orientationsupport_h
#include "gmock/gmock.h"
#include <QtCore/QObject>
#include <QtDeclarative>
#include <QtCore/QScopedPointer>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiorientation.h>
#include <bb/cascades/core/supporteddisplayorientation.h>
#include <bb/cascades/core/displaydirection.h>
namespace bb {
    namespace cascades {
    class OrientationSupportPrivate;
    class OrientationSupport : public QObject
    {
public:
    MOCK_METHOD0(instance, bb::cascades::OrientationSupport *());
    MOCK_CONST_METHOD0(supportedDisplayOrientation, bb::cascades::SupportedDisplayOrientation::Type ());
    MOCK_METHOD1(setSupportedDisplayOrientation, void (bb::cascades::SupportedDisplayOrientation::Type displayOrientation));
    MOCK_METHOD0(resetSupportedDisplayOrientation, void ());
    MOCK_CONST_METHOD0(orientation, bb::cascades::UIOrientation::Type ());
    MOCK_CONST_METHOD0(displayDirection, bb::cascades::DisplayDirection::Type ());
    virtual ~OrientationSupport();
    };
}
}
#endif 
