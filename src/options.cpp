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

#include "options.hxx"


#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>


namespace gf {

Options::Options()
{
}


Options::Options(int argc, char **argv)
{
    for(int i=0; i < argc; ++i){
        std::string a(argv[i]);
        std::vector<std::string> r;
        boost::split(r, a, boost::is_any_of("="));
        if(2 == r.size()){
            put(r[0], r[1]);
        }
    }
}

void
Options::put(const std::string &key, const std::string &value){
    options[key] = value;
}

bool
Options::has(const std::string &key) const
{
    return (options.find(key) != options.end());
}

std::vector<std::string>
Options::keys() const
{
    std::vector<std::string> ret;
    for(std::map<std::string, std::string>::const_iterator it = options.begin();
        it != options.end();
        it++)
    {
        ret.push_back(it->first);
    }
    return ret;
}

}

