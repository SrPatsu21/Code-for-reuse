#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include<time.h>

#define NUMBER_OF_INSERT 1000000

int main(int argc, char *argv[])
{
    char movieTitles[100][30] = {
        "The Matrix", "Inception", "Gladiator", "Casablanca", "Avatar",
        "Joker", "Memento", "Inception", "Django", "Titanic",
        "Jaws", "Rocky", "E.T.", "Jumanji", "Shrek",
        "Grease", "Alien", "Rambo", "Zootopia", "Frozen",
        "Tenet", "Tango", "Rush", "Heat", "Hunger",
        "Maleficent", "Hercules", "Scream", "Aladdin", "Lucy",
        "Venom", "Godzilla", "Tenet", "Willy Wonka", "Mulan",
        "Coco", "Soul", "The Maze", "The Road", "Maverick",
        "Shazam", "Moana", "Matrix", "Dune", "Beetlejuice",
        "Shutter Island", "Lion King", "Moulin Rouge", "Bohemian", "Trolls",
        "Dawn", "Doom", "Midsommar", "Us", "Jigsaw",
        "Whiplash", "Parasite", "Blade Runner", "Snowpiercer", "Logan",
        "Ex Machina", "Arrival", "Selma", "Rush Hour", "Pride",
        "Raya", "Trolls", "Prisoners", "Spectre", "Uncut Gems",
        "The Hunt", "Casino Royale", "Kingsman", "Gravity", "A Quiet Place"
    };


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
    int random_value = 1;

    for (size_t i = 0; i < NUMBER_OF_INSERT; i++)
    {
        random_value = rand();

        // Execute a query
        char query [1024] = "INSERT INTO films (title, duration, score, release_date) values (";
        char helper[1] = "\0";
        //* title
        char title[33] = "'";
        strcat(title, movieTitles[random_value%100]);
        strcat(title, "',");
        strcat(query, title);
        //* duration
        char duration [11]= "'0";
        helper[0] = '0'+ random_value%4;
        strcat(duration, helper);
        strcat(duration, ":");
        //rand to change
        random_value = rand();
        helper[0] = '0'+ random_value%6;
        strcat(duration, helper);
        //rand to change
        random_value = rand();
        helper[0] = '0'+ random_value%10;
        strcat(duration, helper);
        strcat(duration, ":00',");
        strcat(query, duration);
        //* score
        helper[0] = '\0';
        helper[1] = '\0';
        char score [8] = "'";
        //rand to change
        random_value = rand();
        helper[0] = '0'+ random_value%5;
        strcat(score, helper);
        //! dont know why
        strcat(score, ",");
        strcat(query, score);

        //* release_date
        helper[0] = '\0';
        helper[1] = '\0';
        char release_date [50] = "TO_DATE('";
        helper[0] = (char) '0'+ random_value%3;
        strcat(release_date, helper);
        helper[0] = '0'+ random_value%10;
        strcat(release_date, helper);
        strcat(release_date, "/");
        helper[0] = '0';
        strcat(release_date, helper);
        helper[0] = '0'+ random_value%10;
        strcat(release_date, helper);
        strcat(release_date, "/20");
        helper[0] = '0'+ random_value%4;
        strcat(release_date, helper);
        helper[0] = '0'+ random_value%10;
        strcat(release_date, helper);
        strcat(release_date, "', 'DD/MM/YYYY')");

        strcat(query, release_date);
        //* end
        char *closequery = ");";
        strcat(query, closequery);
        //print query
        printf("%s", query);

        // Submit the query and retrieve the result
        PGresult *res = PQexec(conn, query);

        // Check the status of the query result
        ExecStatusType resStatus = PQresultStatus(res);

        // Convert the status to a string and print it
        printf("\t \t Query Status: %s\n", PQresStatus(resStatus));
        // We have successfully executed the query
        PQclear(res);
    }

    // Finish the connection
    PQfinish(conn);

    return 0;
}