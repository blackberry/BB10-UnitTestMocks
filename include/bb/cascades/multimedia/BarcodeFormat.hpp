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
#ifndef BB_CASCADES_MULTIMEDIA_BARCODEFORMAT_HPP
#define BB_CASCADES_MULTIMEDIA_BARCODEFORMAT_HPP
#include "gtest/gtest.h"
#include <bb/Global>
#include <QObject>
namespace bb
{
namespace cascades
{
namespace multimedia
{
class QT_CASCADES_EXPORT BB_DLL_PUBLIC BarcodeFormat
{
public:
    enum Type
    {
        QrCode     = 0x1,   
        DataMatrix = 0x2,   
        UpcE       = 0x4,   
        UpcA       = 0x8,   
        Ean8       = 0x10,  
        Ean13      = 0x20,  
        Code128    = 0x40,  
        Code39     = 0x80,  
        Itf        = 0x100, 
        Aztec      = 0x200, 
        Any        = 0xffff 
    };
};
} 
} 
} 
#endif 
