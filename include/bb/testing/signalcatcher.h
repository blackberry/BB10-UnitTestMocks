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

#ifndef SIGNALCATCHER_H_
#define SIGNALCATCHER_H_
#include "abstractsignalcatcher.h"
#include "gmock/gmock.h"
#include <bb/cascades/Color>

namespace bb {
namespace testing {
/*!
* @brief A simple mocked class to count the number of signals caught from classes for testing.
*/
class SignalCatcher: public AbstractSignalCatcher {
Q_OBJECT
public:
	SignalCatcher(QObject *parent = 0) : AbstractSignalCatcher(parent) {

	}
	virtual ~SignalCatcher() {

	}

	MOCK_METHOD1(colorChanged, void(bb::cascades::Color));
	MOCK_METHOD0(confirmed, void());
};

} /* namespace testing */
} /* namespace bb */

#endif /* SIGNALCATCHER_H_ */

