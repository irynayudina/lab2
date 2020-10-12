#include "CELLCOLUMNS.h"

ostream& operator<<(ostream& out, const CELLCOLUMNS& point)
{
	out << '\n' << point.cols_ << " ";
	for (int i = 0; i < point.cols_; i++)
	{
		out << point.data_[i] << " ";
	}
	out << '\n';
	return out;
}
istream& operator>> (istream& out, CELLCOLUMNS& point)
{
	out >> point.cols_;
	for (int i = 0; i < point.cols_; i++)
	{
		out >> point.data_[i];
	}
	return out;
}
