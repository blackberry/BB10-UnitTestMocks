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
#ifndef cascades_websettings_h
#define cascades_websettings_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/color.h>
#include <QtCore/QObject>
#include <QtDeclarative/QtDeclarative>
namespace bb {
  namespace cascades {
    class WebSettingsPrivate;
    class WebSettings : public QObject
    {
public:
        MOCK_CONST_METHOD0(defaultFontSize, int ());
        MOCK_METHOD1(setDefaultFontSize, void (int size));
        MOCK_METHOD0(resetDefaultFontSize, void ());
        MOCK_CONST_METHOD0(isJavaScriptEnabled, bool ());
        MOCK_METHOD1(setJavaScriptEnabled, void (bool enabled));
        MOCK_METHOD0(resetJavaScriptEnabled, void ());
        MOCK_CONST_METHOD0(isImageDownloadingEnabled, bool ());
        MOCK_METHOD1(setImageDownloadingEnabled, void (bool enabled));
        MOCK_METHOD0(resetImageDownloadingEnabled, void ());
        MOCK_CONST_METHOD0(minimumFontSize, int ());
        MOCK_METHOD1(setMinimumFontSize, void (int size));
        MOCK_METHOD0(resetMinimumFontSize, void ());
        MOCK_CONST_METHOD0(userAgent, QString ());
        MOCK_METHOD1(setUserAgent, void (const QString& userAgent));
        MOCK_CONST_METHOD0(userStyleSheetLocation, QUrl ());
        MOCK_METHOD1(setUserStyleSheetLocation, void (const QUrl& location));
        MOCK_METHOD0(resetUserStyleSheetLocation, void ());
        MOCK_CONST_METHOD0(isWebInspectorEnabled, bool ());
        MOCK_METHOD1(setWebInspectorEnabled, void (bool enabled));
        MOCK_METHOD0(resetWebInspectorEnabled, void ());
        MOCK_CONST_METHOD0(isZoomToFitEnabled, bool ());
        MOCK_METHOD1(setZoomToFitEnabled, void (bool enabled));
        MOCK_METHOD0(resetZoomToFitEnabled, void ());
        MOCK_CONST_METHOD0(isActiveTextEnabled, bool ());
        MOCK_METHOD1(setActiveTextEnabled, void (bool enabled));
        MOCK_METHOD0(resetActiveTextEnabled, void ());
        MOCK_CONST_METHOD0(viewportArguments, QVariantMap ());
        MOCK_METHOD1(setViewportArguments, void (const QVariantMap& arguments));
        MOCK_METHOD0(resetViewportArguments, void ());
        MOCK_CONST_METHOD0(background, QVariant ());
        MOCK_METHOD1(setBackground, void (const bb::cascades::Paint& paint));
        MOCK_METHOD0(resetBackground, void ());
        MOCK_CONST_METHOD0(isBinaryFontDownloadingEnabled, bool ());
        MOCK_METHOD1(setBinaryFontDownloadingEnabled, void (bool enabled));
        MOCK_METHOD0(resetBinaryFontDownloadingEnabled, void ());
        WebSettings(WebSettingsPrivate &dd);
        ~WebSettings();
    };
}
}
#endif	
