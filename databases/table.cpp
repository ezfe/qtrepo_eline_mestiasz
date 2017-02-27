#include "table.h"

Table::Table() {
    std::cerr << "No database/name provided to database" << std::endl;
    exit(-1);
}

Table::Table(Database* database, std::string name) {
    this->current = database;
    this->name = name;

    store_exist_sql();
    store_create_sql();
    store_drop_sql();
    store_size_sql();

    sql_add_row = "";
}

void Table::build_table() {
    exists();

    if (!table_exists) {
        create();
    }
}

void Table::store_template_sql() {
    sql_template =  "SELECT name ";
    sql_template += "FROM sqlite_master ";
    sql_template += "WHERE ";
    sql_template += "type = \"table\";";
}

void Table::store_exist_sql() {
    sql_exist  = "SELECT count(*) ";
    sql_exist += "FROM sqlite_master ";
    sql_exist += "WHERE ";
    sql_exist += "type = \"table\" ";
    sql_exist += "and name = \"" + this->name + "\";";
}

void Table::store_create_sql() {
    sql_create =  "CREATE TABLE ";
    sql_create += this->name + " ";
    sql_create += "(";
    sql_create += "id INT PRIMARY KEY NOT NULL, ";
    sql_create += "item0 TEXT NOT NULL, ";
    sql_create += "item1 INT  NOT NULL, ";
    sql_create += "item2 CHAR(50), ";
    sql_create += "item3 REAL";
    sql_create += ");";
}

void Table::store_drop_sql() {
    sql_drop = "DROP TABLE " + this->name + ";";
}

void Table::store_size_sql() {
    sql_size =  "SELECT count(*) ";
    sql_size += "FROM ";
    sql_size += this->name + ";";
}

int Table::dbtemplate() {
    /* This is currently copied directly from DBTable.cpp */

    // Initialize local variables.
    int retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(current->db(), sql_template.c_str(), cb_template, this, &zErrMsg);

    if(retCode != SQLITE_OK) {
        std::cerr << sql_template << std::endl;
        std::cerr << "SQL error: "<< zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    return retCode;
}

bool Table::exists() {
    /* This is currently copied directly from DBTable.cpp */

    // Initialize local variables.
    int retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.  The parameters
    // are identified as follows:
    // 1. Provide reference to sqlite object in dbtool.
    // 2. Provide the SQL command as a C string.
    // 3. Provide pointer to callback function coded below.
    // 4. Pointer to the DBTable object.
    // 5. Pointer to varible where sqlite will place error code.
    retCode = sqlite3_exec(current->db(), sql_exist.c_str(), cb_exist, this, &zErrMsg);

    // Process return code.
    if(retCode != SQLITE_OK) {
        std::cerr << sql_exist << std::endl;
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    return retCode;
}

int cb_exist(void  *data,        // pointer to the DBTable object.
             int    argc,        // number of data columns
             char **argv,        // the actual data columns
             char **azColName) { // the data column names
    /* This is currently copied directly from DBTable.cpp */

    if(argc != 1) {
        // If call fails, generate error message.
        std::cerr << "More than 1 item returned " << "argc = " << argc << std::endl;
    } else {
        Table* obj = (Table*) data;
        obj->set_exists(atoi(argv[0]));
    }

    return 0;
}

// Create the db table.
bool Table::create() {

    // Initialize local variables.
    int   retCode = 0;
    char* zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_create.c_str(),
                           cb_create,
                           this,
                           &zErrMsg);

    // Process a failed call.
    if (retCode != SQLITE_OK) {
        std::cerr << sql_create << std::endl;
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    // Return the code.
    return retCode;
}

// The callback after the table is created.   SQLite
// will pass the results of the call and this function
// will manipulate and make changes to the DBTable object.
int cb_create(void  *data,
              int    argc,
              char **argv,
              char **azColName){

    // Create failed, generate error message.
    if (argc < 1) {
        std::cerr << "No data presented to callback " << "argc = " << argc << std::endl;
    }

    // Commented code prints information returned by
    // sqlite.

    // std::cout << "------------------------------\n";
    // std::cout << obj->get_name()
    // 	    << std::endl;

    // int i;
    // for(i = 0; i < argc; i++){
    //   std::cout << azColName[i]
    // 	      << " = "
    // 	      <<  (argv[i] ? argv[i] : "NULL")
    // 	      << std::endl;
    // }

    // Return the code.
    return 0;
}

// Removes the db table from the database.
bool Table::drop() {

    /* This is currently copied directly from DBTable.cpp */

    // Initialize local variables.
    int retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(current->db(),
                           sql_drop.c_str(),
                           cb_drop,
                           this,
                           &zErrMsg);

    // Process a failed call.
    if (retCode != SQLITE_OK) {
        std::cerr << sql_drop << std::endl;
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    //
    return retCode;
}

// The callback after the table is droped.   SQLite
// will pass the results of the call and this function
// will manipulate and make changes to the DBTable object.
int cb_drop(void  *data,
            int    argc,
            char **argv,
            char **azColName){

    /* This is currently copied directly from DBTable.cpp */

    // Table not dropped, generate error message.
    if (argc < 1) {
        std::cerr << "No data presented to callback " << "argc = " << argc << std::endl;
    }

    // std::cout << "------------------------------\n";
    // std::cout << obj->get_name()
    // 	    << std::endl;

    // int i;
    // for(i = 0; i < argc; i++){
    //   std::cout << azColName[i]
    // 	      << " = "
    // 	      <<  (argv[i] ? argv[i] : "NULL")
    // 	      << std::endl;
    // }

    return 0;
}

// Determines the number of rows in the table.
int Table::size() {

    /* This is currently copied directly from DBTable.cpp */

    // Initialize local variables.
    int retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(current->db(),
                           sql_size.c_str(),
                           cb_size,
                           this,
                           &zErrMsg          );

    // Process a failed call.
    if (retCode != SQLITE_OK) {

        std::cerr << sql_size << std::endl;

        std::cerr << "SQL error: " << zErrMsg << std::endl;

        sqlite3_free(zErrMsg);
    }

    // Return the number of rows in table.
    return _row_count;
}

// The callback after the size is computed.   SQLite
// will pass the results of the call and this function
// will manipulate and make changes to the DBTable object.
int cb_size(void  *data,
            int    argc,
            char **argv,
            char **azColName){

    /* This is currently copied directly from DBTable.cpp */

    // If no data is presented generate error message.
    if (argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    } else {
        // Store size in object.
        Table *obj = (Table *) data;
        obj->set_size(atoi(argv[0]));
    }

    return 0;
}

std::string Table::get_name() {
    return this->name
}
