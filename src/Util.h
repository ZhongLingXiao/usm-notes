#pragma once

#include "Library.h"

namespace Suffer
{
    extern const string EMPTY_STRING;

    using ElementPtr        = shared_ptr<class Element>;
    using ConstElementPtr   = shared_ptr<const class Element>;

    string createVaildName(string name, char replaceChar = '_');

    bool isVaildName(const string& name);

    string incrementName(const string& name);

    StringVector splitString(const string& str, const string& sep);

    string printElement(ConstElementPtr elem);

}; // namespace Suffer
