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

#ifndef BB_CORE_PPSATTRIBUTEFLAG_HPP
#define BB_CORE_PPSATTRIBUTEFLAG_HPP

#include <QObject>
#include <QFlags>

namespace bb
{
class PpsAttributeFlag
{
    Q_GADGET
    Q_ENUMS(Type)
    Q_FLAGS(Types)

public:
    enum Type {
        Incomplete = 0x01,
        Deleted    = 0x02,
        Created    = 0x04,
        Truncated  = 0x08,
        Purged     = 0x10
    };
    Q_DECLARE_FLAGS(Types, Type)

private:
    PpsAttributeFlag();
    ~PpsAttributeFlag();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(PpsAttributeFlag::Types)

} // namespace bb

#endif // BB_CORE_PPSATTRIBUTEFLAGS_HPP
