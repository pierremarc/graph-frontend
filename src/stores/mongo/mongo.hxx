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

#ifndef MONGO_HXX
#define MONGO_HXX

#include "store.hxx"

#include <mongo/client/dbclient.h>

namespace gf {
namespace mongo {

class MongoStore : public Store
{
    mongo::DBClientConnection client;

public:

    virtual const begin() const;
    virtual const end() const;

};

} // namespace mongo
} // namespace gf

#endif // MONGO_HXX
