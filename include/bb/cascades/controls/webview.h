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
#ifndef cascades_webview_h
#define cascades_webview_h
#include "gmock/gmock.h"
#include <QUrl>
#include <QVariantMap>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/web/javascriptworld.h>
#include <bb/cascades/web/webfindflag.h>
namespace bb {
    namespace cascades {
    class ActionSet;
    class WebResourceRequestFilter;
    class WebViewPrivate;
    class WebSettings;
    class Container;
    class WebNavigationRequest;
    class WebLoadRequest;
    class WebStorage;
    class WebView : public Control
    {
public:
        WebView(Container *parent = 0);
        WebView(WebView *parent);
        virtual ~WebView();
        MOCK_CONST_METHOD0(settings, bb::cascades::WebSettings *());
        MOCK_CONST_METHOD0(storage, bb::cascades::WebStorage *());
        MOCK_METHOD3(loadData, void (const QByteArray& data, const QString& mimeType = QString(), const QUrl& baseUrl = QUrl()));
        MOCK_CONST_METHOD0(canGoBack, bool ());
        MOCK_CONST_METHOD0(canGoForward, bool ());
        MOCK_CONST_METHOD0(loading, bool ());
        MOCK_CONST_METHOD0(loadProgress, int ());
        MOCK_METHOD2(evaluateJavaScript, int (const QString& script, bb::cascades::JavaScriptWorld::Type world = bb::cascades::JavaScriptWorld::Normal));
        MOCK_CONST_METHOD0(title, QString ());
        MOCK_CONST_METHOD0(url, QUrl ());
        MOCK_METHOD1(setUrl, void (const QUrl& url));
        MOCK_CONST_METHOD0(icon, QUrl ());
        MOCK_CONST_METHOD0(html, QString ());
        MOCK_METHOD2(setHtml, void (const QString& html, const QUrl& baseUrl = QUrl()));
        MOCK_METHOD1(setResourceRequestFilter, void (WebResourceRequestFilter* filter));
        MOCK_METHOD2(findText, void (const QString& subString, WebFindFlag::Types options = 0));
        MOCK_CONST_METHOD0(minContentScale, float ());
        MOCK_CONST_METHOD0(maxContentScale, float ());
        MOCK_METHOD1(loadingChanged, void (bb::cascades::WebLoadRequest* loadRequest));
        MOCK_METHOD1(loadProgressChanged, void (int loadProgress));
        MOCK_METHOD1(titleChanged, void (const QString& title));
        MOCK_METHOD0(navigationHistoryChanged, void ());
        MOCK_METHOD1(urlChanged, void (const QUrl& url));
        MOCK_METHOD1(iconChanged, void (const QUrl& icon));
        MOCK_METHOD1(navigationRequested, void (bb::cascades::WebNavigationRequest* request));
        MOCK_METHOD2(javaScriptResult, void (int resultId, const QVariant& result));
        MOCK_METHOD0(javaScriptInterrupted, void ());
        MOCK_METHOD1(messageReceived, void (const QVariantMap& message));
        MOCK_METHOD0(microFocusChanged, void ());
        MOCK_METHOD1(minContentScaleChanged, void (float minContentScale));
        MOCK_METHOD1(maxContentScaleChanged, void (float maxContentScale));
public:
        MOCK_METHOD2(loadHtml, void (const QString& html, const QUrl& baseUrl = QUrl()));
        MOCK_METHOD0(goBack, void ());
        MOCK_METHOD0(goForward, void ());
        MOCK_METHOD0(stop, void ());
        MOCK_METHOD0(reload, void ());
        MOCK_METHOD1(postMessage, void (const QString& message));
public:
        typedef WebView ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        };
        class Builder : public TBuilder<Builder, WebView>
        {
        public:
            Builder() : TBuilder<Builder, WebView>(new WebView())
            {
            }
            Builder(WebView *webView) : TBuilder<Builder, WebView>(new WebView(webView))
            {
            }
        };
      static Builder create()
        {
            return Builder();
        }
      static Builder create(WebView *webView)
        {
            return Builder(webView);
        }
    };
}
}
#endif	
