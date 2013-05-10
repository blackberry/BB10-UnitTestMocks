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
#ifndef BB_CASCADES_TEXTCONTENTPROPERTIES_H
#define BB_CASCADES_TEXTCONTENTPROPERTIES_H
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtDeclarative/QtDeclarative>
#include <Qt/qobject.h>
#include <bb/cascades/controls/textcontentflag.h>
namespace bb {
    namespace cascades {
        class TextContentPropertiesPrivate;
        class TextContentProperties : public QObject
        {
public:
            MOCK_CONST_METHOD0(flags, bb::cascades::TextContentFlag::Types ());
            MOCK_METHOD1(setFlags, void (bb::cascades::TextContentFlag::Types flags));
            MOCK_METHOD0(resetFlags, void ());
            MOCK_METHOD1(flagsChanged, void (bb::cascades::TextContentFlag::Types newFlags));
        };
    }
}
#endif 