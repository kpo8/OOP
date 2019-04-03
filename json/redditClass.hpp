#pragma once

#include "json.hpp"
#include <string>

class redditPost
{
	private:
		Value author;
		Value title;

};

class author : redditPost
{
	public:
		author();
		void getAuthor();
};

class title : redditPost
{
	public:
		title();
		void getTitle();
};
