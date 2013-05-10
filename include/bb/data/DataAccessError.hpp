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


#ifndef BB_DATA_DATAACCESSERROR_H
#define BB_DATA_DATAACCESSERROR_H


#include <bb/data/dataaccesserrortype.h>
#include <QObject>
#include "gmock/gmock.h"


namespace bb
{
namespace data
{


class DataAccessError : public QObject
{
public:
	DataAccessError(){};
	virtual ~DataAccessError(){};
	DataAccessError(DataAccessErrorType::Type anErrorType, const QString& errorMsg) {};
	
	MOCK_METHOD0(errorMessage, QString());
	MOCK_METHOD0(errorType, DataAccessErrorType::Type());
};


}
}


#endif // BB_DATA_DATAACCESSERROR_H


