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
#ifndef BB_CASCADES_MULTIMEDIA_CAMERASETTINGS_HPP
#define BB_CASCADES_MULTIMEDIA_CAMERASETTINGS_HPP
#include "gtest/gtest.h"
#include <bb/cascades/multimedia/CameraMode>
#include <bb/Global>
#include <QObject>
#include <QPoint>
#include <QRect>
#include <QSize>
#include <QtDeclarative>
namespace bb
{
namespace cascades
{
namespace multimedia
{
class CameraSettingsPrivate;
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraSettings : public QObject
{
public:
    CameraSettings(QObject *parent=0);
    virtual ~CameraSettings();
    MOCK_CONST_METHOD0(cameraMode, bb::cascades::multimedia::CameraMode::Type ());
     MOCK_METHOD1(setCameraMode, void (bb::cascades::multimedia::CameraMode::Type mode));
     MOCK_CONST_METHOD0(shootingMode, bb::cascades::multimedia::CameraShootingMode::Type ());
    MOCK_METHOD1(setShootingMode, void (bb::cascades::multimedia::CameraShootingMode::Type mode));
    MOCK_CONST_METHOD0(sceneMode, bb::cascades::multimedia::CameraSceneMode::Type ());
    MOCK_METHOD1(setSceneMode, void (bb::cascades::multimedia::CameraSceneMode::Type mode));
    MOCK_CONST_METHOD0(flashMode, bb::cascades::multimedia::CameraFlashMode::Type ());
    MOCK_METHOD1(setFlashMode, void (bb::cascades::multimedia::CameraFlashMode::Type mode));
    MOCK_CONST_METHOD0(focusMode, bb::cascades::multimedia::CameraFocusMode::Type ());
    MOCK_METHOD1(setFocusMode, void (bb::cascades::multimedia::CameraFocusMode::Type mode));
    MOCK_CONST_METHOD0(captureResolution, QSize ());
    MOCK_METHOD1(setCaptureResolution, void (const QSize &resolution));
    MOCK_CONST_METHOD0(zoomLevel, unsigned int ());
    MOCK_METHOD1(setZoomLevel, void (unsigned int level));
    MOCK_METHOD1(setFocusRegion, void (const QRect &focusRegion));
    MOCK_CONST_METHOD0(focusRegion, QRect ());
    MOCK_METHOD1(setCameraRollPath, void (const QString &path));
    MOCK_CONST_METHOD0(cameraRollPath, QString ());
	MOCK_METHOD1(cameraModeChanged, void (bb::cascades::multimedia::CameraMode::Type mode));
	MOCK_METHOD1(shootingModeChanged, void (bb::cascades::multimedia::CameraShootingMode::Type mode));
	MOCK_METHOD1(sceneModeChanged, void (bb::cascades::multimedia::CameraSceneMode::Type mode));
	MOCK_METHOD1(flashModeChanged, void (bb::cascades::multimedia::CameraFlashMode::Type mode));
	MOCK_METHOD1(focusModeChanged, void (bb::cascades::multimedia::CameraFocusMode::Type mode));
	MOCK_METHOD1(focusRegionChanged, void (const QRect &focusRegion));
	MOCK_METHOD1(captureResolutionChanged, void (const QSize &resolution));
	MOCK_METHOD1(zoomLevelChanged, void (unsigned int level));
	MOCK_METHOD1(cameraRollPathChanged, void (const QString &path));
};
} 
} 
} 
#endif 
