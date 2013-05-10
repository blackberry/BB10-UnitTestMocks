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
#ifndef BB_CASCADES_MULTIMEDIA_QRCODEVIEW_HPP
#define BB_CASCADES_MULTIMEDIA_QRCODEVIEW_HPP
#include "gtest/gtest.h"
#include <bb/cascades/multimedia/QrCodeErrorCorrection>
#include <bb/cascades/CustomControl>
#include <bb/Global>
namespace bb
{
namespace cascades
{
namespace multimedia
{
class QrCodeViewPrivate;
class QT_CASCADES_EXPORT BB_DLL_PUBLIC QrCodeView : public CustomControl
{
public:
    QrCodeView(Container *parent = 0);
    virtual ~QrCodeView();
    MOCK_CONST_METHOD0(data, QString ());
    MOCK_METHOD1(setData, void (const QString &data));
    MOCK_CONST_METHOD0(errorCorrection, QrCodeErrorCorrection::Type ());
    MOCK_METHOD1(setErrorCorrection, void (QrCodeErrorCorrection::Type errorCorrection));
    MOCK_METHOD1(dataChanged, void (const QString &data));
    MOCK_METHOD1(errorCorrectionChanged, void (bb::cascades::multimedia::QrCodeErrorCorrection::Type errorCorrection));
};
} 
} 
} 
#endif 
