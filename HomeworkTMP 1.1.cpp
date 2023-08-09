#include <iostream>
#include "sql_query_builder.h"

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name", "phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42", "name", "John");

    std::cout << query_builder.BuildQuery() << std::endl;



    std::map<std::string, std::string> kvMain;
    kvMain.emplace("id", "42");
    kvMain.emplace("name", "John");
    kvMain.emplace("lastname", "Alonzo");
    std::vector<std::string> columnMain = {"name", "phone", "book"};

    query_builder.AddColumns(columnMain);
    query_builder.AddFrom("teachers");
    query_builder.AddWhere(kvMain);

    std::cout << query_builder.BuildQuery2() << std::endl;
}