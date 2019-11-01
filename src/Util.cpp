#include "Util.h"
#include "Element.h"

namespace Suffer
{

const string EMPTY_STRING;

string createVaildName(string name, char replaceChar)
{
    std::replace_if(std::begin(name), std::end(name),
        [](char c) { return !isalnum(c) && c != '_' && c != ':'; },
        replaceChar);

    return name;
}

bool isVaildName(const string& name)
{
    auto it = std::find_if(std::begin(name), std::end(name), 
        [](char c) { return !isalnum(c) && c != '_' && c != ':'; });

    return it == std::end(name);    
}

string incrementName(const string& name)
{
    auto split = name.size();
    while (split > 0)
    {
        if(!isdigit(name[split-1]))
        {
            break;
        }
        split--;
    }

    if (split < name.length())
    {
        string prefix = name.substr(0, split);
        string suffix = name.substr(split, name.length());
        return prefix + std::to_string(std::stoi(suffix) + 1);
    }

    return name + "2";
}

StringVector splitString(const string& str, const string& sep)
{
    StringVector split;

    auto lastPos = str.find_first_not_of(sep, 0);
    auto pos = str.find_last_of(sep, lastPos);

    while( lastPos != string::npos || pos != string::npos )
    {
        split.push_back(str.substr(lastPos, pos-lastPos));
        lastPos = str.find_first_not_of(sep, pos);
        pos = str.find_first_of(sep, lastPos);        
    }

    return split;
}

string printElement(ElementPtr)
{
    // 需要遍历整个Element，将整个节点树打印出来。
}

};

