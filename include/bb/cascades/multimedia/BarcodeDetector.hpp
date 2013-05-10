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
#ifndef BB_CASCADES_MULTIMEDIA_BARCODEDETECTOR_HPP
#define BB_CASCADES_MULTIMEDIA_BARCODEDETECTOR_HPP
#include "gtest/gtest.h"
#include <bb/cascades/multimedia/BarcodeFormat>
#include <bb/cascades/multimedia/Camera>
#include <bb/Global>
#include <QObject>
#include <QtDeclarative>
namespace bb
{
namespace cascades
{
namespace multimedia
{
class BarcodeDetectorPrivate;
class QT_CASCADES_EXPORT BB_DLL_PUBLIC BarcodeDetector : public QObject
{
public:
    BarcodeDetector(QObject *parent = 0);
    virtual ~BarcodeDetector();
    MOCK_CONST_METHOD0(camera, bb::cascades::multimedia::Camera *());
    MOCK_METHOD1(setCamera, void (bb::cascades::multimedia::Camera *camera));
    MOCK_CONST_METHOD0(formats, bb::cascades::multimedia::BarcodeFormat::Types ());
    MOCK_METHOD1(setFormats, void (bb::cascades::multimedia::BarcodeFormat::Types formats));
    MOCK_METHOD2(barcodeDetected, void (const QString &data, BarcodeFormat::Type format));
    MOCK_METHOD1(cameraChanged, void (bb::cascades::multimedia::Camera *camera));
    MOCK_METHOD1(formatsChanged, void (bb::cascades::multimedia::BarcodeFormat::Types newFormats));
};
} 
} 
} 
#endif 
