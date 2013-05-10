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
#ifndef cascades_textstyledefinition_h
#define cascades_textstyledefinition_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtDeclarative/QtDeclarative>
#include <QString>
#include <bb/cascades/resources/colorpaint.h>
#include <bb/cascades/resources/textstyle.h>
#include <bb/cascades/BaseObject>
namespace bb {
namespace cascades {
class TextStyleDefinitionPrivate;
class TextStyleDefinition : public BaseObject {
public:
    MOCK_METHOD0(styleChanged, void ());
    MOCK_METHOD1(baseChanged, void (const bb::cascades::TextStyle &textStyle));
    MOCK_METHOD1(fontFamilyChanged, void (const QString &fontFamily));
    MOCK_METHOD1(fontStyleChanged, void (bb::cascades::FontStyle::Type newFontStyle));
    MOCK_METHOD1(fontWeightChanged, void (bb::cascades::FontWeight::Type newFontWeight));
    MOCK_METHOD1(colorChanged, void (const bb::cascades::ColorPaint &color));
    MOCK_METHOD1(colorChanged, void (const QVariant &color));
    MOCK_METHOD1(lineHeightChanged, void (float lineHeight));
    MOCK_METHOD1(fontSizeValueChanged, void (float fontSizeValue));
    MOCK_METHOD1(fontSizeChanged, void (bb::cascades::FontSize::Type newFontSize));
    MOCK_METHOD1(textAlignChanged, void (bb::cascades::TextAlign::Type newAlignment));

    TextStyleDefinition() { }
    virtual ~TextStyleDefinition() { }

     MOCK_METHOD0(base, bb::cascades::TextStyle ());
    MOCK_METHOD0(style, bb::cascades::TextStyle ());
    MOCK_METHOD1(setBase, void (const bb::cascades::TextStyle &base));
    MOCK_METHOD0(resetBase, void ());
    MOCK_METHOD1(setFontFamily, void (const QString &fontFamily));
    MOCK_CONST_METHOD0(fontFamily, QString ());
    MOCK_METHOD0(resetFontFamily, void ());
    MOCK_METHOD1(setFontStyle, void (bb::cascades::FontStyle::Type fontStyle));
    MOCK_CONST_METHOD0(fontStyle, bb::cascades::FontStyle::Type ());
    MOCK_METHOD0(resetFontStyle, void ());
    MOCK_METHOD1(setFontWeight, void (bb::cascades::FontWeight::Type fontWeight));
    MOCK_CONST_METHOD0(fontWeight, bb::cascades::FontWeight::Type ());
    MOCK_METHOD0(resetFontWeight, void ());
    MOCK_METHOD1(setColor, void (const bb::cascades::ColorPaint &color));
    MOCK_METHOD1(setColor, void (const QVariant &color));
    MOCK_METHOD0(color, QVariant ());
    MOCK_METHOD0(resetColor, void ());
    MOCK_METHOD1(setLineHeight, void (float lineHeight));
    MOCK_CONST_METHOD0(lineHeight, float  ());
     MOCK_METHOD0(resetLineHeight, void ());
    MOCK_METHOD1(setFontSizeValue, void (float size));
    MOCK_CONST_METHOD0(fontSizeValue, float ());
    MOCK_METHOD0(resetFontSizeValue, void ());
    MOCK_METHOD1(setFontSize, void (bb::cascades::FontSize::Type size));
    MOCK_CONST_METHOD0(fontSize, bb::cascades::FontSize::Type ());
    MOCK_METHOD0(resetFontSize, void ());
    MOCK_METHOD1(setTextAlign, void (bb::cascades::TextAlign::Type alignment));
    MOCK_METHOD0(textAlign, bb::cascades::TextAlign::Type ());
    MOCK_METHOD0(resetTextAlign, void ());
};
}
}
#endif 
