#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include<time.h>

#define NUMBER_OF_INSERT 100

int main(int argc, char *argv[])
{
    // conninfo is a string of keywords and values separated by spaces.
    const char *conninfo = "dbname=test_index user=postgres password=paulo29 host=localhost port=5432";

    // Create a connection
    PGconn *conn = PQconnectdb(conninfo);

    // Check if the connection is successful
    if (PQstatus(conn) != CONNECTION_OK) {
        // If not successful, print the error message and finish the connection
        printf("Error while connecting to the database server: %s\n", PQerrorMessage(conn));

        // Finish the connection
        PQfinish(conn);

        // Exit the program
        exit(1);
    }

    // We have successfully established a connection to the database server
    printf("Connection Established\n");
    printf("Port: %s\n", PQport(conn));
    printf("Host: %s\n", PQhost(conn));
    printf("DBName: %s\n", PQdb(conn));

    //* seed random
    srand(time(NULL));
    int random_value;

    for (size_t i = 0; i < NUMBER_OF_INSERT; i++)
    {
        random_value = rand()%10;

        // Execute a query
        char *query = "INSERT INTO films (title, duration, score, release_date) values ('test 1', '01:30:00', '1', TO_DATE('17/12/2016', 'DD/MM/YYYY'))";
        query[71]= random_value%10;
        // Submit the query and retrieve the result
        PGresult *res = PQexec(conn, query);

        // Check the status of the query result
        ExecStatusType resStatus = PQresultStatus(res);

        // Convert the status to a string and print it
        printf("Query Status: %s\n", PQresStatus(resStatus));

        // Check if the query execution was successful
        if (resStatus != PGRES_TUPLES_OK) {
            // If not successful, print the error message and finish the connection
            printf("Error while executing the query: %s\n", PQerrorMessage(conn));

            // Clear the result
            PQclear(res);

            // Finish the connection
            PQfinish(conn);

            // Exit the program
            exit(1);
        }
            // Check if the query execution was successful
        if (resStatus != PGRES_TUPLES_OK) {
            // If not successful, print the error message and finish the connection
            printf("Error while executing the query: %s\n", PQerrorMessage(conn));

            // Clear the result
            PQclear(res);

            // Finish the connection
            PQfinish(conn);

            // Exit the program
            exit(1);
        }

        // We have successfully executed the query
        printf("Query Executed Successfully\n");
        PQclear(res);
    }

    // Finish the connection
    PQfinish(conn);

    return 0;
}