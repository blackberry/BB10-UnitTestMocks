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

#ifndef ABSTRACTSIGNALCATCHER_H_
#define ABSTRACTSIGNALCATCHER_H_

#include <QObject>
#include <QVariantList>
#include <bb/cascades/Color>

namespace bb {
namespace testing {

/*! * @brief Abstract base class for the SignalCatcher mock object */
class AbstractSignalCatcher: public QObject {
	Q_OBJECT
public:
	AbstractSignalCatcher(QObject *parent = 0) : QObject(parent) {

	}
	virtual ~AbstractSignalCatcher() {

	}

public Q_SLOTS:
	virtual void colorChanged(bb::cascades::Color color) = 0;
	virtual void confirmed() = 0;
};

} /* namespace testing */
} /* namespace bb */

#endif /* ABSTRACTSIGNALCATCHER_H_ */

