/*
 * ValueGroup.hpp
 *
 *  Created on: Feb 2, 2012
 *      Author: issle
 */

#ifndef VALUEGROUP_HPP_
#define VALUEGROUP_HPP_

#include <iostream>
#include <deque>
#include <map>
#include <iostream>
#include "commons/tools/String.hpp"
#include "IValueGroup.hpp"

using namespace std;

class ValueGroup: public IValueGroup
{
private:
	map<string,deque<string> > values;

public:
	string getRandomValue(string var)
	{
		if(values.count(var) != 0 && values[var].size() !=0)
		{
			if(values[var].size() == 1)
				return values[var].front();
			else
				return values[var][Rnd::getInt(0,values[var].size()-1)];
		}
		else
		{
			return String::getRandom();
		}
	}

	void addValue(string var, string value)
	{
		if(values.count(var) == 0)
		{
			deque<string> s;
			s.push_back(value);
			values[var] = s;
		}
		else
			values[var].push_back(value);
	}
};


#endif /* VALUEGROUP_HPP_ */
