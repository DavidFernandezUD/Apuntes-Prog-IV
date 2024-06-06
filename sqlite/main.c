#include <stdio.h>
#include <string.h>
#include "sqlite3.h"


int create_tables(sqlite3* db) {

    const char* sql_create_table_subject = 
        "CREATE TABLE IF NOT EXISTS subject("
        "   id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "   name TEXT NOT NULL"
        ");"
    ;

    const char* sql_create_table_student = 
        "CREATE TABLE IF NOT EXISTS student("
        "   id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "   name TEXT NOT NULL,"
        "   second_name TEXT NOT NULL,"
        "   mark REAL NOT NULL,"
        "   subject_id INTEGER,"
        "   FOREIGN KEY (subject_id) REFERENCES subject(id) ON DELETE CASCADE"
        ");"
    ;

    // Use sqlite3_exec() to create tables
    if (sqlite3_exec(db, sql_create_table_subject, 0, 0, NULL) != SQLITE_OK)
        return 1;

    if (sqlite3_exec(db, sql_create_table_student, 0, 0, NULL) != SQLITE_OK)
        return 1;

    return SQLITE_OK;
}


int insert_subject(sqlite3* db, const char* name) {

    sqlite3_stmt* stmt;

    const char* sql_insert_subject = "INSERT INTO subject (name) VALUES (?);";

    // Prepare statement
    if (sqlite3_prepare_v2(db, sql_insert_subject, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed preparing statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Bind statement (fill ? values)
    // sqlite3_bind_text(statement, param_index, param_value, strlen(param_value), SQLITE_STATIC)
    if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK) {
        fprintf(stderr, "Failed binding statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Use sqlite3_step() to execute a statement
    // Remember it returns SQLITE_DONE instead of SQLITE_OK
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Failed inserting subject: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Use sqlite3_finalize() to finalize an statement
    if (sqlite3_finalize(stmt) != SQLITE_OK) {
        fprintf(stderr, "Failed finalizing statement");
        return 1;
    }

    return SQLITE_OK;
}


int insert_student(sqlite3* db, const char* name, const char* second_name, float mark, int subject_id) {

    sqlite3_stmt* stmt;

    const char* sql_insert_student = "INSERT INTO student (name, second_name, mark, subject_id) VALUES (?, ?, ?, ?);";

    // Prepare statement
    if (sqlite3_prepare_v2(db, sql_insert_student, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Bind text
    if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK) {
        fprintf(stderr, "Failed binding statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Bind text
    if (sqlite3_bind_text(stmt, 2, second_name, -1, SQLITE_STATIC) != SQLITE_OK) {
        fprintf(stderr, "Failed binding statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Bind float
    if (sqlite3_bind_double(stmt, 3, mark) != SQLITE_OK) {
        fprintf(stderr, "Failed binding statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Bind int
    if (sqlite3_bind_int(stmt, 4, subject_id) != SQLITE_OK) {
        fprintf(stderr, "Failed binding statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Execute statement
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Failed inserting student: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Finalize statement
    if (sqlite3_finalize(stmt) != SQLITE_OK) {
        fprintf(stderr, "Failed finalizing statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    return SQLITE_OK;
}


int show_students(sqlite3* db) {

    sqlite3_stmt *stmt;

    // const char* sqlite_select_student = "SELECT id, name, second_name, mark, subject_id FROM student;";
    const char* sqlite_select_student = "SELECT * FROM student;";

    // Prepare statement
    // NOTE: Use -1 as length to let it guess it
    if (sqlite3_prepare_v2(db, sqlite_select_student, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Print table header
    printf("id\tname\tsecond_name\tmark\tsubject_id\n");
    printf("-----------------------------------------\n");

    // Print each row in a loop
    int err_code;
    while ((err_code = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);   // Remember to use 0 as index in sqlite_column_xxx()
        const unsigned char* name = sqlite3_column_text(stmt, 1);
        const unsigned char* second_name = sqlite3_column_text(stmt, 2);
        float mark = (float) sqlite3_column_double(stmt, 3);
        int subject_id = sqlite3_column_int(stmt, 4);

        printf("%d\t%s\t%s\t%.2f\t%d\n", id, name, second_name, mark, subject_id);
    }

    if (err_code != SQLITE_DONE) {
        fprintf(stderr, "Failed to select students: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return err_code;
    }

    sqlite3_finalize(stmt);

    return SQLITE_OK;
}


int delete_stuednt(sqlite3* db, int id) {
    
    sqlite3_stmt* stmt;

    const char* sql_delete_student = "DELETE FROM student WHERE id = ?;";

    int err_code;

    // Prepare statement
    if ((err_code = sqlite3_prepare_v2(db, sql_delete_student, -1, &stmt, NULL)) != SQLITE_OK) {
        fprintf(stderr, "Failed preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return err_code;
    }

    // Bind student id
    if ((err_code = sqlite3_bind_int(stmt, 1, id)) != SQLITE_OK) {
        fprintf(stderr, "Failed binding student: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return err_code;
    }

    // Execute statement
    if ((err_code = sqlite3_step(stmt)) != SQLITE_DONE) {
        fprintf(stderr, "Failed delating student: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return err_code;
    }

    sqlite3_finalize(stmt);

    return SQLITE_OK;
}


int delete_all_students(sqlite3* db) {
    
    sqlite3_stmt* stmt;

    const char* sql_delete_students = "DELETE FROM student;";

    int err_code;

    if ((err_code = sqlite3_prepare(db, sql_delete_students, -1, &stmt, NULL)) != SQLITE_OK) {
        fprintf(stderr, "Failed preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return err_code;
    }

    if ((err_code = sqlite3_step(stmt)) != SQLITE_DONE) {
        fprintf(stderr, "Failed deleting all students: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return err_code;
    }

    sqlite3_finalize(stmt);

    return SQLITE_OK;
}


int main() {
    
    // Instantiate data base pointer (kind of like FILE*)
    sqlite3* db;
    
    // Use sqlite3_open() to create or open the database
    if (sqlite3_open("test.sqlite", &db) != SQLITE_OK) {
        fprintf(stderr, "Failed opening database\n");
        return 1;
    }

    printf("Opened database\n");
    
    if (create_tables(db) != SQLITE_OK) {
        fprintf(stderr, "Error creating tables\n");
        return 1;
    }

    printf("Created tables\n");

    insert_subject(db, "math");
    insert_subject(db, "prog");
    insert_subject(db, "algebra");

    printf("Inserted subjects\n");

    insert_student(db, "Mark", "Martinez", 8.2f, 1);
    insert_student(db, "David", "Fernandez", 9.2f, 2);
    insert_student(db, "Juan", "Restrepo", 6.2f, 3);

    printf("Inserted students\n");

    show_students(db);

    printf("Deleted student");
    delete_stuednt(db, 1);
    show_students(db);

    printf("Deleted student");
    delete_stuednt(db, 3);
    show_students(db);

    insert_student(db, "Juan", "Restrepo", 6.2f, 3);
    printf("Inserted students\n");
    show_students(db);

    delete_all_students(db);
    printf("Deleted all students\n");
    show_students(db);
    
    return 0;
}

