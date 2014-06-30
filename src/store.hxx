/**************************************************************************
 *  Copyright (C) 2014  Pierre Marchand <pierremarc07@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU  General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU  General Public License for more details.
 *
 *  You should have received a copy of the GNU  General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
**************************************************************************/

#ifndef GF_STORE_HXX
#define GF_STORE_HXX

#include <memory>
#include <iterator>

#include "options.hxx"

namespace gf {

enum StoreType{
    VERTEX,
    EDGE,
    PROPERTY
};

std::string
getStoreKey(const StoreType& t)
{
    if(VERTEX == t)
    {
        return std::string("vertex");
    }
    else if(EDGE == t)
    {
        return std::string("edge");
    }
    else if(PROPERTY == t)
    {
        return std::string("property");
    }

    return std::string();
}

class Store
{
    Store();

public:

    virtual iterator begin() const = 0;
    virtual iterator end() const = 0;

};


typedef std::shared_ptr<Store> StorePtr;

} // namespace gf

#endif // GF_STORE_HXX
