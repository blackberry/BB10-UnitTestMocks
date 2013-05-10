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

#ifndef cascades_systemdefaults_h
#define cascades_systemdefaults_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/textstyle.h>
namespace bb {
namespace cascades {
    class ColorPaint;
    class Paint;
class SystemDefaults
{
public:
    class Paints
    {
public:
        MOCK_METHOD0(defaultText, const ColorPaint & ());
        MOCK_METHOD0(containerBackground, const Paint & ());
    };

    class TextStyles
    {
    public:
        MOCK_METHOD0(bigText, TextStyle ());
        MOCK_METHOD0(bodyText, TextStyle ());
        MOCK_METHOD0(titleText, TextStyle ());
        MOCK_METHOD0(subtitleText, TextStyle ());
        MOCK_METHOD0(smallText, TextStyle ());
    };
};
}
}
#endif
