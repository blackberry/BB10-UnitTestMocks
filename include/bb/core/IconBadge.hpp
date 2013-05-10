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
#ifndef BB_CORE_ICONBADGE_HPP
#define BB_CORE_ICONBADGE_HPP
#include <QObject>
namespace bb
{
class IconBadge
{
public:
    enum Type {
        None = 0, /*!< No badge. */
        Splat = 1 /*!< A splat badge (a white asterisk in a red circle). */
    };
};
} // namespace bb
#endif // BB_CORE_ICONBADGE_HPP
