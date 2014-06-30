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

#include "storefactory.hxx"
#include "stores/mongo/stores.hxx"

namespace gf {


StoreFactory::StoreFactory(const StoreType& st, const Options &opts)
{
    std::string df;
    std::string sname(opts.get(getStoreKey(st), df));
    if(sname == df){
        // TODO throw something
    }

    if(0 == sname.compare("mongo")){
        store.reset(::gf::mongo::get_store(st, opts));
    }
    else if(0 == sname.compare("mem")){
        store.reset(::gf::memory::get_store(st, opts));
    }
}

StorePtr
StoreFactory::get() const
{
    return store;
}

} // namespace gf
