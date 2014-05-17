#pragma once

///Namespace, to work with errors, connected with hashtable
namespace TableErrors
{
    ///Error, whent you whant to delete val, which is not exists in table
    class NoSuchVal{};
    ///Error, whent you whant to add val, which is already in table
    class FindEqualVal{};
}
