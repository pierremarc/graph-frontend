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

#ifndef GF_OPTIONS_HXX
#define GF_OPTIONS_HXX

#include <string>
#include <vector>
#include <map>
#include <boost/any.hpp>


namespace gf {

class Options
{
    std::map<std::string, std::string> options;

public:
    Options();
    Options(int argc, char **argv);


    void put(const std::string& key, const std::string& value);

    bool has(const std::string& key) const;

    std::vector<std::string> keys() const;

    template<typename T>
    T get(const std::string& key, const T default_value) const
    {
        if(this->options.find(key) != this->options.end())
        {
            try
            {
                boost::any v(this->options.at(key));
                return boost::any_cast<T>(v);
            }
            catch(boost::bad_any_cast&)
            {
                return default_value;
            }
        }
        return default_value;
    }
};


} // namespace gf


#endif // GF_OPTIONS_HXX
