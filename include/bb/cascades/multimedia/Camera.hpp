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
#ifndef BB_CASCADES_MULTIMEDIA_CAMERA_HPP
#define BB_CASCADES_MULTIMEDIA_CAMERA_HPP
#include "gtest/gtest.h"
#include <bb/cascades/CustomControl>
#include <bb/cascades/Container>
#include <bb/cascades/multimedia/CameraUnit>
#include <bb/Global>
#include <QtDeclarative>
#include <QObject>
namespace bb
{
namespace cascades
{
namespace multimedia
{
class CameraPrivate;
class CameraSettings;
typedef QSharedPointer<unsigned char> SharedUCharPointer;
class QT_CASCADES_EXPORT BB_DLL_PUBLIC Camera : public CustomControl
{
public:
    Camera(Container *parent = 0);
    virtual ~Camera();
    MOCK_CONST_METHOD0(cameraUnit, bb::cascades::multimedia::CameraUnit::Type ());
    MOCK_CONST_METHOD1(isCameraAccessible, bool (bb::cascades::multimedia::CameraUnit::Type unit = bb::cascades::multimedia::CameraUnit::Rear));
    MOCK_CONST_METHOD0(allCamerasAccessible, bool ());
    MOCK_METHOD1(open, void (bb::cascades::multimedia::CameraUnit::Type unit = bb::cascades::multimedia::CameraUnit::Rear));
    MOCK_METHOD0(close, void ());
    MOCK_METHOD0(startViewfinder, void ());
    MOCK_METHOD0(stopViewfinder, void ());
    MOCK_METHOD0(capturePhoto, void ());
    MOCK_METHOD0(startVideoCapture, void ());
    MOCK_METHOD0(stopVideoCapture, void ());
    MOCK_CONST_METHOD1(getSettings, void (CameraSettings *settings));
    MOCK_METHOD1(applySettings, bool (CameraSettings *settings));
    MOCK_CONST_METHOD0(maxZoomLevel, unsigned int ());
    MOCK_CONST_METHOD1(supportedCaptureResolutions, QVariantList (bb::cascades::multimedia::CameraMode::Type mode));
    MOCK_CONST_METHOD0(supportedCameras, QList<bb::cascades::multimedia::CameraUnit::Type> ());
    MOCK_METHOD0(previewBufferSize, quint64 ());
    MOCK_METHOD2(addPreviewBuffer, void (const QSharedPointer<unsigned char> &previewBuffer, quint64 previewBufferSize));
	MOCK_METHOD1(cameraUnitChanged, void (bb::cascades::multimedia::CameraUnit::Type unit));
	MOCK_METHOD0(cameraOpened, void ());
	MOCK_METHOD1(cameraOpenFailed, void (bb::cascades::multimedia::CameraError::Type error));
	MOCK_METHOD0(cameraClosed, void ());
	MOCK_METHOD1(cameraCloseFailed, void (bb::cascades::multimedia::CameraError::Type error));
    MOCK_METHOD0(viewfinderStarted, void ());
    MOCK_METHOD1(viewfinderStartFailed, void (bb::cascades::multimedia::CameraError::Type error));
    MOCK_METHOD0(viewfinderStopped, void ());
    MOCK_METHOD1(viewfinderStopFailed, void (bb::cascades::multimedia::CameraError::Type error));
    MOCK_METHOD0(shutterFired, void ());
    MOCK_METHOD0(photoCaptured, void ());
    MOCK_METHOD1(photoCaptureFailed, void (bb::cascades::multimedia::CameraError::Type error));
    MOCK_METHOD2(photoSaved, void (const QString &fileName, quint64 length));
    MOCK_METHOD1(photoSaveFailed, void (bb::cascades::multimedia::CameraError::Type error));
    MOCK_METHOD5(previewFrameAvailable, void (bb::cascades::multimedia::SharedUCharPointer previewBuffer, quint64 size,
                                unsigned int width, unsigned int height, unsigned int stride));
    MOCK_METHOD2(reviewImageReady, void (const QSize &imgSize, const QByteArray &imgData));
    MOCK_METHOD0(videoCaptureStarted, void ());
    MOCK_METHOD1(videoCaptureFailed, void (bb::cascades::multimedia::CameraError::Type error));
    MOCK_METHOD1(videoCaptureStopped, void (const QString &fileName));
    MOCK_METHOD0(cameraResourceReleased, void ());
    MOCK_METHOD1(focusStateChanged, void (bb::cascades::multimedia::CameraFocusState::Type state));
};
} 
} 
} 
#endif 
