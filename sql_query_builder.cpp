#include "sql_query_builder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
	clears();
}

void SqlSelectQueryBuilder::clears() {
	column[0] = "*";
	column[1] = " ";
}

void SqlSelectQueryBuilder::AddColumn(const std::string ones, const std::string twos) {
	column[0] = ones; 
	column[1] = twos;
}

void SqlSelectQueryBuilder::AddFrom(const std::string ones) {
	from = ones;
}

void SqlSelectQueryBuilder::AddWhere(const std::string ones, const std::string twos, const std::string frees, const std::string fours) {
	where[0][0] = ones;
	where[0][1] = twos;
	where[1][0] = frees;
	where[1][1] = fours;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
	std::stringstream strings;
	strings << "Select " << column[0] << ", " << column[1] << " FROM " << from << " WHERE " << where[0][0] << "=" << where[0][1] << " AND " << where[1][0] << "=" << where[1][1];
	clears();
	std::string output = strings.str();
	return output;
}


void SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
	if (kv.size() != 0) {
		where2 = kv;
	}
}


void SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
	if (columns.size() > 0) {
		column2 = columns;
	}
}


std::string SqlSelectQueryBuilder::BuildQuery2() {
	std::stringstream strings;
	strings << "Select ";
	for (int i = 0; i < column2.size() - 1; i++) {
		strings << column2[i] << ", ";
	}
	strings << column2[column2.size()-1] << " FROM " << from << " WHERE ";
	int size = where2.size() - 1; int i = 0;
	for (auto& item : where2) {
		if (i == size) {
			strings << item.first << "=" << item.second;
			break;
		}
		strings << item.first << "=" << item.second << " AND ";
		i++;
	}
	std::string output = strings.str();
	return output;
}




