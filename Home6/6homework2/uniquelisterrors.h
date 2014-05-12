#pragma once

///Namespace, to work with errors, connected with unique list
namespace UniqueListErrors
{
    ///Error, whent you whant to add val, which is already in list
    class FindEqualVal{};
    ///Error, whent you whant to delete val, which is not exists in list
    class NoSuchVal{};
}
