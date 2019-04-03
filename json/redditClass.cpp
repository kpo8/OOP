#include "reddit.hpp"

#include <iostream>

void author::getAuthor()
{
	while(!x.eof())
	{
		cout <<	x["author"] << endl;
	}
}

void title::getTitle()
{
	while(!x.eof())
	{
		cout <<	x["title"] << endl;
	}

}
