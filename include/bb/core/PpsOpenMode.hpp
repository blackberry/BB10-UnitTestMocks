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

#ifndef BB_CORE_PPSOPENMODE_HPP
#define BB_CORE_PPSOPENMODE_HPP

#include <QObject>
#include <QFlags>

namespace bb
{

class PpsOpenMode
{
    Q_GADGET
    Q_ENUMS(Type)

public:
    enum Type {
        Publish = 1,
        Subscribe = 2,
        PublishSubscribe = Publish | Subscribe,
        Create = 4,
        DeleteContents = 8
    };
    Q_DECLARE_FLAGS(Types, Type)

private:
    PpsOpenMode();
    ~PpsOpenMode();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(PpsOpenMode::Types)

} // namespace bb

#endif // BB_CORE_PPSOPENMODE_HPP
