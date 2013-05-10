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

#ifndef PROXY_PROXYBASE_HPP
#define PROXY_PROXYBASE_HPP

#include <stdexcept>
#include <queue>
#include <typeinfo>

namespace bb {
namespace testing {

/*!
 * Exception thrown by ProxyBase class when a mock object is requested but none exists.
 */
class NullMockException : public std::runtime_error
{
public:
    NullMockException(std::string const &msg) :
        std::runtime_error(msg)
    {}
};

/*!
 * Base class for objects that implement the proxy-mock testing pattern.
 *
 * Mock objects created with the Google Mock framework suffer from several limitations.
 * They must be instantiated and configured with a set of expectations before they can be 
 * used by the code under test. Whereas the code under test may want to internally 
 * instantiate it's dependencies. Mock objects also cannot handle constructors, overloaded 
 * operators, or static methods.
 *
 * The proxy-mock testing pattern addresses these issues by inserting an extra object, 
 * the proxy, between the code under test and the mock object. The proxy perfectly 
 * reproduces the interface of a real dependency (but is not related to it in any way) and 
 * forwards all calls to a mock object. Calls to constructors, overloaded operators, and 
 * static methods are remapped to regular member methods of the mock object. When the code 
 * under test creates a proxy object, the proxy obtains a mock object from a global registry. 
 * Mock objects are created, configured, and registered (see @c pushMock() and 
 * @c setStaticMock()) ahead of time before exercising the code under test.
 *
 * Using the proxy-mock pattern reduces the need to refactor/redesign the code under test.
 * The one remaining problem is figuring out how to get the code under test to use the proxy
 * instead of the real dependency when creating a test build. This can be done with #defines
 * at beginning of each cpp file that map the name of the real dependency to the name of the
 * proxy class. This trick satisfies the compiler as you still include the header file for
 * the real dependency but fools the linker beacause all symbol names reference the proxy
 * class instead of the real class.
 */
template <typename MockClass>
class ProxyBase
{
public:
    ProxyBase() :
        _mock(NULL)
    {
        // assert that an instance mock is available
        if (_mockQueue.empty()) {
            throw NullMockException(std::string("Mock queue is empty: ") + typeid(this).name());
        }

        // pop the next instance mock off the queue
        _mock = _mockQueue.front();
        _mockQueue.pop();
    }

    virtual ~ProxyBase()
    {
    }

    static void pushMock(MockClass* mock)
    {
        // push a new instance mock onto the queue;
        // NOTE: ownership of the mock does NOT transfer
        _mockQueue.push(mock);
    }

    static MockClass* staticMock()
    {
        // assert that a static mock is available
        if (!_staticMock) {
           throw NullMockException(std::string("Static mock not set: ") + __PRETTY_FUNCTION__ );
        }

        return _staticMock;
    }

    template <typename T>
    static T * staticMock()
    {
        T * result = dynamic_cast<T *>(staticMock());
        if (result == NULL) {
            throw std::runtime_error( std::string("Invalid static mock cast: ") + __PRETTY_FUNCTION__ );
        } else {
            return result;
        }
    }

    static void setStaticMock(MockClass* mock)
    {
        // save new static mock;
        // NOTE: ownership of the mock does NOT transfer
        _staticMock = mock;
    }

    static void reset()
    {
        // clear instance queue and static mock
        _mockQueue = std::queue<MockClass*>();
        _staticMock = NULL;
    }

protected:
    MockClass* mock() const
    {
        return _mock;
    }

    template <typename T>
    T * mock() const
    {
        if (mock() == NULL) {
            throw NullMockException(std::string("Mock queue is empty during cast: ") + typeid(this).name());
        }
        T * result = dynamic_cast<T *>(mock());
        if (result == NULL) {
            throw std::runtime_error( std::string("Invalid mock cast from \"") + typeid(mock()).name() + "\":"  + __PRETTY_FUNCTION__ );
        } else {
            return result;
        }
    }

private:
    static std::queue<MockClass*> _mockQueue;
    static MockClass *_staticMock;
    MockClass *_mock;
};

template <typename MockClass>
std::queue<MockClass*> ProxyBase<MockClass>::_mockQueue;

template <typename MockClass>
MockClass* ProxyBase<MockClass>::_staticMock;

} // namespace testing
} // namespace bb

#endif // PROXY_PROXYBASE_HPP
