#include "CELL.h"

ostream& operator<<(ostream& out, const CELL& point)
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
istream& operator>> (istream& out, CELL& point)
{
	int nl, cl, p;
	char* n; char* c;
	out >> nl;
	point.set_name_length(nl);
	n = new char[nl];
	for (int i = 0; i < nl; i++)
	{
		out >> n[i];
	}
	point.set_name(nl, n);
	out >> cl;
	point.set_content_length(cl);
	c = new char[cl];
	for (int i = 0; i < cl; i++)
	{
		out >> c[i];
	}
	point.set_content(cl, c);
	out >> p;
	point.set_protection(p);
	return out;
}
