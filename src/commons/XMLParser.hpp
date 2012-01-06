/*
 * XMLParser.hpp
 *
 *  Created on: Jan 6, 2012
 *      Author: issle
 */

#ifndef XMLPARSER_HPP_
#define XMLPARSER_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ptree_fwd.hpp>
#include <boost/foreach.hpp>

using boost::property_tree::ptree;
using namespace std;

class XMLParser
{
private:
	ifstream* fileStream;
public:
	XMLParser(string filename)
	{
		//fileStream = new std::ifstream(filename.c_str());
		//if (!fileStream->is_open())
		//{
		//	cout << "Could not open file :" << filename << endl;
		//	exit(0);
		//}

		read(filename);

	}

	void load(const std::string &filename)
	{
	    ptree pt;

	    // Load the XML file into the property tree. If reading fails
	    // (cannot open file, parse error), an exception is thrown.
	    read_xml(filename, pt);

	    // Get the filename and store it in the m_file variable.
	    // Note that we construct the path to the value by separating
	    // the individual keys with dots. If dots appear in the keys,
	    // a path type with a different separator can be used.
	    // If the debug.filename key is not found, an exception is thrown.
	    //m_file = pt.get<std::string>("debug.filename");

	    // Get the debug level and store it in the m_level variable.
	    // This is another version of the get method: if the value is
	    // not found, the default value (specified by the second
	    // parameter) is returned instead. The type of the value
	    // extracted is determined by the type of the second parameter,
	    // so we can simply write get(...) instead of get<int>(...).
	    //m_level = pt.get("debug.level", 0);

	    // Iterate over the debug.modules section and store all found
	    // modules in the m_modules set. The get_child() function
	    // returns a reference to the child at the specified path; if
	    // there is no such child, it throws. Property tree iterators
	    // are models of BidirectionalIterator.
	    //BOOST_FOREACH(ptree::value_type &v,
	           // pt.get_child("debug.modules"))
	        //m_modules.insert(v.second.data());
	}

	void read(const std::string &filename)
	{
		// populate tree structure pt
		ptree pt;

		string s("build.xml");
		cout << "Running with: "<< s << endl;
		read_xml(*&s, pt);


		cout << "Came here." << endl;
		// traverse pt
		//Sked ans;
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("html") )
		{
			/**
			if( v.first == "flight" )
			{
				cout << "Found a flight." << endl;
				cout << v.second.get<std::string>("carrier") << endl;;
				v.second.get<unsigned>("number");
				//v.second.get<Date>("date");
				v.second.get("<xmlattr>.cancelled", false);
			}
			*/
		}

	}

	~XMLParser()
	{
		fileStream->close();
		delete fileStream;
		fileStream = NULL;
	}
};

#endif /* XMLPARSER_HPP_ */
