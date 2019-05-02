#define CHAR 20
#define NST 50

struct person {

    char name[CHAR];
    double grade[NST];
    float average;
    float min;
    float max;
};

struct assignment{
    float average;
    float min;
    float max;
};

int extractgrades(struct person reader[]);

char assaignletter(double points);

double avg(struct person reader[]);

double min( struct person reader[]);

double max( struct person reader[]);

double stddev( struct person reader[]);

double total( struct person reader[]);


