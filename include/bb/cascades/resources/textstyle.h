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
#ifndef cascades_textstyle_h
#define cascades_textstyle_h
#include "gmock/gmock.h"
#include <QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/resource.h>
#include <bb/cascades/resources/fontstyle.h>
#include <bb/cascades/resources/fontweight.h>
#include <bb/cascades/resources/fontsize.h>
#include <bb/cascades/resources/textalign.h>
#include <bb/cascades/resources/colorpaint.h>
namespace bb {
    namespace cascades {
class TextStylePrivate;
class TextStyle : public Resource { 
public:
    TextStyle() { }
    virtual ~TextStyle() { }
    TextStyle(const TextStyle &other) { }
    TextStyle& operator=(const TextStyle &other);
    MOCK_METHOD1(setFontFamily, void (const QString &fontFamily));
    MOCK_CONST_METHOD0(fontFamily, QString ());
    MOCK_METHOD0(resetFontFamily, void ());
    MOCK_METHOD1(setFontStyle, void (FontStyle::Type fontStyle));
    MOCK_CONST_METHOD0(fontStyle, FontStyle::Type ());
    MOCK_METHOD0(resetFontStyle, void ());
    MOCK_METHOD1(setFontWeight, void (bb::cascades::FontWeight::Type fontWeight));
    MOCK_CONST_METHOD0(fontWeight, bb::cascades::FontWeight::Type ());
    MOCK_METHOD0(resetFontWeight, void ());
    MOCK_METHOD1(setColor, void (const bb::cascades::ColorPaint& color));
    MOCK_METHOD1(setColor, void (const QVariant& color));
    MOCK_CONST_METHOD0(color, QVariant ());
    MOCK_METHOD0(resetColor, void ());
    MOCK_METHOD1(setLineHeight, void (float lineHeight));
    MOCK_CONST_METHOD0(lineHeight, float ());
    MOCK_METHOD0(resetLineHeight, void ());
    MOCK_METHOD1(setFontSizeValue, void (float size));
    MOCK_CONST_METHOD0(fontSizeValue, float ());
    MOCK_METHOD0(resetFontSizeValue, void ());
    MOCK_METHOD1(setFontSize, void (FontSize::Type size));
    MOCK_CONST_METHOD0(fontSize, FontSize::Type ());
    MOCK_METHOD0(resetFontSize, void ());
    MOCK_METHOD1(setTextAlign, void (bb::cascades::TextAlign::Type alignment));
    MOCK_CONST_METHOD0(textAlign, bb::cascades::TextAlign::Type ());
    MOCK_METHOD0(resetTextAlign, void ());
};
}
}
#endif 
