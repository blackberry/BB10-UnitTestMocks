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
#ifndef BB_CASCADES_INPUTPROPERTIES_H
#define BB_CASCADES_INPUTPROPERTIES_H
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtDeclarative/QtDeclarative>
#include <bb/cascades/SubmitKey>
#include <bb/cascades/controls/abstracttextcontrol.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/controls/input/textinputflag.h>
#include <bb/cascades/SubmitKeyFocusBehavior>
namespace bb {
namespace cascades {
class TextInputPropertiesPrivate;
class TextInputProperties : public UIObject
{
     MOCK_METHOD1(submitted, void (bb::cascades::AbstractTextControl *submitter));
     MOCK_METHOD1(submitKeyChanged, void (const bb::cascades::SubmitKey::Type submitKey));
     MOCK_METHOD1(flagsChanged, void (bb::cascades::TextInputFlag::Types newFlags));
public:
    virtual ~TextInputProperties();
    MOCK_METHOD1(setSubmitKey, void (bb::cascades::SubmitKey::Type submitKey));
    MOCK_METHOD0(resetSubmitKey, void ());
    MOCK_METHOD0(submitKey, bb::cascades::SubmitKey::Type ());
    MOCK_CONST_METHOD0(flags, bb::cascades::TextInputFlag::Types ());
    MOCK_METHOD1(setFlags, void (bb::cascades::TextInputFlag::Types flags));
    MOCK_METHOD0(resetFlags, void ());
    MOCK_METHOD1(setSubmitKeyFocusBehavior, void(bb::cascades::SubmitKeyFocusBehavior::Type submitKeyFocusBehavior));
};
}
}
#endif 
