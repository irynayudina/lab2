#include "SHEET.h"

ostream& operator<<(ostream& out, const SHEET& point)
{
	out << '\n' << point.name_length << " ";
	for (int i = 0; i < point.name_length; i++)
	{
		out << point.name[i];
	}
	out << " " << point.content_length << " ";
	for (int i = 0; i < point.content_length; i++)
	{
		out << point.content[i];
	}
	out << " " << point.protection << '\n';;
	return out;
}
istream& operator>> (istream& out, SHEET& point)
{
	out >> point.name_length;
	for (int i = 0; i < point.name_length; i++)
	{
		out >> point.name[i];
	}
	out >> point.content_length;
	for (int i = 0; i < point.content_length; i++)
	{
		out >> point.content[i];
	}
	out >> point.protection;
	return out;
}