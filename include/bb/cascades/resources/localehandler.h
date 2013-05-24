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
#ifndef cascades_localehandler_h
#define cascades_localehandler_h
#include "gmock/gmock.h"
#include <QtDeclarative/QtDeclarative>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/BaseObject>
namespace bb {
namespace cascades {
class LocaleHandlerPrivate;
class LocaleHandlerMock: public BaseObjectMock {
public:
	MOCK_METHOD1(ctor, void(QObject *parent));
	virtual ~LocaleHandlerMock() {}
	MOCK_METHOD0(localeOrLanguageChanged, void ());
	MOCK_METHOD0(localeChanged, void ());
	MOCK_METHOD0(languageChanged, void ());
	MOCK_METHOD0(systemLanguageChanged, void ());
};

class LocaleHandler: public BaseObject {
public:
	LocaleHandler(QObject *parent = 0) { mock<LocaleHandlerMock>()->ctor(parent); }
	virtual ~LocaleHandler() { }
	void localeOrLanguageChanged() { mock<LocaleHandlerMock>()->localeOrLanguageChanged(); }
	void localeChanged() { mock<LocaleHandlerMock>()->localeChanged(); }
	void languageChanged() { mock<LocaleHandlerMock>()->languageChanged(); }
	void systemLanguageChanged() { mock<LocaleHandlerMock>()->systemLanguageChanged(); }
};

}
}
#endif 
