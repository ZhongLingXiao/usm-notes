#pragma once

#include <algorithm>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include <exception>
#include <map>
#include <unordered_map>
#include <set>

namespace Suffer
{
using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;

/// A vector of strings.
using StringVector = vector<string>;
/// An unordered map with strings as both keys and values.
using StringMap = std::unordered_map<string, string>;
/// A set of strings.
using StringSet = std::set<string>;


/// @class Exception
/// suffer中全部异常(exception)的基类，用于将Suffer中的异常传递给
/// 客户端应用程序
class Exception : public std::exception
{
  public:

    explicit Exception(const string& msg) : 
        _msg(msg) 
    {}

    Exception(const Exception& e) : 
        _msg(e._msg)
    {}

    Exception& operator=(const Exception& e)
    {
        _msg = e._msg;
        return *this;
    }

    virtual ~Exception() noexcept
    {}

    const char* what() const noexcept override
    {
        return _msg.c_str();
    }

  private:
  
    string _msg{};
}; // class Exception

}; // namespace Suffer
