#pragma once
#include "iostream"
#include <sstream>
#include <map>
#include <vector>

class SqlSelectQueryBuilder
{
private:
	std::string column[2];
	std::string from;
	std::string where[2][2];
	
	void clears();

	std::map<std::string, std::string> where2;
	std::vector<std::string> column2;

public:
	class SqlSelectQueryBuilder();
	void AddColumn(const std::string ones, const std::string twos);
	void AddFrom(const std::string ones);
	void AddWhere(const std::string ones, const std::string twos, const std::string frees, const std::string fours);
	std::string BuildQuery();

	void AddWhere(const std::map<std::string, std::string>& kv) noexcept;
	void AddColumns(const std::vector<std::string>& columns) noexcept;
	std::string BuildQuery2();
};

